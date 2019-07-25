#include <stdlib.h>

void	remplissage(char *str, char **tab_end, int *i, int j)
{
	int k;

	k = 0;
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t')
		(*i)++;
	if (str[*i] == '\0')
		return ;
	while (!(str[*i] == ' ' || str[*i] == '\n'
				|| str[*i] == '\t' || str[*i] == '\0'))
	{
		tab_end[j][k] = str[*i];
		(*i)++;
		k++;
	}
	tab_end[j][k] = '\0';
	if (str[*i] != '\0')
		remplissage(str, tab_end, i, j + 1);
}

void	word_lenght(char *str, int *i, int *tab_words, int j)
{
	int	len_word;

	len_word = 0;
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t')
		(*i)++;
	if (str[*i] == '\0')
		return ;
	while (!(str[*i] == ' ' || str[*i] == '\n'
				|| str[*i] == '\t' || str[*i] == '\0'))
	{
		len_word++;
		(*i)++;
	}
	tab_words[j] = len_word;
	if (str[*i] != '\0')
		word_lenght(str, i, tab_words, j + 1);
}

void	number_words(char *str, int *word_num, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t')
		(*i)++;
	if (str[*i] == '\0')
		return ;
	while (!(str[*i] == ' ' || str[*i] == '\n'
				|| str[*i] == '\t' || str[*i] == '\0'))
		(*i)++;
	*word_num = *word_num + 1;
	if (str[*i] != '\0')
		number_words(str, word_num, i);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab_end;
	int		word_num;
	int		*tab_words;
	int		i;

	word_num = 0;
	i = 0;
	number_words(str, &word_num, &i);
	if (!(tab_words = (int*)malloc(sizeof(int) * (word_num))))
		return (NULL);
	i = 0;
	word_lenght(str, &i, tab_words, 0);
	if (!(tab_end = (char**)malloc(sizeof(char*) * (word_num + 1))))
		return (NULL);
	i = 0;
	while (i < word_num)
	{
		if (!(tab_end[i] = (char*)malloc(sizeof(char) * (tab_words[i] + 1))))
			return (NULL);
		i++;
	}
	i = 0;
	remplissage(str, tab_end, &i, 0);
	tab_end[word_num] = 0;
	return (tab_end);
