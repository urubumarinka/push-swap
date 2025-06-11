/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:39:52 by maborges          #+#    #+#             */
/*   Updated: 2025/06/10 17:14:59 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	words_counter(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			s++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	int			i;
	int			len;
	static int	cursor = 0;
	char		*next_word;

	i = 0;
	len = 0;
	while (s[cursor] == c)
		cursor++;
	while ((s[cursor + len] != c) && s[cursor + len])
		len++;
	next_word = malloc(sizeof(char) * len + 1);
	if (!next_word)
		return (NULL);
	while (s[cursor] != c && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *s, char c)
{
	int		i;
	int		words_count;
	char	**array;

	i = 0;
	words_count = words_counter(s, c);
	if (!words_count)
		exit(1);
	array = malloc(sizeof(char *) * words_count + 2);
	if (!array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			array[i] = malloc(sizeof(char));
			if (!array[i])
				return (NULL);
			array[i++][0] = '\0';
			continue ;
		}
		array[i++] = get_next_word(s, c);
	}
	array[i] = NULL;
	return (array);
}
