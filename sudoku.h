/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 00:47:00 by marvin            #+#    #+#             */
/*   Updated: 2019/07/02 00:53:42 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

/*ft_toto
{
    static int i;

    i++;

    return ((int)i);
}*/

int ft_strlen(char *str);
void ft_fill(char **str, char **av);
int ft_check_line(char *str);
int ft_parse(char ***table, int ac, char **av);

#endif
