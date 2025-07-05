/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include "usage.h"
#include "my.h"

int check_args(int ac, char **av)
{
    if (ac != 2) {
        print_bad_ac(ac, av);
        return (MY_EXIT_FAILURE);
    }
    if (check_options(av[1]) == MY_EXIT_SUCCESS)
        return (MY_EXIT_OPTION);
    return (MY_EXIT_SUCCESS);
}

int check_options(char *arg)
{
    if (my_strcmp(arg, "-h") == 0 || my_strcmp(arg, "--help") == 0) {
        print_help();
        return (MY_EXIT_SUCCESS);
    }
    return (MY_EXIT_FAILURE);
}

void print_help(void)
{
    my_putstr("Air traffic simulation panel.\n");
    my_putchar('\n');
    my_putstr("USAGE\n");
    my_putstr("  ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("  path_to_script    The path to the script file.\n");
    my_putchar('\n');
    my_putstr("OPTIONS\n");
    my_putstr("  -h | --help          print the usage and quit.\n");
    my_putchar('\n');
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  'L' key              enable/disable hitboxes and areas.\n");
    my_putstr("  'S' key              enable/disable sprites.\n");
}

void print_bad_ac(int ac, char **av)
{
    my_puterr(av[0]);
    my_puterr(": bad arguments: ");
    my_puterr(int_to_str(ac - 1));
    my_puterr(" given but 1 is required\n");
    my_puterr("retry with -h\n");
}
