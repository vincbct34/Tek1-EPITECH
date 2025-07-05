/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** main.c
*/

#include "robot.h"

void reverse_magic(all_t *all)
{
    all->header->magic = ((all->header->magic >> 24) & 0xff) |
                    ((all->header->magic << 8) & 0xff0000) |
                    ((all->header->magic >> 8) & 0xff00) |
                    ((all->header->magic << 24) & 0xff000000);
    all->header->prog_size = ((all->header->prog_size >> 24) & 0xff) |
                    ((all->header->prog_size << 8) & 0xff0000) |
                    ((all->header->prog_size >> 8) & 0xff00) |
                    ((all->header->prog_size << 24) & 0xff000000);
}

int write_cor_header(const char *filename, const header_t *header)
{
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    write(fd, header, sizeof(header_t));
    close(fd);
    return 0;
}

int main_bis(all_t all, char ***array3d, char *str)
{
    char *name = my_get_file_name(str);

    name = realloc(name, my_strlen(name) + 5);
    name = my_strcat(name, ".cor");
    all.header->prog_size = count_bytes_all(array3d);
    reverse_magic(&all);
    write_cor_header(name, all.header);
    return 0;
}

int main(int ac, char **av)
{
    all_t all;
    char ***array3d;
    char **array2;
    char *buffer;
    char **array;

    if (ac != 2)
        return 84;
    buffer = read_file(av[1]);
    array = my_str_to_line_array(buffer);
    if (handling_parsing_error(array, &all) == 84)
        return 84;
    array2 = copy_array(array);
    remove_label_lines(array2, count_line(buffer));
    array3d = create_3d_array(array2);
    remove_trailing_commas(array3d);
    if (compare_output_with_op_tab(array3d, op_tab) == 84)
        return 84;
    main_bis(all, array3d, av[1]);
    return 0;
}
