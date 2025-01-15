/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:02:36 by asajed            #+#    #+#             */
/*   Updated: 2025/01/15 15:59:47 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_int(int *sorted, int i)
{
	int	tmp;

	tmp = sorted[i];
	sorted[i] = sorted[i + 1];
	sorted[i + 1] = tmp;
}

void	ft_swap(t_list *stack)
{
	int	tmp;

	if (!stack || !stack->next)
	{
		return ;
	}
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

void	sa(t_list *stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list *stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
