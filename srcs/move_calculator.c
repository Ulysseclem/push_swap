/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:49:48 by uclement          #+#    #+#             */
/*   Updated: 2023/05/01 15:45:49 by uclement         ###   ########.fr       */
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
	count.pb = 1;
	if (count.pa > 0 && count.pb > 0)
	{
		size = count.sa + count.sb + count.ss + count.ra + count.rb + count.rr \
		+ count.rra + count.rrb + count.rrr + 1;
		(*b)->index = size;
		size = 0;
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

// t_list	*search_index_min(t_list *b)
// {
// 	t_list *current;
	
// 	current = b;
// 	while (b != NULL)
// 	{
// 		if(current->content > b->content)
// 			current->content = b->content
// 		b = b->next;
// 	}
// 	return (current);
// }

void	index_mover(t_list **a, t_list **b)
{
	t_list *first;
	
	first = *b;
	while ((*b) != NULL)
	{
		thinker(a, b);
		// calculateur(b,7); // ajouter une condition entre rb et rrb en fonction de la size de b
		*b = (*b)->next;
	}
	*b = first;
}

void	thinker(t_list **a, t_list **b)
{
	t_list	*current;
	int		count;
	int		nbr;

	current = *a;
	count = 1; 
	nbr = ft_lstlast(*b)->content;
	while (current != NULL)
	{
		if (nbr < current->content && (current->next == NULL || nbr > current->next->content))				
			break ;
		else if (nbr > current->content && nbr > current->next->content) // si nbr plus grand que valeur et valeur.suivante
		{
			if (current->content < current->next->content) //si la a un moment donne valeur < valeur.suivante alors on break 
				break ;
			calculateur(b,4);										// sinon cela veut dire qu'on a tout traverse et la valeur la plus grand est bien la valeur du debut, donc un push et rotate
			calculateur(b,6);
			return;
		}
		count++;
		current = current ->next;
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