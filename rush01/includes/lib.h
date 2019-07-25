#ifndef LIST_H
# define LIST_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str);
int ft_backtrack(char **grille,char **list, int x, int y);
int ft_check(char **list, char **grille, int x, int y, char c);
int ft_check_coldown(char **list, char **grille, int x, int y, char c);
int ft_check_column(char **grille, int x, int y, char c);
int ft_check_colup(char **list, char **grille, int x, int y, char c);
int ft_check_line(char **grille, int x, int y, char c);
int ft_check_rowleft(char **list, char **grille, int x, int y, char c);
int ft_check_rowright(char **list, char **grille, int x, int y, char c);
int ft_count_letters(char *str);
void ft_fill(char *tab, char *str, int n);
char **ft_init(char **tab, int c);
void ft_skip_tab(char **grille, int *x, int *y);
void ft_putchar(char c);
void ft_putendl(char *str);
void ft_putnbr(int n);
int ft_parse(char **tab);
void ft_putstr(char *str);
void ft_skip_whitespaces(char *str, int *j);
char **ft_split_whitespaces(char *str);
int ft_strlen(char *str);
int ft_tablen(char **tab);

#endif
