/*
** EPITECH PROJECT, 2024
** B-PSU-200-MPL-2-1-42sh-vincent.bichat [WSL: Ubuntu-22.04]
** File description:
** my_get_input
*/

#include "../include/my.h"

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

static void analyse_event(minishell_t *shell, int *ind, int *cursor_ind)
{
    switch (getchar()) {
    case 'A':
        up_arrow(shell, ind, cursor_ind);
        break;
    case 'B':
        down_arrow(shell, ind, cursor_ind);
        break;
    case 'C':
        if (*cursor_ind < *ind) {
            *cursor_ind += 1;
            printf("\033[1C");
        }
        break;
    case 'D':
        if (*cursor_ind > 0) {
            *cursor_ind -= 1;
            printf("\033[1D");
        }
        break;
    }
}

void is_a_ctrl_d(minishell_t shell)
{
    tcsetattr(STDIN_FILENO, TCSANOW, &shell.data_termios->old_termios);
    printf("exit\n");
    exit(shell.return_value);
}

char *get_input_end(minishell_t shell, char c, int index)
{
    if (c == '\n') {
        shell.data_termios->buffer = my_realloc(shell.data_termios->buffer);
        shell.data_termios->buffer[index] = '\0';
    } else
        shell.data_termios->buffer[index] = '\0';
    tcsetattr(STDIN_FILENO, TCSANOW, &shell.data_termios->old_termios);
    printf("\n");
    return shell.data_termios->buffer;
}

void my_getinput3(minishell_t *shell, int *index, int *cursor_index, char c)
{
    if (c == 126)
        return delete(*shell, index, cursor_index);
    if (c == 0x0B)
        return cut_line(*shell, index, cursor_index);
    if (c == 0x19)
        return paste(*shell, index, cursor_index);
    if (c == 0x17)
        return copy(*shell, cursor_index);
    if (c == 127)
        suppr(*shell, index, cursor_index);
    else
        add(*shell, index, cursor_index, c);
}

void my_getinput2(minishell_t *shell, int *index, int *cursor_index, char c)
{
    if (c == '\033') {
        getchar();
        analyse_event(shell, index, cursor_index);
        return;
    }
    if (c == 4) {
        is_a_ctrl_d(*shell);
        return;
    }
    if (c == 1) {
        printf("\033[%ldG", strlen(shell->data_termios->prompt) + 1);
        *cursor_index = 0;
        return;
    }
    if (c == 5) {
        printf("\033[%ldG", strlen(shell->data_termios->prompt) + *index + 1);
        *cursor_index = *index;
        return;
    }
    return my_getinput3(shell, index, cursor_index, c);
}

char *my_get_input(minishell_t shell)
{
    int index = 0;
    int cursor_index = 0;
    char c = 0;

    c = init_terminal(&shell);
    while (c != '\n' && c != '\r') {
        my_getinput2(&shell, &index, &cursor_index, c);
        c = getchar();
    }
    return get_input_end(shell, c, index);
}
