/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:15:48 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:55:58 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	array_length(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c && str[i + 1] == c) || (str[i] != c && !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static char	*wordbyword(char const *str, char c)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	while (j < i)
	{
		new[j] = str[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

static char	**ft_array(char const *s, char c, char **array)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			new = wordbyword(s + i, c);
			array[j] = new;
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char			**array;

	array = NULL;
	if (!s || !*s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (array_length(s, c) + 1));
	if (!array)
		return (NULL);
	array = ft_array(s, c, array);
	return (array);
}
