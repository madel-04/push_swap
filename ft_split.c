/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:06:15 by marvin            #+#    #+#             */
/*   Updated: 2024/11/12 11:06:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char sep)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == sep && *str)
			++str;
		while (*str != sep && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char sep)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == sep)
		++cursor;
	while ((str[cursor + len] != sep) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != sep) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char sep)
{
	int		words_number;
	char	**v_str;
	int		i;

	i = 0;
	words_number = count_words(str, sep);
	if (!words_number)
		exit(1);
	v_str = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (NULL == v_str)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			v_str[i] = malloc(sizeof(char));
			if (NULL == v_str[i])
				return (NULL);
			v_str[i++][0] = '\0';
			continue ;
		}
		v_str[i++] = get_next_word(str, sep);
	}
	v_str[i] = NULL;
	return (v_str);
}
