/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:28:29 by uclement          #+#    #+#             */
/*   Updated: 2023/05/26 16:37:05 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include "libft.h"
# include <stdio.h> //

typedef struct s_function
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
} instruct;

void	pair_swap(t_list **stack);
void	print_list(t_list *a, t_list *b);
void	to_list_a(char **argv, int argc, t_list **stack_a);
void	error_exit(void);
void	push(t_list **receiver, t_list **sender);
void	rotate(t_list **stack_a);
void	reverse(t_list	**stack);

t_list *dele(t_list *head);
t_list	*ps_lstnew(int content);
void	free_lst(t_list	**lst);
t_list	*test(t_list *tmp);

int	parsing(t_list	*lst);

void	move(t_list **stack_a, t_list **stack_b, int call);
void	move_2(t_list **stack_a, t_list **stack_b, int call);
void	print_move(int call);

void	index_maker(t_list **stack);
void	median_sort(t_list **a, t_list **b);
void	three(t_list **a, t_list **b);
void	five(t_list **a, t_list **b);
void	last_sort(t_list **stack, t_list **b);

void	find_pos(t_list **a, t_list **b);
void	sort(t_list **a, t_list **b, int count);

void	compteur(instruct *count, int call);
void	calculateur(t_list **b, int call);
void	search_index_min(t_list **a, t_list **b);
void	iter_index(t_list **a, t_list **b);
void	index_find_pos(t_list **a, t_list **b);
void	index_sort(t_list **a, t_list **b, int count);
void	sort_b_stack(t_list **a, t_list **b, int min);

void	double_move(t_list **stack_a, t_list **stack_b, int call);

int	is_sort(t_list *a);

long long int	ps_atoi(const char *nptr);

void	push_suite(t_list **receiver, t_list *curr);
int	iter_i_min(t_list **b, int min);

t_list	*create_stack(int content);


#endif