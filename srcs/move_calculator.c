/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:49:48 by uclement          #+#    #+#             */
/*   Updated: 2023/05/09 15:16:41 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	calculateur(t_list **b, int call) //ajouter l element de la liste b 
{
	static	instruct count;
	int		size;
	
	compteur(&count, call);
	if (count.sa > 1 && count.sb > 1)
	{
		count.ss++;
		count.sa--;
		count.sb--;
	}
	if (count.ra > 1 && count.rb > 1)
	{
		count.rr++;
		count.rb--;
		count.ra--;
	}
	if (count.rra > 1 && count.rrb > 1)
	{
		count.rrr++;
		count.rrb--;
		count.rra--;
	}
	if (count.pa >= 1)
	{
		size = count.sa + count.sb + count.ss + count.ra + count.rb + count.rr \
		+ count.rra + count.rrb + count.rrr + count.pa;
		(*b)->index = size;
		size = 0;
		ft_memset(&count, 0, sizeof(count));
	}
}

void	compteur(instruct *count, int call)
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
	t_list *current;
	t_list	*min;
	
	min = ft_lstnew(NULL);
	current = *b;
	min->index = current->index;
	min->content = current->content;
	if (current->next == NULL)
	{
		min->content = current->content;
		ro_re_maker(a, b, min->content);
		return ;
	}
	while (current != NULL)
	{
		if(current->index < min->index)
		{
			min->index = current->index;
			min->content = current->content;
		}
		current = current->next;
	}
	ro_re_maker(a, b, min->content);
}

void	ro_re_maker(t_list **a, t_list **b, int min)
{
	t_list *current;
	int i;
	int size;
	
	size = ft_lstsize(*b);
	current = (*b);
	i = 1;
	while (current->content != min)
	{
		i++;
		current = current->next;
	}
	if (i <= size/2)
	{
		while (i)
		{
			tri(a, b, 10);
			i--;
		}
		hundred(a, b);
		return;
	}
	if (i > size/2)
	{
		i = size - i;
		while (i)
		{
			tri(a, b, 7);
			i--;
		}
		hundred(a, b);
		return;
	}
}

void	index_mover(t_list **a, t_list **b)
{
	t_list	*current;
	int		size;
	int		i;
	int		j;
	
	size = ft_lstsize(*b);
	i = 1;
	current = *b;
	while (current != NULL)
	{
		if (i <= (size / 2))
		{
			j = i;
			while (j)
			{
			calculateur(b, 10);
			j--;
			}
		}
		else
		{
			j = size - i;
			while (j)
			{
			calculateur(b, 7);
			j--;
			}
		}
		thinker(a, &current);
		i++;
		current = current->next;
	}
	search_index_min(a, b);
}

void	thinker(t_list **a, t_list **b)
{
	t_list	*current;
	int		count;
	int		nbr;

	current = *a;
	count = 1;
	nbr = (*b)->content;
	while (current->next != NULL)
		{
			if (nbr < current->content && (current->next == NULL || nbr > current->next->content))
				break ;
			if (current->content < current->next->content && nbr > current->next->content)
				break;
			count++;
			current = current->next;
		}
	thinker_order(a,b,count);
}

void	thinker_order(t_list **a, t_list **b, int count)
{
	if (count <= (ft_lstsize(*a)/2))
	{
		while (count != 0)
		{
			calculateur(b,9);
			count--;
		}
		calculateur(b, 4);
	}
	else 
	{
		count = ft_lstsize(*a) - count;
		while (count != 0)
		{
			calculateur(b,6);
			count--;
		}
		calculateur(b,4);
	}
}