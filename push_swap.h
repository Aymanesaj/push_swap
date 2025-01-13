/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:55:18 by asajed            #+#    #+#             */
/*   Updated: 2025/01/12 23:49:35 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libftprintf.h"
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}					t_list;
// Src/create_the_list.c
void				ft_lstadd_back(t_list **lst, int num);
t_list				*create_node(int num);
void				create_stack_a(char **av, t_list **stack_a);
// Src/check.c
int					ft_is_sorted(t_list *head);
int					ft_lstsize(t_list *lst);
int					ft_checkargs(char *s);
// Src/Error.c
void				ft_remove(t_list **list, int index);
void				ft_check_double(t_list **stack_a);
void				ft_clean_and_free(t_list **stack_a, t_list **stack_b);
//Src/find.c
int					ft_find_max(t_list *lst);
int					ft_find_min(t_list *lst);
//Src/ft_argtoint.c
long				ft_argtoint(char *str);
//Src/ft_split.c
char				**ft_split(char const *s, char c);
//Src/ft_substr.c
char				*ft_substr(char const *s, unsigned int start, size_t len);
// Src/low_sort.c
void				ft_sort_three(t_list **n);
void				ft_sort_low(t_list **stack_a, t_list **stack_b);
// Src/parsing.c
int					are_all_numbers(char **av);
// Src/push.c
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_b, t_list **stack_a);
// Src/reverse_rotate.c
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
// Src/rotate.c
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
// Src/swap.c
void				sa(t_list *stack_a);
void				sb(t_list *stack_b);
void				ss(t_list *stack_a, t_list *stack_b);

#endif