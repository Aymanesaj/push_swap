/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:09:00 by asajed            #+#    #+#             */
/*   Updated: 2025/01/15 15:59:13 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*previous;

	if (!stack || !(*stack))
		return ;
	temp = *stack;
	while (temp->next)
	{
		previous = temp;
		temp = temp->next;
	}
	temp->next = *stack;
	*stack = temp;
	previous->next = NULL;
}

void	rra(t_list **stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !(*stack_a))
		return ;
	if (!stack_b || !(*stack_b))
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
