#include "./includes/lib.h"
/*
  colup
  1 2 3 4 
1 0 0 0 0 1 rowright
2 0 0 0 0 2
3 0 0 0 0 3
4 0 0 0 0 4
  1 2 3 4

    1     2       3      4      5       6           7       8       9       10      11          12      13      14          15      16
"col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right"
 
*/
int ft_check_colup(char **list, char **grille, int x, int y, char c)
{
    int x2;
    int count;
    char tmp;

    count = 0;
    x2 = -1;
    tmp = '0';
    grille[x][y] = c;
    while (grille[++x2])
    {
        if (grille[x2][y] > tmp)
        {
            tmp = grille[x2][y];
            count++;
        }
    }
    grille[x][y] = '0';
    return(count <= ft_atoi(list[x]) ? 1 : -1);
}

int ft_check_coldown(char **list, char **grille, int x, int y, char c)
{
    int x2;
    int count;
    char tmp;

    count = 0;
    x2 = 4;
    tmp = '0';
    grille[x][y] = c;
    while (grille[--x2])
    {
        if (grille[x2][y] > tmp)
        {
            tmp = grille[x2][y];
            count++;
        }
    }
    grille[x][y] = '0';
    return(count <= ft_atoi(list[x + 4]) ? 1 : -1);
}

int ft_check_rowleft(char **list, char **grille, int x, int y, char c)
{
    int y2;
    int count;
    char tmp;

    count = 0;
    y2 = -1;
    tmp = '0';
    grille[x][y] = c;
    while (grille[x][++y2])
    {
        if (grille[x][y2] > tmp)
        {
            tmp = grille[x][y2];
            count++;
        }
    }
    grille[x][y] = '0';
    return(count <= ft_atoi(list[x + 8]) ? 1 : -1);
}

int ft_check_rowright(char **list, char **grille, int x, int y, char c)
{
    int y2;
    int count;
    char tmp;

    count = 0;
    y2 = 4;
    tmp = '0';
    grille[x][y] = c;
    while (grille[x][--y2])
    {
        if (grille[x][y2] > tmp)
        {
            tmp = grille[x][y2];
            count++;
        }
    }
    grille[x][y] = '0';
    return(count <= ft_atoi(list[x + 12]) ? 1 : -1);
}