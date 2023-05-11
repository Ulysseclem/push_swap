/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:03:28 by uclement          #+#    #+#             */
/*   Updated: 2023/05/11 14:04:09 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	move(t_list **stack_a, t_list **stack_b, int call)
{
	if (call == 1 || call == 2)
		pair_swap(stack_a);
	else if (call == 3)
		double_move(stack_a, stack_b, call);
	else if (call == 4)
		push(stack_a, stack_b);
	else if (call == 5)
		push(stack_b, stack_a);
	else if (call == 6 || call == 7)
		rotate(stack_a);
	else if (call == 8)
		double_move(stack_a, stack_b, call);
	if (call == 9 || call == 10)
		reverse(stack_a);
	else if (call == 11)
		double_move(stack_a, stack_b, call);
	print_move(call);
}

void	double_move(t_list **stack_a, t_list **stack_b, int call)
{
	if (call == 3)
	{
		pair_swap(stack_a);
		pair_swap(stack_b);
	}
	else if (call == 8)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (call == 11)
	{
		reverse(stack_a);
		reverse(stack_b);
	}
}

void	print_move(int call)
{	
	if (call == 1)
		printf("sa\n");
	if (call == 2)
		printf("sb\n");
	if (call == 3)
		printf("ss\n");
	if (call == 4)
		printf("pa\n");
	if (call == 5)
		printf("pb\n");
	if (call == 6)
		printf("ra\n");
	if (call == 7)
		printf("rb\n");
	if (call == 8)
		printf("rr\n");
	if (call == 9)
		printf("rra\n");
	if (call == 10)
		printf("rrb\n");
	if (call == 11)
		printf("rrr\n");
}
