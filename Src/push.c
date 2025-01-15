/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:24:34 by asajed            #+#    #+#             */
/*   Updated: 2025/01/15 15:58:48 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (!src || !(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	push_back(t_list **stack_b, t_list **stack_a)
{
	int	max_index;

	while (ft_lstsize(*stack_b))
	{
		max_index = ft_index(*stack_b, ft_find_max(*stack_b));
		if (max_index == 0)
			pa(stack_a, stack_b);
		else if (max_index == 1)
			sb(*stack_b);
		else if (max_index >= (ft_lstsize(*stack_b) / 2))
			rrb(stack_b);
		else
			rb(stack_b);
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	ft_push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
