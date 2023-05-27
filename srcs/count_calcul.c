/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_calcul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:48:18 by uclement          #+#    #+#             */
/*   Updated: 2023/05/27 15:37:24 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	calculateur(t_list **b, int call)
{
	static t_instruct	count;
	int					size;

	compteur(&count, call);
	if (count.pa >= 1)
	{
		size = count.sa + count.sb + count.ss + count.ra + count.rb + count.rr \
		+ count.rra + count.rrb + count.rrr + count.pa;
		(*b)->index = size;
		size = 0;
		ft_memset(&count, 0, sizeof(count));
	}
}

void	compteur(t_instruct *count, int call)
{
	if (call == 1)
		count->sa = 1 + count->sa;
	if (call == 2)
		count->sb = 1 + count->sb;
	if (call == 3)
		count->ss = 1 + count->ss;
	if (call == 4)
		count->pa = 1 + count->pa;
	if (call == 5)
		count->pb = 1 + count->pb;
	if (call == 6)
		count->ra = 1 + count->ra;
	if (call == 7)
		count->rb = 1 + count->rb;
	if (call == 8)
		count->rr = 1 + count->rr;
	if (call == 9)
		count->rra = 1 + count->rra;
	if (call == 10)
		count->rrb = 1 + count->rrb;
	if (call == 11)
		count->rrr = 1 + count->rrr;
}

void	search_index_min(t_list **a, t_list **b)
{
	t_list	*current;
	int		min;
	int		test;

	current = *b;
	test = current->content;
	if (current->next == NULL)
	{
		sort_b_stack(a, b, test);
		return ;
	}
	while (current != NULL)
	{
		if (current->index < test)
		{
			test = current->index;
			min = current->content;
		}
		current = current->next;
	}
	sort_b_stack(a, b, min);
}

void	sort_b_stack(t_list **a, t_list **b, int min)
{
	int	i;

	i = iter_i_min(b, min);
	if (i <= ft_lstsize(*b) / 2)
	{
		while (i--)
		{
			move(b, a, 10);
		}
		find_pos(a, b);
		return ;
	}
	if (i > ft_lstsize(*b) / 2)
	{
		i = ft_lstsize(*b) - i;
		while (i--)
			move(b, a, 7);
		find_pos(a, b);
		return ;
	}
}

int	iter_i_min(t_list **b, int min)
{
	t_list	*current;
	int		i;

	current = (*b);
	i = 1;
	while (current->content != min)
	{
		i++;
		current = current->next;
	}
	return (i);
}
