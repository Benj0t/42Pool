/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 05:21:25 by anonymous         #+#    #+#             */
/*   Updated: 2020/04/21 05:44:34 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char *string;
	int i;

	i = 0;
	if (!(string = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i <= len)
	{
		string[i] = s[start + i];
		i++;
	}
	return (string);
}

int		main(void)
{
	printf("%s\n", ft_substr("bon", 0, 7));
	return (0);
}