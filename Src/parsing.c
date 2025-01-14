/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:45:37 by asajed            #+#    #+#             */
/*   Updated: 2025/01/14 20:39:35 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	number_length(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int	valid_number(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			j = number_length(str + i);
		if (j > 10)
			return (0);
		i++;
	}
	return (1);
}

int	check_spaces(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	if (!size)
		return (0);
	while (i < size)
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	valid_argument(char *str)
{
	int	i;
	int	num_started;

	i = 0;
	num_started = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			num_started = 0;
		else if ((str[i] == '-' || str[i] == '+') && !num_started && str[i + 1]
			&& ft_isdigit(str[i + 1]))
			num_started = 1;
		else if (ft_isdigit(str[i]))
			num_started = 1;
		else
			return (0);
		i++;
	}
	return (1);
}

int	are_all_numbers(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!check_spaces(av[i]) || !valid_number(av[i]))
			return (0);
		if (!valid_argument(av[i]))
			return (0);
		i++;
	}
	return (1);
}
