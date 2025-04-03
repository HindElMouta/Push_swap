/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinel-mo <hinel-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:44:18 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/04/03 16:40:00 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_len(const char *str, char sep)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	return (len);
}

static int	count_words(const char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i])
		{
			count++;
			i += word_len(&str[i], sep);
		}
	}
	return (count);
}

static char	*str_dup(const char *src, int len)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(const char *str, char sep)
{
	char	**res;
	int		i;
	int		wlen;

	i = 0;
	if (!str)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(str, sep) + 1));
	if (!res)
		return (NULL);
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
		{
			wlen = word_len(str, sep);
			res[i++] = str_dup(str, wlen);
			str += wlen;
		}
	}
	res[i] = NULL;
	return (res);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
