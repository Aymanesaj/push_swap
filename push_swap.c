/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:45:28 by asajed            #+#    #+#             */
/*   Updated: 2025/01/14 14:25:49 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libftprintf.h"
#include <stdio.h>
#include "push_swap.h"

void	print_list(t_list *head)
{
	if (!head)
	{
		ft_printf("List is empty\n");
		return ;
	}
	while (head)
	{
		ft_printf("%d -> ", head->num);
		head = head->next;
	}
	ft_printf("NULL\n");
}

int ft_range(t_list *stack_a)
{
	int size;
	
	size = ft_lstsize(stack_a);
	if (size <= 16)
		return (3);
	else if (size <= 100)
		return (16);
	else if (size <= 500)
		return (25);
	else
		return (35);
}

// ft_clear(t_list **stack_a, t_list **stack_b)
// {
// 	ft_remove(stack_a);
// 	ft_remove(stack_b);
// }

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
	{
		ft_printf("Error\n");
		return (1);
	}
	create_stack_a(av, &stack_a);
	ft_check_double(&stack_a);
	// if (ft_is_sorted(*stack_a))
	// {
	// 	ft_clear(&stack_a, &stack_b);
	// 	return (1);
	// }
	if (ft_lstsize(stack_a) <= 10)
		ft_sort_low(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) > 10)
		big_sort(&stack_a, &stack_b, ft_range(stack_a));
	// ft_clear(&stack_a, &stack_b);
	ft_remove(&stack_a);
	ft_remove(&stack_b);
}
