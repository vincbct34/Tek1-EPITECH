/*
** EPITECH PROJECT, 2024
** B-PSU-200-MPL-2-1-42sh-vincent.bichat [WSL: Ubuntu-22.04]
** File description:
** termios
*/

#include "../include/my.h"

void init_termios(termios_t *data_termios)
{
    memset(data_termios, 0, sizeof(termios_t));
    tcgetattr(STDIN_FILENO, &data_termios->old_termios);
    data_termios->new_termios = data_termios->old_termios;
    data_termios->new_termios.c_lflag &= ~(ICANON | ECHO);
    data_termios->new_termios.c_cc[VMIN] = 1;
    data_termios->new_termios.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &data_termios->new_termios);
    data_termios->prompt = get_prompte();
    data_termios->buffer = NULL;
    data_termios->clipboard = NULL;
}

char init_terminal(minishell_t *shell)
{
    shell->data_termios->prompt = get_prompte();
    shell->data_termios->buffer = NULL;
    printf("\033[34m%s\033[0m", shell->data_termios->prompt);
    init_termios(shell->data_termios);
    return getchar();
}
