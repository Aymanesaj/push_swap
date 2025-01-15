/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:45:28 by asajed            #+#    #+#             */
/*   Updated: 2025/01/15 16:17:51 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_range(t_list *stack_a)
{
	int	size;

	size = ft_lstsize(stack_a);
	if (size <= 16)
		return (3);
	else if (size <= 100)
		return (16);
	else if (size <= 500)
		return (30);
	else
		return (35);
}

int	ft_clear(t_list **stack_a, t_list **stack_b)
{
	ft_remove(stack_a);
	ft_remove(stack_b);
	return (-1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		return (0);
	av += 1;
	if (!are_all_numbers(av))
		return (write(2, "Error\n", 6));
	create_stack_a(av, &stack_a);
	ft_check_double(&stack_a);
	if (ft_is_sorted(stack_a))
		return (ft_clear(&stack_a, &stack_b));
	if (ft_lstsize(stack_a) <= 10)
		ft_sort_low(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) > 10)
		big_sort(&stack_a, &stack_b, ft_range(stack_a));
	ft_clear(&stack_a, &stack_b);
	return (0);
}
