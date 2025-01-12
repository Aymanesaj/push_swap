/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:45:28 by asajed            #+#    #+#             */
/*   Updated: 2025/01/12 23:30:59 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libftprintf.h"
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
		ft_printf("%d ->", head->num);
		head = head->next;
	}
	ft_printf("NULL\n");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list  *stack_b;

	if (ac <= 1)
		return (0);
	av += 1;
	if (!are_all_numbers(av))
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_a = NULL;
	create_stack_a(av, &stack_a);
	ft_check_double(&stack_a);
	if (ft_lstsize(stack_a) <= 10)
		ft_sort_low(&stack_a, &stack_b);
	print_list(stack_a);
}
