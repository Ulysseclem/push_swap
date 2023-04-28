/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:28:29 by uclement          #+#    #+#             */
/*   Updated: 2023/04/28 16:04:15 by uclement         ###   ########.fr       */
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
} struc;

void	pair_swap(t_list **stack);
void	print_list(t_list *node);
void	to_list_a(char *argv,t_list **stack_a);
void	error_exit(void);
void	push(t_list **receiver, t_list **sender);
void	rotate(t_list **stack_a);
void	reverse(t_list	**stack);

t_list *dele(t_list *head);
t_list	*ps_lstnew(int content);
void	free_lst(t_list	*lst);
t_list	*test(t_list *tmp);

int	parsing(t_list	*lst);

void	tri(t_list **stack_a, t_list **stack_b, int call);
void	tri_2(t_list **stack_a, t_list **stack_b, int call);
void	print_tri(int call);

void	index_maker(t_list **stack);
void	median_sort(t_list **a, t_list **b);
void	three(t_list **a);
void	five(t_list **a, t_list **b);
void	sort(t_list **stack);

void	hundred(t_list **a, t_list **b);
void	order(t_list **a, t_list **b, int count);



#endif