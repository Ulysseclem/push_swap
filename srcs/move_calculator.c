/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:49:48 by uclement          #+#    #+#             */
/*   Updated: 2023/05/11 16:18:12 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	iter_index(t_list **a, t_list **b)
{
	t_list	*current;
	int		i;
	int		j;

	i = 1;
	current = *b;
	while (current != NULL)
	{
		if (i <= (ft_lstsize(*b) / 2))
		{
			j = i + 1;
			while (--j)
				calculateur(b, 10);
		}
		else
		{
			j = ft_lstsize(*b) - i + 1;
			while (--j)
				calculateur(b, 7);
		}
		index_find_pos(a, &current);
		i++;
		current = current->next;
	}
	search_index_min(a, b);
}

void	index_find_pos(t_list **a, t_list **b)
{
	t_list	*current;
	int		count;
	int		nbr;

	current = *a;
	count = 1;
	nbr = (*b)->content;
	while (current->next != NULL)
	{
		if (nbr < current->content && \
		(current->next == NULL || nbr > current->next->content))
			break ;
		if (current->content < current->next->content && \
		nbr > current->next->content)
			break ;
		count++;
		current = current->next;
	}
	index_sort(a, b, count);
}

void	index_sort(t_list **a, t_list **b, int count)
{
	if (count <= (ft_lstsize(*a) / 2))
	{
		while (count != 0)
		{
			calculateur(b, 9);
			count--;
		}
		calculateur(b, 4);
	}
	else
	{
		count = ft_lstsize(*a) - count;
		while (count != 0)
		{
			calculateur(b, 6);
			count--;
		}
		calculateur(b, 4);
	}
}