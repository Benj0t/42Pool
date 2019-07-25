#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
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
void ft_display_file(char *file)
{
    int fd;
    int check;
    char buffer[4097];

    fd = open(file, O_RDONLY);
    check = read(fd, buffer, 4096);
    write(1,buffer,check);
    close(fd);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        write(2, "File name is missing.\n",22 );
    if (argc > 2)
        write(2, "Too many arguments.\n",20 ); 
    if (argc == 2)
        ft_display_file(argv[1]);
    return(0);
} 