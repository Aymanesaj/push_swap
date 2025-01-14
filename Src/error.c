/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:45:32 by asajed            #+#    #+#             */
/*   Updated: 2025/01/13 09:50:07 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_remove(t_list **list)
{
	t_list	*tmp;
	t_list	*next;

	if (!list || !(*list))
		return ;
	tmp = *list;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*list = tmp;
}

void	ft_check_double(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*head;

	head = *stack_a;
	if (!head)
		return ;
	while (head)
	{
		tmp = head;
		while (tmp->next)
		{
			if (head->num == tmp->next->num)
				ft_clean_and_free(stack_a, NULL);
			tmp = tmp->next;
		}
		head = head->next;
	}
}

void	ft_clean_and_free(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		ft_remove(stack_a);
	if (stack_b)
		ft_remove(stack_b);
	ft_printf("Error\n");
	exit(1);
}
