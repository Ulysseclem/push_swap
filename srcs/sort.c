/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:26:01 by uclement          #+#    #+#             */
/*   Updated: 2023/05/27 14:14:51 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	find_pos(t_list **a, t_list **b)
{
	t_list	*current;
	int		count;
	int		nbr;

	current = *a;
	count = 1;
	nbr = ft_lstlast(*b)->content;
	while (current->next != NULL)
	{
		if (nbr < current->content && (current->next == NULL || \
		nbr > current->next->content))
			break ;
		if (current->content < current->next->content && \
		nbr > current->next->content)
			break ;
		count++;
		current = current->next;
	}
	sort(a, b, count);
}

void	sort(t_list **a, t_list **b, int count)
{
	if (count <= (ft_lstsize(*a) / 2))
	{
		while (count != 0)
		{
			move(a, b, 9);
			count--;
		}
		move(a, b, 4);
	}
	else
	{
		count = ft_lstsize(*a) - count;
		while (count != 0)
		{
			move(a, b, 6);
			count--;
		}
		move(a, b, 4);
	}
}

void	last_sort(t_list **stack, t_list **b)
{
	t_list	*current;
	int		nbr;
	int		count;

	current = *stack;
	nbr = current->content;
	count = 1;
	current = current->next;
	while (current != NULL)
	{
		if (current->content < nbr)
			count++;
		else
			break ;
		current = current->next;
	}
	if (count == ft_lstsize(*stack))
		return ;
	last_sort_suite(stack, b, count);
}

void	last_sort_suite(t_list **stack, t_list **b, int count)
{
	if (count <= (ft_lstsize(*stack) / 2))
	{
		while (count > 0)
		{
			move(stack, b, 9);
			count--;
		}
	}
	else
	{
		count = ft_lstsize(*stack) - count;
		while (count > 0)
		{
			move(stack, b, 6);
			count--;
		}
	}
}
