/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:45:35 by asajed            #+#    #+#             */
/*   Updated: 2025/01/12 23:37:03 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_list **n)
{
	if (ft_lstsize(*n) == 3)
	{
		while (!ft_is_sorted(*n))
		{
			if (ft_is_sorted(*n))
				return ;
			else if ((*n)->num > (*n)->next->num
				&& (*n)->num > (*n)->next->next->num)
				ra(n);
			else if ((*n)->num > (*n)->next->num)
				sa(*n);
			else if ((*n)->num < (*n)->next->num
				&& (*n)->next->next->num < (*n)->num)
				rra(n);
			else if ((*n)->num < (*n)->next->num
				&& (*n)->next->num > (*n)->next->next->num)
			{
				sa(*n);
				ra(n);
			}
		}
	}
	else if (ft_lstsize(*n) == 2 && (*n)->num > (*n)->next->num)
		sa(*n);
}

void	ft_sort_low(t_list **stack_a, t_list **stack_b)
{
	int		min;
	t_list	*tmp;

	min = ft_find_min(*stack_a);
	tmp = *stack_a;
	while ((ft_lstsize(*stack_a) > 3))
	{
		if (ft_is_sorted(*stack_a))
			break ;
		tmp = *stack_a;
		min = ft_find_min(*stack_a);
		if (tmp->num == min)
			pb(stack_b, stack_a);
		else if (tmp->next->num == min)
		{
			sa(*stack_a);
			pb(stack_b, stack_a);
		}
		else
			rra(stack_a);
	}
	ft_sort_three(stack_a);
	while (ft_lstsize(*stack_b))
		pa(stack_a, stack_b);
}
