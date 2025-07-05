/*
** EPITECH PROJECT, 2023
** myprintf
** File description:
** Header of my_printf
*/

#pragma once
#include <stdarg.h>

int my_put_scientific_low(double nb);
int my_put_scientific_up(double nb);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(long long int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int verif_flag(char const *format, int i, int *count, va_list list);
int my_printf(char const *format, ...);
int my_putnbr_base(long long int nbr, char const *base);
int verif_flag2(char const *format, int i, int *count, va_list list);
int my_intlen(long long n);
int my_put_float(double nb);
int my_compute_power_rec(int nb, int p);
int percent_o(char const *format, int i, int *count, va_list list);
int percent_d(char const *format, int i, int *count, va_list list);
int percent_i(char const *format, int i, int *count, va_list list);
int percent_s(char const *format, int i, int *count, va_list list);
int simple_percent(char const *format, int i, int *count, va_list list);
int percent_c(char const *format, int i, int *count, va_list list);
int percent_x(char const *format, int i, int *count, va_list list);
int percent_uppercase_x(char const *format, int i, int *count, va_list list);
int percent_u(char const *format, int i, int *count, va_list list);
int percent_f(char const *format, int i, int *count, va_list list);
int percent_e(char const *format, int i, int *count, va_list list);
int percent_uppercase_e(char const *format, int i, int *count, va_list list);
int parcours_array(char const *format, int *i, int *count, va_list list);
int parcours_array2(int *j, int *i);
int long_percent_d(char const *format, int i, int *count, va_list list);
int long_percent_i(char const *format, int i, int *count, va_list list);
int format_percent_o(char const *format, int i, int *count, va_list list);
int format_percent_x(char const *format, int i, int *count, va_list list);
int format_percent_uppercase_x
(char const *format, int i, int *count, va_list list);
int format_percent_d(char const *format, int i, int *count, va_list list);
int format_percent_d2(char const *format, int i, int *count, va_list list);
int format_percent_d3(char const *format, int i, int *count, va_list list);
int my_putnbr_base_p(unsigned long long int nbr, char const *base);
int percent_p(char const *format, int i, int *count, va_list list);
int percent_p_adresse(void *nb);