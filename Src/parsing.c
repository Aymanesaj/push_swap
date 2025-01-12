/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:45:37 by asajed            #+#    #+#             */
/*   Updated: 2025/01/12 23:10:19 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	are_all_numbers(char **av)
{
	int	i;
	int	j;
	int	num_started;

	i = 0;
	while (av[i])
	{
		j = 0;
		num_started = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				num_started = 0;
			else if ((av[i][j] == '-' || av[i][j] == '+') && !num_started
					&& av[i][j + 1] && ft_isdigit(av[i][j + 1]))
				num_started = 1;
			else if (!ft_isdigit(av[i][j]))
				return (0);
			else
				num_started = 1;
			j++;
		}
		i++;
	}
	return (1);
}
