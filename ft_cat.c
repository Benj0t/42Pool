#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_putendl(char *str)
{
    int i;
    i=-1;
    while (str[++i])
        ft_putchar(str[i]);
    ft_putchar('\n');
}

void ft_display_file(char *str)
{
    int fd;
    int check;
    char buffer[4097];

    fd = open(str, O_RDONLY);
    check = read(fd, buffer, 4096);
    ( fd != -1 ? write(1,buffer,check) : write(2, "Cannot read file.\n",18));
    close(fd);
}

int main(int argc, char **argv)
{
    int i;
    
    i = 0;
    if (argc == 1)
    { 
        write(2, "File name is missing.\n",22 );
        return(0);
    }
    while (++i < argc)
        ft_display_file(argv[i]);
    return(0);
}