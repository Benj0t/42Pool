#include "./includes/lib.h"

int ft_check_line(char **grille, int x, int y, char c)
{
    while (grille[x][y])
    {
        if (grille[x][y++] == c)
            return(-1);
    }
    return(1);
}

int ft_check_column(char **grille, int x, int y, char c)
{
    while (grille[x])
    {
        if (grille[x++][y] == c)
            return(-1);
    }
    return(1);
}


int ft_check(char **list, char **grille, int x, int y, char c)
{
    if (ft_check_column(grille,0,y,c) < 0 || ft_check_line(grille,x,0,c) < 0 )
    {
        return(-1);
    }
    if (ft_check_colup(list,grille,x,y,c) < 0 || ft_check_coldown(list,grille,x,y,c) < 0)
    {
        if (x == 2 && y == 0)
        return(-1);
    }
    if (ft_check_rowleft(list,grille,x,y,c) < 0 || ft_check_rowright(list,grille,x,y,c) < 0)
    {        
        return(-1);   
    }
    return(1);
}

void ft_skip_tab(char **grille, int *x, int *y)
{
    while (grille[*x][*y] != '0')
    {
        *y = *y + 1;
        if (*y == 4)
        {
            *y = 0;
            *x = *x + 1;
            if (*x == 4)
                return;
        }        
    }
}

int ft_backtrack(char **grille,char **list, int x, int y)
{
    char c;

    c = '0';
    while(++c <= '4')
    {
        ft_skip_tab(grille,&x,&y);
        if (x == 4)
            return(1);
        if (ft_check(list,grille,x,y,c) < 0)
        {
            if (c == '4')
                return(-1);
        }
        else
        {
            grille[x][y]=c;
            if (ft_backtrack(grille,list,0,0) < 0)
            {
                grille[x][y] = '0';
                if (c == '4')
                    return(-1);
            }
        }
    }
    return(1);
}