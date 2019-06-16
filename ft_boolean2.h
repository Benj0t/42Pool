#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
#include <unistd.h>

typedef int t_bool;
#define EVEN(x) !(x%2)
#define TRUE 1
#define FALSE 0
#define EVEN_MSG "\033[38;2;255;0;0mCoucou les amis, c'est pair\033[0m"
#define ODD_MSG "\033[38;2;1;255;0bmnul, sale, deux\033[0m"
#define SUCCESS  0
#endif