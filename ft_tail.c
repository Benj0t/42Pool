/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 00:45:35 by marvin            #+#    #+#             */
/*   Updated: 2019/07/25 00:45:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
    write(1,&c,1);
}

int ft_count_lines(char *str)
{
    int nb;
    int i;

    nb = 0;
    i=-1;
    while (str[++i])
    {
        if (str[i] == '\n')
            nb++;
    }
    return(nb);
}

int ft_open(char *filename, int *i)
{
    int fd;
    char buffer[4097];

    fd = open(filename, O_RDONLY);
    read(fd, buffer, 4096);
    while (buffer[*i])
        *i = *i + 1;
    return(fd < 0 ? -1 : 1);
}

int ft_fill(char *filename, char *str)
{
    int fd;
    int i;
    char buffer[4097];

    i = -1;
    fd = open(filename, O_RDONLY);
    read(fd, buffer, 4096);
    while (buffer[++i])
        str[i] = buffer [i];
    return(fd < 0 ? -1 : 1);
}

void ft_tail(char *str, int nb)
{
    int count;
    int i;

    i = -1;
    count = 0;
    while (str[++i] && (count <= nb-10))
    {
        if(str[i] == '\n')
            count++;
    }
    while (str[i])
        ft_putchar(str[i++]);
}

int main(int argc, char **argv)
{
    int nb;
    char *file;
    int cl;
    
    cl = 0;
    if (argc == 1)
        write(2, "File name is missing.\n",22 );
    if (argc > 2)
        write(2, "Too many arguments.\n",20 );
    if (argc == 2)
    {
        if (ft_open(argv[1], &cl) < 0)
        {
            write(2, "Cannot read file.\n",18);
            return(0);
        }
        if (!(file = (char*)malloc(sizeof(char) * (cl+1))))
            return(0);
        file[cl]= '\0';
        ft_fill(argv[1],file);
        nb = ft_count_lines(file);
        ft_tail(file, nb);
    }
    return(0);
}