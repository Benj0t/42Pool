#include "./includes/lib.h"

int main(int argc, char **argv)
{
    char **tab;
    char **grille;
    if (argc != 2)
    {
        ft_putstr("Error\n");
        return(0);
    }
    tab = ft_split_whitespaces(argv[1]);
    if (ft_parse(tab) < 0 || ft_tablen(tab) != 16)
    {
        ft_putstr("Error\n");
        return(0);
    }
    grille = ft_init(grille, 4);
    //ft_backtrack(tab);
    return(0);
}

/*
    int i=-1;
    while((++i) <= 3)
            printf("%s\n",grille[i]);
 */