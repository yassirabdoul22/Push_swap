/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:41:49 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/12/09 14:41:58 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int	is_separator(char c, char sep)
{
	return (c == sep);
}

int	count_words(char *str, char sep)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_separator(*str, sep))
			str++;
		if (*str && !is_separator(*str, sep))
		{
			count++;
			while (*str && !is_separator(*str, sep))
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str, char sep)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	i = 0;
	while (str[len] && !is_separator(str[len], sep))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	char	**result;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		while (*str && is_separator(*str, c))
			str++;
		if (*str && !is_separator(*str, c))
		{
			result[i++] = malloc_word(str, c);
			while (*str && !is_separator(*str, c))
				str++;
		}
	}
	result[i] = NULL;
	return (result);
}