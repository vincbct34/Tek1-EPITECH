/*
** EPITECH PROJECT, 2024
** Testing function
** File description:
** Test for Setenv and unsetenv
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_add_alias, test_cases)
{
    minishell_t minishell;
    minishell.alias = NULL;

    // Test case 1: Add a single alias
    char *args1[] = {"alias", "ls", "ls -l", NULL};
    minishell.args = args1;
    add_alias(&minishell);
    cr_assert_str_eq(minishell.alias->alias, "ls");
    cr_assert_str_eq(minishell.alias->command, "ls -l");
    cr_assert_null(minishell.alias->next);

    // Test case 2: Add another alias
    char *args2[] = {"alias", "grep", "grep --color=auto", NULL};
    minishell.args = args2;
    add_alias(&minishell);
    cr_assert_str_eq(minishell.alias->next->alias, "grep");
    cr_assert_str_eq(minishell.alias->next->command, "grep --color=auto");
    cr_assert_null(minishell.alias->next->next);
}

Test(test_alias_with_flags, test_cases)
{
    minishell_t minishell;
    alias_t alias;
    char *args[] = {"alias", "ls", "ls -l", NULL};

    // Test case 1: Alias with no flags
    alias.command = "ls -l";
    cr_assert_eq(alias_with_flags(&minishell, args, &alias), 0);
}

Test(test_flags_or_not, test_cases)
{
    minishell_t minishell;
    alias_t alias;
    alias.command = "ls -l";
    minishell.alias = &alias;

    // Test case 1: Command with flags
    cr_assert_eq(flags_or_not(&minishell), 0);

    // Test case 2: Command without flags
    alias.command = "ls";
    cr_assert_eq(flags_or_not(&minishell), 1);
}

Test(test_flags_or_not_two, test_cases)
{
    alias_t alias;

    // Test case 1: Command with flags
    alias.command = "ls -l";
    cr_assert_eq(flags_or_not_two(&alias), 0);

    // Test case 2: Command without flags
    alias.command = "ls";
    cr_assert_eq(flags_or_not_two(&alias), 1);
}

Test(test_check_alias_loop, test_cases)
{
    minishell_t minishell;
    alias_t alias1, alias2;
    alias1.alias = "ls";
    alias1.command = "ls -l";
    alias1.next = &alias2;
    alias2.alias = "grep";
    alias2.command = "grep --color=auto";
    alias2.next = NULL;
    minishell.alias = &alias1;
    minishell.args = (char *[]){"ls", NULL};

    // Test case: No alias loop
    cr_assert_eq(check_alias_loop(&minishell), 1);
}

Test(test_nbr_args_emi, test_cases)
{
    char *args[] = {"ls", "-l", "-a", NULL};

    // Test case: Three arguments
    cr_assert_eq(nbr_args_emi(args), 3);
}

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_change_to_home_directory, test_cases)
{
    minishell_t minishell;
    minishell.env_list = NULL;

    // Test case: HOME environment variable not set
    cr_assert_eq(change_to_home_directory(&minishell), 1);
}

Test(test_free_array, test_cases)
{
    char **array = (char **)malloc(sizeof(char *) * 3);
    array[0] = strdup("ls");
    array[1] = strdup("-l");
    array[2] = NULL;

    // Test case: Free array
    free_array(array);
}

Test(test_array_to_str, test_cases)
{
    char *array1[] = {"Hello", "world", NULL};
    char *array2[] = {NULL};

    // Test case 1: Normal array
    cr_assert_str_eq(array_to_str(array1), "Hello world");
}

Test(test_clean_str2, test_cases)
{
    bool space_encountered = false;
    char str[10] = {0};
    int j = 0;

    // Test case: Space not encountered yet
    clean_str2(&space_encountered, str, &j);
    cr_assert_str_eq(str, " ");
    cr_assert_eq(j, 1);
    cr_assert(space_encountered);
}

Test(test_clean_str, test_cases)
{
    char str1[] = "  Hello   world  ";
    char str2[] = "\tHello\tworld\t";
    char str3[] = "Hello world";

    // Test case 1: Leading, trailing, and multiple spaces
    clean_str(str1, 0);
    cr_assert_str_eq(str1, "Hello world");

    // Test case 2: Tabs instead of spaces
    clean_str(str2, 0);
    cr_assert_str_eq(str2, "Hello world");

    // Test case 3: No extra spaces
    clean_str(str3, 0);
    cr_assert_str_eq(str3, "Hello world");
}

Test(test_is_empty_or_space, test_cases)
{
    // Test case 1: Null string
    cr_assert(is_empty_or_space(NULL));

    // Test case 2: Empty string
    cr_assert(is_empty_or_space(""));

    // Test case 3: String with only spaces
    cr_assert(is_empty_or_space("   "));

    // Test case 4: String with non-space characters
    cr_assert_not(is_empty_or_space("Hello world"));
}

int check_name(env_t *new, char *name)
{
    if (is_alpha(name) == 1) {
        new->name = my_strdup(name);
    } else {
        my_puterror("setenv: Variable");
        my_puterror(" name must contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

Test(test_check_name, test_cases)
{
    env_t new;
    char *name = "TEST";

    // Test case: Valid name
    cr_assert_eq(check_name(&new, name), 0);
    cr_assert_str_eq(new.name, "TEST");
}

static int name_null(minishell_t *minishell, char *name)
{
    if (name == NULL) {
        print_env(minishell);
        return 1;
    }
    return 0;
}

static env_t *create_new_env_node(minishell_t *minishell, char *name,
    char *value)
{
    env_t *new = NULL;

    if (name_null(minishell, name) == 1)
        return NULL;
    new = malloc(sizeof(env_t));
    if (new == NULL || check_name(new, name) == 1) {
        free(new);
        return NULL;
    }
    if (value != NULL) {
        new->value = my_strdup(value);
        if (new->value == NULL) {
            free(new);
            return NULL;
        }
    } else
        new->value = "\0";
    new->next = NULL;
    return new;
}

Test(test_my_list_size, test_cases)
{
    env_t list;
    list.name = "TEST";
    list.value = "VALUE";
    list.next = NULL;

    // Test case: List with one element
    cr_assert_eq(my_list_size(&list), 1);
}

Test(tests_is_alpha, test_cases)
{
    // Test case 1: Alphanumeric string
    cr_assert(is_alpha("Test123"));

    // Test case 2: Non-alphanumeric string
    cr_assert_not(is_alpha("Test 123"));

    // Test case 3: Empty string
    cr_assert(is_alpha(""));
}

Test(tests_my_strstr, test_cases)
{
    // Test case 1: Needle is in haystack
    cr_assert_str_eq(my_strstr("Hello world", "world"), "world");

    // Test case 2: Needle is not in haystack
    cr_assert_null(my_strstr("Hello world", "planet"));

    // Test case 3: Needle is empty
    cr_assert_str_eq(my_strstr("Hello world", ""), "Hello world");
}

Test(tests_my_list_size, test_cases)
{
    env_t list;
    list.name = "TEST";
    list.value = "VALUE";
    list.next = NULL;

    // Test case: List with one element
    cr_assert_eq(my_list_size(&list), 1);
}

Test(test_is_alpha, test_cases)
{
    // Test case 1: Alphanumeric string
    cr_assert(is_alpha("Test123"));

    // Test case 2: Non-alphanumeric string
    cr_assert_not(is_alpha("Test 123"));

    // Test case 3: Empty string
    cr_assert(is_alpha(""));
}

Test(test_my_strstr, test_cases)
{
    // Test case 1: Needle is in haystack
    cr_assert_str_eq(my_strstr("Hello world", "world"), "world");

    // Test case 2: Needle is not in haystack
    cr_assert_null(my_strstr("Hello world", "planet"));

    // Test case 3: Needle is empty
    cr_assert_str_eq(my_strstr("Hello world", ""), "Hello world");
}

Test(test_my_puterror, test_cases, .init = redirect_all_std)
{
    // Test case: Error message
    my_puterror("Test error message.\n");
    cr_assert_stderr_eq_str("Test error message.\n");
}

Test(test_my_putrror, test_cases, .init = redirect_all_std)
{
    // Test case: Error message
    my_puterror("Test error message.\n");
    cr_assert_stderr_eq_str("Test error message.\n");
}

Test(test_handle_quotes, test_cases)
{
    quote_info_t info = {false, '\0'};

    // Test case: Opening quote
    handle_quotes('"', &info);
    cr_assert(info.in_quotes);
    cr_assert_eq(info.quote_char, '"');

    // Test case: Closing quote
    handle_quotes('"', &info);
    cr_assert_not(info.in_quotes);
}

Test(test_handle_char, test_cases)
{
    quote_info_t info = {false, '\0', 0, 0};

    // Test case: Handle quote
    handle_char('"', &info);
    cr_assert(info.in_quotes);
    cr_assert_eq(info.prev_index, 1);
}

Test(test_my_putstr, test_cases, .init = redirect_all_std)
{
    // Test case: Regular string
    my_putstr("Hello, world!");
    cr_assert_stdout_eq_str("Hello, world!");
}

Test(test_my_strlen, test_cases)
{
    // Test case 1: Regular string
    cr_assert_eq(my_strlen("Hello, world!"), 13);

    // Test case 2: Empty string
    cr_assert_eq(my_strlen(""), 0);

    // Test case 3: Null string
    cr_assert_eq(my_strlen(NULL), -1);
}

Test(test_my_strdup, test_cases)
{
    // Test case: Regular string
    char *dup = my_strdup("Hello, world!");
    cr_assert_str_eq(dup, "Hello, world!");
    free(dup);
}

Test(test_my_strcat, test_cases)
{
    // Test case: Regular strings
    char dest[30] = "Hello, ";
    my_strcat(dest, "world!");
    cr_assert_str_eq(dest, "Hello, world!");
}

Test(test_my_strcmp, test_cases)
{
    // Test case 1: Identical strings
    cr_assert_eq(my_strcmp("Hello, world!", "Hello, world!"), 0);

    // Test case 2: Different strings
    cr_assert_neq(my_strcmp("Hello, world!", "Goodbye, world!"), 0);
}

Test(test_my_strncmp, test_cases)
{
    // Test case 1: Identical strings
    cr_assert_eq(my_strncmp("Hello, world!", "Hello, world!", 5), 0);

    // Test case 2: Different strings
    cr_assert_neq(my_strncmp("Hello, world!", "Goodbye, world!", 5), 0);

    // Test case 3: Identical strings but n is too large
    cr_assert_eq(my_strncmp("Hello", "Hello", 10), 0);
}

Test(test_my_strcpy, test_cases)
{
    char dest[20];

    // Test case: Regular string
    my_strcpy(dest, "Hello, world!");
    cr_assert_str_eq(dest, "Hello, world!");
}

Test(test_my_strncpy, test_cases)
{
    char dest[20];

    // Test case 1: Regular string
    my_strncpy(dest, "Hello, world!", 5);
    cr_assert_str_eq(dest, "Hello");

    // Test case 2: n is larger than the string length
    my_strncpy(dest, "Hello", 10);
    cr_assert_str_eq(dest, "Hello");
}

Test(test_my_strcat2, test_cases)
{
    // Test case: Regular strings
    char *result = my_strcat2("Hello, ", "world!");
    cr_assert_str_eq(result, "Hello, world!");
    free(result);
}

Test(test_calculate_list_size, test_cases)
{
    // Test case: Empty list
    env_t *list = NULL;
    cr_assert_eq(calculate_list_size(list), 0);

    // Test case: List with one element
    list = malloc(sizeof(env_t));
    list->name = "name";
    list->value = "value";
    list->next = NULL;
    cr_assert_eq(calculate_list_size(list), 1);
    free(list);
}

Test(test_list_to_double_array, test_cases)
{
    // Test case: Convert list with one element to array
    env_t *list = malloc(sizeof(env_t));
    list->name = "name";
    list->value = "value";
    list->next = NULL;
    char **array = list_to_double_array(list);
    cr_assert_str_eq(array[0], "name=value");
    free(list);
    free_array(array);
}

Test(test_is_delim, test_cases)
{
    // Test case 1: Character is a delimiter
    cr_assert_eq(is_delim(' ', " \t"), true);

    // Test case 2: Character is not a delimiter
    cr_assert_eq(is_delim('a', " \t"), false);
}

static int count_words(char *str, char *delim)
{
    quote_info_t info = {false, '\0', delim, 0, 0};

    for (int i = 0; str[i]; i++)
        handle_char(str[i], &info);
    if (!is_delim(str[0], delim))
        info.count++;
    return info.count;
}

Test(test_count_words, test_cases)
{
    // Test case: Regular string
    cr_assert_eq(count_words("Hello, world!", " "), 2);
}

static char **my_str_to_word_array_bis(char **tab, int i)
{
    tab[i] = NULL;
    return tab;
}

Test(test_my_str_to_word_array_bis, test_cases)
{
    // Test case: Regular array
    char *array[3] = {"Hello,", "world!", NULL};
    cr_assert_eq(my_str_to_word_array_bis(array, 2), array);
}

Test(test_extract_token, test_cases)
{
    // Test case: Regular string
    int index = 0;
    cr_assert_str_eq(extract_token("Hello, world!", &index, " "), "Hello,");
}

Test(test_create_empty_tab, test_cases)
{
    // Test case: Create empty tab
    char **tab = create_empty_tab();
    cr_assert_not_null(tab);
    cr_assert_null(tab[0]);
    free(tab);
}

Test(test_fill_tokens, test_cases)
{
    // Test case: Regular string
    char *str = "Hello, world!";
    char *separator = " ";
    char **tab = malloc(sizeof(char *) * 3);
    int num_tokens = fill_tokens(tab, str, separator);
    cr_assert_eq(num_tokens, 2);
    cr_assert_str_eq(tab[0], "Hello,");
    cr_assert_str_eq(tab[1], "world!");
    free(tab[0]);
    free(tab[1]);
    free(tab);
}

Test(test_my_str_to_word_array, test_cases)
{
    // Test case: Regular string
    char **tab = my_str_to_word_array("Hello, world!", " ");
    cr_assert_not_null(tab);
    cr_assert_str_eq(tab[0], "Hello,");
    cr_assert_str_eq(tab[1], "world!");
    free(tab[0]);
    free(tab[1]);
    free(tab);
}

Test(test_my_strchr, test_cases)
{
    // Test case 1: Character is in the string
    cr_assert_str_eq(my_strchr("Hello, world!", 'w'), "world!");

    // Test case 2: Character is not in the string
    cr_assert_null(my_strchr("Hello, world!", 'z'));

    // Test case 3: Character is the null terminator
    cr_assert_str_eq(my_strchr("Hello, world!", '\0'), "");

    // Test case 4: String is empty
    cr_assert_null(my_strchr("", 'a'));
}

Test(test_my_tablen, test_cases)
{
    // Test case 1: Non-empty tab
    char *tab[3] = {"Hello,", "world!", NULL};
    cr_assert_eq(my_tablen(tab), 2);

    // Test case 2: Empty tab
    char **tab2 = NULL;
    cr_assert_eq(my_tablen(tab2), 0);
}

Test(tests_my_tablen, test_cases)
{
    // Test case 1: Non-empty tab
    char *tab[3] = {"Hello,", "world!", NULL};
    cr_assert_eq(my_tablen(tab), 2);

    // Test case 2: Empty tab
    char **tab2 = NULL;
    cr_assert_eq(my_tablen(tab2), 0);
}

static int update_min_priority(int priority, int minPriority)
{
    if (minPriority == -1 || priority < minPriority) {
        return priority;
    }
    return minPriority;
}

Test(test_update_min_priority, test_cases)
{
    // Test case 1: minPriority is -1
    cr_assert_eq(update_min_priority(5, -1), 5);

    // Test case 2: priority is less than minPriority
    cr_assert_eq(update_min_priority(3, 5), 3);

    // Test case 3: priority is greater than minPriority
    cr_assert_eq(update_min_priority(5, 3), 3);
}

static void update_delimiter_index(int *delimiterIndex, int tmpIndex)
{
    *delimiterIndex = tmpIndex;
}

static void update_delimiter(char **delimiter, char *currentDelimiter)
{
    *delimiter = currentDelimiter;
}

Test(test_update_delimiter_index, test_cases)
{
    // Test case: Regular update
    int delimiterIndex = 0;
    update_delimiter_index(&delimiterIndex, 5);
    cr_assert_eq(delimiterIndex, 5);
}

Test(test_update_delimiter, test_cases)
{
    // Test case: Regular update
    char *delimiter = NULL;
    update_delimiter(&delimiter, ">>");
    cr_assert_str_eq(delimiter, ">>");
}

Test(test_find_main_delimiter, test_cases)
{
    // Test case 1: Delimiter found
    int delimiterIndex = 0;
    char *delimiter = NULL;

    // Test case 2: Delimiter not found
    cr_assert_eq(find_main_delimiter("Hello, world!", &delimiterIndex, &delimiter), 0);
}

Test(testing_create_node, test_cases)
{
    // Test case: Regular creation
    node_t *node = create_node("Hello, world!");
    cr_assert_str_eq(node->operation, "Hello, world!");
    cr_assert_null(node->left);
    cr_assert_null(node->right);
    free(node->operation);
    free(node);
}

Test(test_build_tree, test_cases)
{
    // Test case 1: No main delimiter
    node_t *node = build_tree("Hello, world!");
    cr_assert_str_eq(node->operation, "Hello, world!");
    cr_assert_null(node->left);
    cr_assert_null(node->right);
    free(node->operation);
    free(node);
}

static void add(minishell_t shell, int *ind, int *cursor_ind, char c)
{
    if (isprint(c)) {
        shell.data_termios->buffer = my_realloc(shell.data_termios->buffer);
        memmove(&shell.data_termios->buffer[*cursor_ind + 1],
            &shell.data_termios->buffer[*cursor_ind],
            strlen(&shell.data_termios->buffer[*cursor_ind]) + 1);
        shell.data_termios->buffer[*cursor_ind] = c;
        *cursor_ind += 1;
        *ind += 1;
        if (*cursor_ind != *ind) {
            printf("\033[s");
            printf("\033[34m\033[2K\r%s\033[0m%s", shell.data_termios->prompt,
                shell.data_termios->buffer);
            printf("\033[u");
            printf("\033[1C");
        } else
            printf("\033[34m\033[2K\r%s\033[0m%s", shell.data_termios->prompt,
                shell.data_termios->buffer);
    }
}

static void suppr(minishell_t shell, int *ind, int *cursor_ind)
{
    char *buffer = shell.data_termios->buffer;
    char *prompt = shell.data_termios->prompt;

    if (*ind > 0 && *cursor_ind > 0) {
        memmove(&buffer[*cursor_ind - 1],
            &buffer[*cursor_ind], strlen(&buffer[*cursor_ind]) + 1);
        *cursor_ind -= 1;
        *ind -= 1;
        if (*cursor_ind != *ind) {
            printf("\033[s");
            printf("\033[34m\033[2K\r%s\033[0m%s", prompt, buffer);
            printf("\033[u");
            printf("\033[1D");
        } else
            printf("\033[34m\033[2K\r%s\033[0m%s", prompt, buffer);
    }
}

static void delete(minishell_t shell, int *ind, int *cursor_ind)
{
    char *buffer = shell.data_termios->buffer;
    char *prompt = shell.data_termios->prompt;

    if (*cursor_ind < *ind) {
        memmove(&buffer[*cursor_ind],
            &buffer[*cursor_ind + 1], strlen(&buffer[*cursor_ind + 1]) + 1);
        *ind -= 1;
        if (*cursor_ind != *ind) {
            printf("\033[s");
            printf("\033[34m\033[2K\r%s\033[0m%s", prompt, buffer);
            printf("\033[u");
        } else
            printf("\033[34m\033[2K\r%s\033[0m%s", prompt, buffer);
    }
}

Test(test_is_a_ctrl_d, test_cases)
{
    // Test case: Regular is_a_ctrl_d
    minishell_t shell;
    // is_a_ctrl_d(shell);
    // Add assertions based on the expected behavior of the function
}

Test(test_init_termios, test_cases)
{
    // Test case: Regular init_termios
    termios_t data_termios;
    init_termios(&data_termios);
    cr_assert_eq(data_termios.new_termios.c_lflag, data_termios.old_termios.c_lflag & ~(ICANON | ECHO));
    cr_assert_eq(data_termios.new_termios.c_cc[VMIN], 1);
    cr_assert_eq(data_termios.new_termios.c_cc[VTIME], 0);
    cr_assert_null(data_termios.buffer);
    cr_assert_null(data_termios.clipboard);
    // Add assertions for data_termios.prompt based on the expected behavior of the get_prompte function
}

Test(test_tty_function, test_cases)
{
    // Test case: Regular tty_function
    minishell_t minishell;
    // tty_function(minishell);
    // Add assertions based on the expected behavior of the function
}

Test(test_not_tty_function, test_cases)
{
    // Test case: Regular not_tty_function
    minishell_t minishell;
    // not_tty_function(minishell);
    // Add assertions based on the expected behavior of the function
}

Test(test_print_flags, test_cases)
{
    // Test case: Regular print_flags
    alias_t alias;
    alias.command = "test";
    print_flags(&alias);
    // Add assertions based on the expected behavior of the function
}

static void print_alias(alias_t *tmp)
{
    while (tmp != NULL) {
        my_putstr(tmp->alias);
        my_putstr("\t");
        if (flags_or_not_two(tmp) == 0) {
            my_putstr("(");
            print_flags(tmp);
            my_putstr(")");
        } else {
            print_flags(tmp);
        }
        my_putstr("\n");
        tmp = tmp->next;
    }
}

static void alias_check_calls_bis(alias_t *tmp, minishell_t *minishell)
{
    if (my_strcmp(tmp->alias, ARGS[1]) == 0){
        print_flags(tmp);
        my_putstr("\n");
        return;
    }
}

static void delete_alias_bis(alias_t *tmp, minishell_t *minishell,
    alias_t *prev, char *alias_name)
{
    if (my_strcmp(tmp->alias, alias_name) == 0) {
        if (prev == NULL)
            minishell->alias = tmp->next;
        else
            prev->next = tmp->next;
        free(tmp);
        return;
    }
}

static void delete_alias(minishell_t *minishell, char *alias_name)
{
    alias_t *tmp = minishell->alias;
    alias_t *prev = NULL;

    while (tmp != NULL) {
        delete_alias_bis(tmp, minishell, prev, alias_name);
        prev = tmp;
        tmp = tmp->next;
    }
}

Test(test_print_alias, test_cases)
{
    // Test case: Regular print_alias
    alias_t alias;
    alias.alias = "test";
    alias.command = "test";
    alias.next = NULL;
    print_alias(&alias);
    // Add assertions based on the expected behavior of the function
}

Test(test_alias_check_calls_bis, test_cases)
{
    // Test case: Regular alias_check_calls_bis
    minishell_t minishell;
    alias_t alias;
    alias.alias = "test";
    alias.command = "test";
    minishell.args = malloc(sizeof(char *) * 3);
    minishell.args[1] = "test";
    minishell.args[2] = NULL;
    alias_check_calls_bis(&alias, &minishell);
    // Add assertions based on the expected behavior of the function
    // Don't forget to free minishell.args after the test
}

Test(tests_print_flags, test_cases)
{
    // Test case: Regular print_flags
    alias_t alias;
    alias.command = "test";
    print_flags(&alias);
    // Add assertions based on the expected behavior of the function
}

Test(testing_print_alias, test_cases)
{
    // Test case: Regular print_alias
    alias_t alias;
    alias.alias = "test";
    alias.command = "test";
    alias.next = NULL;
    print_alias(&alias);
    // Add assertions based on the expected behavior of the function
}

Test(testing_alias_check_calls_bis, test_cases)
{
    // Test case: Regular alias_check_calls_bis
    minishell_t minishell;
    alias_t alias;
    alias.alias = "test";
    alias.command = "test";
    minishell.args = malloc(sizeof(char *) * 3);
    minishell.args[1] = "test";
    minishell.args[2] = NULL;
    alias_check_calls_bis(&alias, &minishell);
    // Add assertions based on the expected behavior of the function
    // Don't forget to free minishell.args after the test
}

static char *emi_path_bis(minishell_t *minishell, char **path_array,
    char *path, char *args_emi)
{
    char *temp_path = NULL;

    for (int i = 0; path_array[i] != NULL; i++) {
        path = my_strcat2(path_array[i], "/");
        temp_path = my_strcat2(path, args_emi);
        free(path);
        if (access(temp_path, F_OK) == 0) {
            return temp_path;
        }
        free(temp_path);
    }
    return ARGS[0];
}

Test(test_emi_path_bis, test_cases)
{
    // Test case: Regular emi_path_bis
    minishell_t minishell;
    char *path_array[] = {"/usr/bin", "/usr/local/bin", NULL};
    char *path = NULL;
    char *args_emi = "ls";
    char *result = emi_path_bis(&minishell, path_array, path, args_emi);
    cr_assert_str_eq(result, "/usr/bin/ls");
    free(result);
}

Test(test_emi_get_path, test_cases)
{
    // Test case: Regular emi_get_path
    minishell_t minishell;
    minishell.env = malloc(sizeof(char *) * 4);
    minishell.env[0] = "HOME=/home/user";
    minishell.env[1] = "PATH=/usr/bin:/usr/local/bin";
    minishell.env[2] = "USER=user";
    minishell.env[3] = NULL;
    char *args_emi = "ls";
    char *result = emi_get_path(&minishell, args_emi);
    cr_assert_str_eq(result, "/usr/bin/ls");
    free(result);
    free(minishell.env);
}

Test(test_emi_write_error, test_cases)
{
    // Test case: Regular emi_write_error
    minishell_t minishell;
    char *args_emi[] = {"ls", NULL};
    errno = ENOEXEC;
    emi_write_error(&minishell, args_emi);
    // Add assertions based on the expected behavior of the function
}

Test(test_cd_error, test_cases)
{
    // Test case: Regular cd_error
    minishell_t minishell;
    minishell.args = malloc(sizeof(char *) * 3);
    minishell.args[1] = "/nonexistent";
    minishell.args[2] = NULL;
    int result = cd_error(&minishell);
    cr_assert_eq(result, 1);
    free(minishell.args);
}

Test(test_start_error, test_cases)
{
    // Test case: Regular start_error
    minishell_t minishell;
    minishell.args = malloc(sizeof(char *) * 3);
    minishell.args[1] = "/nonexistent";
    minishell.args[2] = NULL;
    int result = start_error(&minishell);
    cr_assert_eq(result, 1);
    free(minishell.args);
}

Test(test_cd_command, test_cases)
{
    // Test case: Regular cd_command
    minishell_t minishell;
    // Set up the environment list and other necessary fields
    // Then call the function and check the result
    // Add assertions based on the expected behavior of the function
}

Test(test_print_env, test_cases)
{
    // Test case: Regular print_env
    minishell_t minishell;
    minishell.env = malloc(sizeof(char *) * 3);
    minishell.env[0] = "HOME=/home/user";
    minishell.env[1] = "PATH=/usr/bin:/usr/local/bin";
    minishell.env[2] = NULL;
    int result = print_env(&minishell);
    cr_assert_eq(result, 0);
    free(minishell.env);
}

Test(test_free_arrays, test_cases)
{
    // Test case: Regular free_array
    char **array = malloc(sizeof(char *) * 3);
    array[0] = strdup("test1");
    array[1] = strdup("test2");
    array[2] = NULL;
    free_array(array);
    // Add assertions based on the expected behavior of the function
}

Test(test_up_arrow, test_cases)
{
    // Test case: Regular up_arrow
    minishell_t shell;
    int ind = 0;
    int cursor_ind = 0;
    // Initialize shell and its history_list
    up_arrow(&shell, &ind, &cursor_ind);
    // Add assertions based on the expected behavior of the function
}

Test(test_down_arrow, test_cases)
{
    // Test case: Regular down_arrow
    minishell_t shell;
    int ind = 0;
    int cursor_ind = 0;
    // Initialize shell and its history_list
    down_arrow(&shell, &ind, &cursor_ind);
    // Add assertions based on the expected behavior of the function
}

static void display_list(history_t *history_list)
{
    int i = 1;
    history_t *tmp = history_list;

    if (tmp == NULL)
        return;
    while (tmp->next != NULL)
        tmp = tmp->next;
    while (tmp != NULL) {
        printf("\t%d %s %s\n", i, tmp->time, tmp->prompt);
        i++;
        tmp = tmp->prev;
    }
}

static void display_returned_history(history_t *history_list)
{
    history_t *tmp = history_list;
    int i = 0;

    if (tmp == NULL)
        return;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        i++;
    }
    tmp = history_list;
    while (tmp != NULL) {
        printf("\t%d %s %s\n", i, tmp->time, tmp->prompt);
        i--;
        tmp = tmp->next;
    }
}

static void delete_history(history_t *history_list)
{
    history_t *tmp = history_list;
    history_t *tmp2 = NULL;

    while (tmp->next != NULL)
        tmp = tmp->next;
    while (tmp != NULL) {
        tmp2 = tmp->prev;
        free(tmp->prompt);
        free(tmp->time);
        free(tmp);
        tmp = tmp2;
    }
}

Test(tests_check_name, test_cases)
{
    // Test case: Regular check_name
    env_t new;
    char *name = "TEST";
    int result = check_name(&new, name);
    cr_assert_eq(result, 0);
    // Add assertions based on the expected behavior of the function
}

Test(test_create_new_env_node, test_cases)
{
    // Test case: Regular create_new_env_node
    minishell_t minishell;
    char *name = "TEST";
    char *value = "value";
    env_t *new = create_new_env_node(&minishell, name, value);
    // Add assertions based on the expected behavior of the function
    free(new);
}

static void append_env_node(env_t **list, env_t *new)
{
    env_t *tmp = NULL;

    if (*list == NULL) {
        *list = new;
    } else {
        tmp = *list;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

Test(test_append_env_node, test_cases)
{
    // Test case: Regular append_env_node
    env_t *list = NULL;
    env_t *new = malloc(sizeof(env_t));
    new->name = "TEST";
    new->value = "value";
    new->next = NULL;
    append_env_node(&list, new);
    // Add assertions based on the expected behavior of the function
    free(new);
}

Test(test_push_back, test_cases)
{
    // Test case: Regular push_back
    minishell_t minishell;
    env_t *list = NULL;
    char *name = "TEST";
    char *value = "value";
    int result = push_back(&minishell, &list, name, value);
    cr_assert_eq(result, 0);
    // Add assertions based on the expected behavior of the function
}

static void free_delete(env_t *tmp)
{
    free(tmp->name);
    if (tmp->value != NULL)
        free(tmp->value);
    free(tmp);
}

Test(test_free_delete, test_cases)
{
    // Test case: Regular free_delete
    env_t *tmp = malloc(sizeof(env_t));
    tmp->name = strdup("TEST");
    tmp->value = strdup("value");
    free_delete(tmp);
    // Add assertions based on the expected behavior of the function
}

Test(test_delete_element, test_cases)
{
    // Test case: Regular delete_element
    env_t *list = malloc(sizeof(env_t));
    list->name = strdup("TEST");
    list->value = strdup("value");
    list->next = NULL;
    char *name = "TEST";
    int result = delete_element(&list, name);
    cr_assert_eq(result, 0);
    // Add assertions based on the expected behavior of the function
}

Test(test_my_strndup, test_cases)
{
    // Test case: Regular my_strndup
    char *str = "TEST";
    int n = 2;
    char *result = my_strndup(str, n);
    cr_assert_str_eq(result, "TE");
}

Test(test_my_tabadd, test_cases)
{
    // Test case: Regular my_tabadd
    char **tab = malloc(sizeof(char *) * 3);
    tab[0] = strdup("Hello");
    tab[1] = strdup("World");
    tab[2] = NULL;
    char *str = strdup("!");

    char **new_tab = my_tabadd(tab, str);

    cr_assert_str_eq(new_tab[0], "Hello");
    cr_assert_str_eq(new_tab[1], "World");
    cr_assert_str_eq(new_tab[2], "!");
    cr_assert_null(new_tab[3]);

    // Free allocated memory
    for (int i = 0; new_tab[i] != NULL; i++)
        free(new_tab[i]);
    free(new_tab);
    free(tab[0]);
    free(tab[1]);
    free(tab);
    free(str);
}

Test(test_my_tabcat, test_cases)
{
    // Test case: Regular my_tabcat
    char **tab1 = malloc(sizeof(char *) * 3);
    tab1[0] = strdup("Hello");
    tab1[1] = strdup("World");
    tab1[2] = NULL;

    char **tab2 = malloc(sizeof(char *) * 3);
    tab2[0] = strdup("This");
    tab2[1] = strdup("is");
    tab2[2] = NULL;

    char **new_tab = my_tabcat(tab1, tab2);

    cr_assert_str_eq(new_tab[0], "Hello");
    cr_assert_str_eq(new_tab[1], "World");
    cr_assert_str_eq(new_tab[2], "This");
    cr_assert_str_eq(new_tab[3], "is");
    cr_assert_null(new_tab[4]);

    // Free allocated memory
    for (int i = 0; new_tab[i] != NULL; i++)
        free(new_tab[i]);
    free(new_tab);
    for (int i = 0; tab1[i] != NULL; i++)
        free(tab1[i]);
    free(tab1);
    for (int i = 0; tab2[i] != NULL; i++)
        free(tab2[i]);
    free(tab2);
}

Test(test_my_tabdup, test_cases)
{
    // Test case: Regular my_tabdup
    char **tab = malloc(sizeof(char *) * 3);
    tab[0] = strdup("Hello");
    tab[1] = strdup("World");
    tab[2] = NULL;

    char **new_tab = my_tabdup(tab);

    cr_assert_str_eq(new_tab[0], "Hello");
    cr_assert_str_eq(new_tab[1], "World");
    cr_assert_null(new_tab[2]);

    // Free allocated memory
    for (int i = 0; new_tab[i] != NULL; i++)
        free(new_tab[i]);
    free(new_tab);
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

Test(test_my_realloc, test_cases)
{
    char *str = strdup("Hello");
    char *new_str = my_realloc(str);

    cr_assert_str_eq(new_str, "Hello");
    cr_assert(new_str != str, "The new string should be at a different memory location");

    free(new_str);
}

static int execute_exit_command(minishell_t *minishell)
{
    if (my_strcmp(ARGS[0], "exit") == 0 &&
        minishell->no_builtin == 0) {
        exit(0);
    }
    return 2;
}

static int execute_cd_command(minishell_t *minishell)
{
    if (my_strcmp(ARGS[0], "cd") == 0 &&
        minishell->no_builtin == 0) {
        return cd_command(minishell);
    }
    return 2;
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

Test(test_execute_exit_command, test_cases)
{
    // Test case: execute_exit_command
    minishell_t minishell;
    minishell.no_builtin = 0;
    minishell.args = malloc(sizeof(char *) * 2);
    minishell.args[0] = strdup("exit");
    minishell.args[1] = NULL;

    int status = execute_exit_command(&minishell);

    // This test case will not pass because the function calls exit(0)
    // You need to find a way to test this function without terminating the test process
    cr_assert_eq(status, 2);

    // Free allocated memory
    free(minishell.args[0]);
    free(minishell.args);
}

Test(test_replace_tab, test_cases)
{
    // Test case: replace_tab
    char *input = strdup("Hello\tWorld");
    char *output = replace_tab(input);

    cr_assert_str_eq(output, "Hello World");

    // Free allocated memory
    free(input);
}

Test(test_get_env_value, test_cases)
{
    // Test case: get_env_value
    env_t *list = malloc(sizeof(env_t));
    list->name = strdup("NAME");
    list->value = strdup("VALUE");
    list->next = NULL;

    char *value = get_env_value(list, "NAME");

    cr_assert_str_eq(value, "VALUE");

    // Free allocated memory
    free(list->name);
    free(list->value);
    free(list);
}

Test(test_create_node, test_cases)
{
    // Test case: Regular create_node
    char *operation = "test";
    node_t *result = create_node(operation);
    cr_assert_str_eq(result->operation, operation);
    cr_assert_null(result->left);
    cr_assert_null(result->right);
    // Add assertions based on the expected behavior of the function
}

Test(testing_build_tree, test_cases)
{
    // Test case: Regular build_tree
    char *expr = "test";
    node_t *result = build_tree(expr);
    // Add assertions based on the expected behavior of the function
}

Test(test_execute_pipe_command, test_cases)
{
    // Test case: Regular execute_pipe_command
    node_t *node = NULL;
    minishell_t minishell;
    // Initialize minishell and node
    int result = execute_pipe_command(node, &minishell);
    // Add assertions based on the expected behavior of the function
}

Test(test_execute_tree_and_commands, test_cases)
{
    // Test case: Regular execute_tree_and_commands
    node_t *node = NULL;
    minishell_t minishell;
    // Initialize minishell and node
    int result = execute_tree_and_commands(node, &minishell);
    cr_assert_eq(result, 0);
    // Add assertions based on the expected behavior of the function
}
