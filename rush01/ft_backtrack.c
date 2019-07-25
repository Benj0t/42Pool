#include "./includes/lib.h"

int ft_check_line(char **grille, int x, int y, char c)
{
    int y2;
    y2= -1;
    grille[x][y] = c;
    while (grille[x][++y2])
    {
        if (grille[x][y2] == c)
        {
            grille[x][y] = '0';
            return(-1);
        }
    }
    grille[x][y] = '0';
    return(1);
}

int ft_check_column(char **grille, int x, int y, char c)
{
    int x2;
    x2= -1;
    grille[x][y] = c;
    while (grille[++x2][y])
    {
        if (grille[x2][y] == c)
        {
            grille[x][y] = '0';
            return(-1);
        }
    }
    grille[x][y] = '0';
    return(1);
}


int ft_check(char **list, char **grille, int x, int y, char c)
{
    if (ft_check_column(grille,x,y,c) < 0 || ft_check_line(grille,x,y,c) < 0 )
        return(-1);
    if (ft_check_colup(list,grille,x,y,c) < 0 || ft_check_coldown(list,grille,x,y,c) < 0)
        return(-1);
    if (ft_check_rowleft(list,grille,x,y,c) < 0 || ft_check_rowright(list,grille,x,y,c) < 0)
        return(-1);
    return(1);
}

int ft_backtrack(char **grille,char **list, int x, int y)
{
    return(0);
}