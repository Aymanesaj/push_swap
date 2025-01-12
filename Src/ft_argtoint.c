/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argtoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:12:11 by asajed            #+#    #+#             */
/*   Updated: 2025/01/12 23:03:14 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_argtoint(char *str)
{
	int	len;
	int	i;
	int	sign;

	len = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i + 1] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		len = len * 10 + (str[i] - '0');
		i++;
	}
	return (len * sign);
}
