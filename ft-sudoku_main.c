int     main(int ac, char **av)
{
    int i;
    char    **table;

    i = 0;
    if (ac == 10)
    {
        if (ft_parse(&table, ac, av))
        {
            printf("Ici les moulineaux\n");
            return (0);
        }
        printf("valeur table = %p\n", table);
        while (table[++i])
            printf("%s\n", table[i]);
    }
    return (0);
}