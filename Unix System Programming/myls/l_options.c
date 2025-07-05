/*
** EPITECH PROJECT, 2023
** l_options.c
** File description:
** The content of the flag -l of the my_ls command
*/

#include "includes/my.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <linux/stat.h>
#include <linux/limits.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <grp.h>
#include <time.h>

static void name_fct(const char *path)
{
    int len = my_strlen(path);
    int i = len - 1;

    if (my_strrchr(path, '/') != NULL) {
        for (; path[i] != '/'; i--);
        for (i = i + 1; path[i] != '\0'; i++)
            my_putchar(path[i]);
    } else {
        for (; path[i] != '\0'; i--);
        for (i = i + 1; path[i] != '\0'; i++)
            my_putchar(path[i]);
    }
}

static int check_may2(char *str, int i, char *tofind, int lentofind)
{
    int y;

    for (y = 0; y < lentofind; y++) {
        if (str[i + y] != tofind[y])
            break;
    }
    return y;
}

static int check_may(char *str, char *tofind)
{
    int lenstr = my_strlen(str);
    int lentofind = my_strlen(tofind);
    int y;

    for (int i = 0; i <= (lenstr - lentofind); i++) {
        y = check_may2(str, i, tofind, lentofind);
        if (y == lentofind)
            return 1;
    }
    return 0;
}

void get_time(struct stat *file_stat)
{
    time_t base_file_time = file_stat->st_mtime;
    char *file_time = ctime(&base_file_time);
    int start = 8;

    my_strlowcase(file_time);
    my_putchar(file_time[4]);
    my_putchar(file_time[5]);
    my_putchar(file_time[6]);
    if (check_may(file_time, "may") != 0)
        my_putchar(' ');
    else
        my_putstr(". ");
    for (int i = start; i < 16; i++)
        my_putchar(file_time[i]);
    my_putchar(' ');
}

void l_options(const char *path)
{
    struct stat file_stat;

    stat(path, &file_stat);
    my_putchar(' ');
    my_put_nbr(file_stat.st_nlink);
    my_putchar(' ');
    if (file_stat.st_uid == 0)
        my_putstr("root");
    else
        my_put_nbr((long)file_stat.st_uid);
    my_putchar(' ');
    if (file_stat.st_gid == 0)
        my_putstr("root");
    else
        my_put_nbr((long)file_stat.st_gid);
    my_putchar(' ');
    my_put_nbr(file_stat.st_size);
    my_putchar(' ');
    get_time(&file_stat);
    name_fct(path);
}

void perm_l(const char *path)
{
    struct stat file_stat;

    stat(path, &file_stat);
    if (S_ISREG(file_stat.st_mode))
        my_printf("-");
    if (S_ISDIR(file_stat.st_mode))
        my_printf("d");
    if (S_ISLNK(file_stat.st_mode))
        my_printf("l");
    my_printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
    my_printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
    my_printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
    my_printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
    my_printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
    my_printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
    my_printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
    my_printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
    my_printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
    l_options(path);
    my_printf("\n");
}

void cmp_dir(const char *path, const char *entry_name, char *path2)
{
    if (entry_name[0] != '.') {
        if (my_strcmp(path, ".") != 0) {
            my_strcpy(path2, path);
            my_strcat(path2, entry_name);
        } else
            my_strcpy(path2, entry_name);
        perm_l(path2);
    }
}

void l_call(const char *path)
{
    DIR *dir;
    struct dirent *entry;
    char *path2 = malloc(sizeof(char) * PATH_MAX);

    if (my_strcmp(path, ".") != 0)
        dir = opendir(path);
    else
        dir = opendir(".");
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir))
        cmp_dir(path, entry->d_name, path2);
}
