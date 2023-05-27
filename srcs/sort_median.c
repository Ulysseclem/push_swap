/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:39:18 by uclement          #+#    #+#             */
/*   Updated: 2023/05/27 13:48:36 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	index_maker(t_list **stack)
{
	t_list	*tmp;
	t_list	*first;
	int		i;

	first = *stack;
	tmp = (*stack)->next;
	while ((*stack) != NULL)
	{		
		i = 1;
		while (tmp != NULL)
		{
			if (((*stack)->content) > (tmp->content))
				i++;
			tmp = tmp->next;
		}
		tmp = first;
		(*stack)->index = i;
		*stack = (*stack)->next;
	}
	*stack = first;
}

void	median_sort(t_list **a, t_list **b)
{
	int		size;
	int		i;
	t_list	*current;
	t_list	*last;

	size = ft_lstsize(*a);
	while (ft_lstsize(*a) > 2)
	{
		i = 0;
		while (i < size)
		{
			current = *a;
			last = ft_lstlast(current);
			if (last->index > (size / 2))
				move(a, b, 5);
			else
				move(a, b, 6);
			i++;
		}
		size = ft_lstsize(*a);
	}
	median_rest(a, b);
}

void	median_rest(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 3)
		three(a, b);
	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->content < (*a)->next->content)
			move(a, b, 1);
	}
}

void	three(t_list **a, t_list **b)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->next->next->content;
	mid = (*a)->next->content;
	bot = (*a)->content;
	if (bot > mid && bot < top && mid < top)
		move(a, b, 6);
	else if (bot < mid && bot < top && mid < top)
	{
		move(a, b, 1);
		move(a, b, 9);
	}
	else if (bot > mid && bot > top && mid < top)
		move(a, b, 1);
	else if (bot < mid && bot > top && mid > top)
	{
		move(a, b, 1);
		move(a, b, 6);
	}
	else if (bot < mid && bot < top && mid > top)
		move(a, b, 9);
}
