/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:15:51 by asajed            #+#    #+#             */
/*   Updated: 2025/01/16 10:07:06 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line/get_next_line.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if ((!s1[i] && s2[i]) || (s1[i] && !s2[i]))
		return (0);
	return (1);
}

int	execute_command(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "sa\n"))
		ft_swap(*stack_a);
	else if (ft_strcmp(str, "sb\n"))
		ft_swap(*stack_b);
	else if (ft_strcmp(str, "ss\n"))
		(ft_swap(*stack_a), ft_swap(*stack_b));
	else if (ft_strcmp(str, "pa\n"))
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n"))
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(str, "ra\n"))
		rotate(stack_a);
	else if (ft_strcmp(str, "rb\n"))
		rotate(stack_b);
	else if (ft_strcmp(str, "rr\n"))
		(rotate(stack_a), rotate(stack_b));
	else if (ft_strcmp(str, "rra\n"))
		reverse_rotate(stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		reverse_rotate(stack_b);
	else if (ft_strcmp(str, "rrr\n"))
		(reverse_rotate(stack_a), reverse_rotate(stack_b));
	else
		return (-1);
	return (0);
}

void	check_get_line(t_list **stack_a, t_list **stack_b, int *i)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (execute_command(stack_a, stack_b, str) == -1)
			*i = -1;
		free(str);
		str = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	av = av + 1;
	i = 0;
	if (ac <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!are_all_numbers(av))
		return (write(2, "Error\n", 6));
	create_stack_a(av, &stack_a);
	ft_check_double(&stack_a);
	check_get_line(&stack_a, &stack_b, &i);
	if (i == -1)
		ft_clean_and_free(&stack_a, &stack_b);
	if (ft_is_sorted(stack_a) && !ft_lstsize(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_remove(&stack_a);
	ft_remove(&stack_b);
}
