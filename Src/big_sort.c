/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:41:10 by asajed            #+#    #+#             */
/*   Updated: 2025/01/14 15:24:30 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_list(int *sorted, int size)
{
	int	i;
	int	swapped;

	i = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (sorted[i] > sorted[i + 1])
			{
				ft_swap_int(sorted, i);
				swapped = 1;
			}
			i++;
		}
	}
}

int	*sorted_array(t_list **stack_a)
{
	t_list	*tmp;
	int		*sorted;
	int		i;
	int		size;

	tmp = *stack_a;
	i = 0;
	size = ft_lstsize(*stack_a);
	sorted = malloc(sizeof(int) * size);
	if (!(sorted))
		return (NULL);
	while (tmp)
	{
		(sorted)[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	sort_list(sorted, size);
	return (sorted);
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

void	ra_or_rra(t_list **stack_a, int i, int offset, int *sorted)
{
	t_list	*tmp;
	int		j;

	tmp = *stack_a;
	j = 0;
	while (tmp && !(tmp->num >= sorted[i] && tmp->num <= sorted[i + offset]))
	{
		tmp = tmp->next;
		j++;
	}
	if (j > ft_lstsize(*stack_a) / 2)
		rra(stack_a);
	else
		ra(stack_a);
}

void	big_sort(t_list **stack_a, t_list **stack_b, int offset)
{
	int	*sorted;
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*stack_a);
	sorted = sorted_array(stack_a);
	while (ft_lstsize(*stack_a))
	{
		if (i + offset > size)
			offset = size - i;
		if ((*stack_a)->num <= sorted[i])
		{
			pb(stack_b, stack_a);
			if (ft_lstsize(*stack_b) > 1
				&& (*stack_b)->num < (*stack_b)->next->num)
				rb(stack_b);
			i++;
		}
		else if ((*stack_a)->num > sorted[i] && (*stack_a)->num <= sorted[i
				+ offset - 1])
		{
			pb(stack_b, stack_a);
			i++;
		}
		else
			ra_or_rra(stack_a, i, offset, sorted);
	}
	push_back(stack_b, stack_a);
	free(sorted);
}
