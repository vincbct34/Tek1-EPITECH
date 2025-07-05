/*
** EPITECH PROJECT, 2024
** B-PSU-200-MPL-2-1-minishell2-axel.pereto
** File description:
** build
*/

#include "../../include/my.h"

node_t *create_node(char *operation)
{
    node_t *newNode = malloc(sizeof(node_t));

    if (newNode == NULL)
        exit(1);
    newNode->operation = my_strdup(operation);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node_t *build_tree(char *expr)
{
    int delimiterIndex;
    char *delimiter;
    char *leftExpr;
    char *rightExpr;
    node_t *node;

    if (!find_main_delimiter(expr, &delimiterIndex, &delimiter)) {
        return create_node(expr);
    }
    leftExpr = my_strndup(expr, delimiterIndex);
    rightExpr = my_strdup(expr + delimiterIndex + my_strlen(delimiter));
    check_error_delim(delimiter, leftExpr, rightExpr);
    node = create_node(delimiter);
    node->left = build_tree(leftExpr);
    node->right = build_tree(rightExpr);
    free(leftExpr);
    free(rightExpr);
    return node;
}

static int execute_tree_bis(node_t *node, minishell_t *minishell)
{
    int left_status = 0;
    int right_status = 0;

    left_status = execute_tree_and_commands(node->left, minishell);
    if (left_status != 0)
        return left_status;
    right_status = execute_tree_and_commands(node->right, minishell);
    if (right_status != 0)
        return right_status;
    return 0;
}

static int execute_pipe_command(node_t *node, minishell_t *minishell)
{
    int status = execute_pipe(node, minishell);

    return status;
}

static int execute_redirection_command(node_t *node, minishell_t *minishell)
{
    char direction = (my_strcmp(node->operation, ">") == 0) ? '>' :
        (my_strcmp(node->operation, "<") == 0) ? '<' : 'a';
    int status = 0;

    if (direction == 'a') {
        clean_str(node->right->operation, 0);
        return execute_redirection_append(node, minishell);
    }
    status = execute_redirection(node, minishell, direction);
    return status;
}

static int execute_logical_command(node_t *node, minishell_t *minishell)
{
    int status = execute_tree_and_commands(node->left, minishell);

    if ((my_strcmp(node->operation, "&&") == 0 && status == 0) ||
        (my_strcmp(node->operation, "||") == 0 && status != 0)) {
        return execute_tree_and_commands(node->right, minishell);
    }
    return status;
}

static int execute_tree_args(node_t *node, minishell_t *minishell)
{
    if (my_strcmp(node->operation, "|") == 0) {
        return execute_pipe_command(node, minishell);
    }
    if (my_strcmp(node->operation, ">") == 0 ||
        my_strcmp(node->operation, "<") == 0 ||
        my_strcmp(node->operation, ">>") == 0) {
        return execute_redirection_command(node, minishell);
    }
    if (my_strcmp(node->operation, "&&") == 0 ||
        my_strcmp(node->operation, "||") == 0) {
        return execute_logical_command(node, minishell);
    }
    return 1;
}

int execute_tree_and_commands(node_t *node, minishell_t *minishell)
{
    if (node == NULL)
        return 0;
    if (execute_tree_args(node, minishell) == 0)
        return 0;
    if (node->left == NULL && node->right == NULL) {
        minishell->args = my_str_to_word_array(node->operation, " ");
        return verif_commands(minishell);
    }
    return execute_tree_bis(node, minishell);
}

int build_tree_to_array_and_execute(char **array, minishell_t *minishell)
{
    node_t *node;
    int status = 0;

    for (int i = 0; array[i] != NULL; i++) {
        node = build_tree(array[i]);
        status = execute_tree_and_commands(node, minishell);
    }
    return status;
}
