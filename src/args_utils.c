/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:03:33 by marvin            #+#    #+#             */
/*   Updated: 2025/04/04 11:03:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_argc(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	**handle_split_args(char **av, int *free_args)
{
	char	**args = ft_split(av[1], ' ');

	if (!args || !args[0])
		exit_error(NULL, NULL);
	*free_args = 1;
	return (args);
}
