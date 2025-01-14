/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_the_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:48:57 by asajed            #+#    #+#             */
/*   Updated: 2025/01/14 16:41:28 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_node(int num)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, int num)
{
	t_list	*p;
	t_list	*new_node;

	new_node = create_node(num);
	if (!(*lst) || !lst)
	{
		*lst = new_node;
		return ;
	}
	p = *lst;
	if (!new_node)
		return ;
	while (p->next)
		p = p->next;
	p->next = new_node;
}

int	split_and_addto_list(char *str, t_list **stack_a)
{
	char	**strs;
	int		i;
	int		num;

	i = 0;
	strs = ft_split(str, ' ');
	while (strs[i])
	{
		num = ft_argtoint(strs[i]);
		ft_lstadd_back(stack_a, num);
		i++;
	}
	while (i--)
		free(strs[i]);
	free(strs);
	return (1);
}

void	create_stack_a(char **av, t_list **stack_a)
{
	int		i;
	long	num;

	i = 0;
	while (av[i])
	{
		if (ft_checkargs(av[i]) > 1)
			split_and_addto_list(av[i], stack_a);
		else
		{
			num = ft_argtoint(av[i]);
			if (num > 2147483647 || num < -2147483648)
			{
				ft_remove(stack_a);
				write(2, "Error\n", 6);
				exit(1);
			}
			ft_lstadd_back(stack_a, num);
		}
		i++;
	}
}
