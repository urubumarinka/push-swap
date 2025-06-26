/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:39:52 by maborges          #+#    #+#             */
/*   Updated: 2025/06/26 20:39:38 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	words_counter(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	inside_word = false;
	while (*s)
	{
		if (*s != c && !inside_word)
		{
			inside_word = true;
			count++;
		}
		else if (*s == c)
			inside_word = false;
		s++;
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	int		i;
	int		len;
	char	*next_word;

	i = 0;
	len = 0;
	while (s[*cursor] == c)
		(*cursor)++;
	while (s[*cursor + len] && s[*cursor + len] != c)
		len++;
	next_word = malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	while (len--)
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *s, char c)
{
	int		i;
	int		cursor;
	int		words_count;
	char	**array;

	i = -1;
	cursor = 0;
	words_count = words_counter(s, c);
	if (!words_count)
		return (NULL);
	array = malloc(sizeof(char *) * (words_count + 1));
	if (!array)
		return (NULL);
	while (++i < words_count)
	{
		array[i] = get_next_word(s, c, &cursor);
		if (!array[i])
		{
			while (i > 0)
				free(array[--i]);
			free(array);
			return (NULL);
		}
	}
	return (array[i] = NULL, array);
}
