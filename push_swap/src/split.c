/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:49:51 by jucheng           #+#    #+#             */
/*   Updated: 2023/11/16 10:44:12 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	in_substring;

	count = 0;
	while (*s)
	{
		in_substring = false;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (!in_substring)
			{
				count++;
				in_substring = true;
			}
			s++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	pos;
	char		*next_word;
	int			len;
	int			i;

	pos = 0;
	len = 0;
	i = 0;
	while (s[pos] == c)
		pos++;
	while ((s[pos + len] != c) && s[pos + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while (s[pos] != c && s[pos])
		next_word[i++] = s[pos++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *s, char c)
{
	int		words_count;
	char	**result;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		return (NULL);
	result = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result[i] = malloc(sizeof(char));
			if (!result[i])
				return (NULL);
			result[i++][0] = '\0';
			continue ;
		}
		result[i++] = get_next_word(s, c);
	}
	result[i] = NULL;
	return (result);
}
