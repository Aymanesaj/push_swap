/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:15:51 by asajed            #+#    #+#             */
/*   Updated: 2025/01/15 21:31:30 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line/get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if ((s1[i] && !s2[i]) || (!s1[i] && s2[i]))
		return (0);
	return (1);
}

void	checker_free(t_list **stack_a, t_list **stack_b, char **str)
{
	free(*str);
	ft_remove(stack_a);
	ft_remove(stack_b);
	write(2, "Error\n", 6);
}

int	swap_or_push(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "sa\n"))
		ft_swap(*stack_a);
	else if (ft_strcmp(str, "sb\n"))
		ft_swap(*stack_b);
	else if (ft_strcmp(str, "ss\n"))
	{
		ft_swap(*stack_a);
		ft_swap(*stack_b);
	}
	else if (ft_strcmp(str, "pa\n"))
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n"))
		ft_push(stack_b, stack_a);
	else
		return (0);
	return (1);
}

int	rotate_or_reverse(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "ra\n"))
		rotate(stack_a);
	else if (ft_strcmp(str, "rb\n"))
		rotate(stack_b);
	else if (ft_strcmp(str, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strcmp(str, "rra\n"))
		reverse_rotate(stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		reverse_rotate(stack_b);
	else if (ft_strcmp(str, "rrr\n"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_a);
	}
	else
		return (0);
	return (1);
}

int	check_get_line(t_list **stack_a, t_list **stack_b)
{
	char	*str;
	int		i;

	str = get_next_line(0);
	while (str)
	{
		if (str[0] == 's' || str[0] == 'p')
			i = swap_or_push(stack_a, stack_b, str);
		else if (str[0] == 'r')
			i = rotate_or_reverse(stack_a, stack_b, str);
		else
		{
			(ft_remove(stack_a), ft_remove(stack_b), free(str));
			return (-1);
		}
		if (!i)
		{
			(ft_remove(stack_a), ft_remove(stack_b), free(str));
			return (-1);
		}
		free(str);
		str = get_next_line(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	av = av + 1;
	if (ac <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!are_all_numbers(av))
		return (write(2, "Error\n", 6));
	create_stack_a(av, &stack_a);
	ft_check_double(&stack_a);
	i = check_get_line(&stack_a, &stack_b);
	if (i == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (ft_is_sorted(stack_a) && !ft_lstsize(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_remove(&stack_a);
	ft_remove(&stack_b);
}
