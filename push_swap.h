/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:55:18 by asajed            #+#    #+#             */
/*   Updated: 2025/01/15 17:09:16 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}					t_list;
// Src/big_sort.c
void				big_sort(t_list **stack_a, t_list **stack_b, int offset);
// Src/create_the_list.c
void				ft_lstadd_back(t_list **lst, int num);
t_list				*create_node(int num);
void				create_stack_a(char **av, t_list **stack_a);
// Src/check.c
int					ft_is_sorted(t_list *head);
int					ft_lstsize(t_list *lst);
int					ft_checkargs(char *s);
int					ft_isdigit(int c);
// Src/Error.c
void				ft_remove(t_list **list);
void				ft_check_double(t_list **stack_a);
void				ft_clean_and_free(t_list **stack_a, t_list **stack_b);
//Src/find.c
int					ft_find_max(t_list *lst);
int					ft_find_min(t_list *lst);
int					ft_index(t_list *lst, int min);
//Src/ft_argtoint.c
long				ft_argtoint(char *str);
char				**ft_split(char const *s, char c);
//Src/ft_substr.c
int					ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
// Src/low_sort.c
void				ft_sort_three(t_list **n);
void				ft_sort_low(t_list **stack_a, t_list **stack_b);
// Src/parsing.c
int					are_all_numbers(char **av);
// Src/push.c
void				ft_push(t_list **dest, t_list **src);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_b, t_list **stack_a);
void				push_back(t_list **stack_b, t_list **stack_a);
// Src/reverse_rotate.c
void				reverse_rotate(t_list **stack);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
// Src/rotate.c
void				rotate(t_list **stack);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
// Src/swap.c
void				ft_swap(t_list *stack);
void				ft_swap_int(int *sorted, int i);
void				sa(t_list *stack_a);
void				sb(t_list *stack_b);
void				ss(t_list *stack_a, t_list *stack_b);

#endif