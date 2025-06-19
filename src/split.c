/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:39:52 by maborges          #+#    #+#             */
/*   Updated: 2025/06/18 19:34:50 by maborges         ###   ########.fr       */
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

static char	*get_next_word(char *s, char c, int *cursor)
{
    int		i = 0;
    int		len = 0;
    char	*next_word;

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
    int		i = 0;
    int		cursor = 0;
    int		words_count = words_counter(s, c);
    char	**array;

    if (!words_count)
        exit(1);
    array = malloc(sizeof(char *) * (words_count + 1));
    if (!array)
        return (NULL);
    while (i < words_count)
{
    array[i] = get_next_word(s, c, &cursor);
    if (!array[i])
    {
        // Free previously allocated words
        while (i > 0)
            free(array[--i]);
        free(array);
        return (NULL);
    }
    i++;
}    array[i] = NULL;
    return (array);
}
