/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:26:01 by uclement          #+#    #+#             */
/*   Updated: 2023/04/28 16:05:56 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"


void	compteur()
{
	static struc count;
	

}

void	median_sort(t_list **a, t_list **b)
{
	int	size;
	int	i;
	int count = 0;

	size = ft_lstsize(*a);

	while (ft_lstsize(*a) > 5)
	{
		i = 0;
		while (i < size)
		{
			if ((*a)->index >= (size / 2))
				tri(a, b, 5);
			else
				tri(a, b, 6);
			i++;
			count++;
		}
		size = ft_lstsize(*a);
	}
	printf("\n \n count = %d \n",count);
}

void	hundred(t_list **a, t_list **b)
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
			tri(a,b,4);										// sinon cela veut dire qu'on a tout traverse et la valeur la plus grand est bien la valeur du debut, donc un push et rotate
			tri(a,b,6);
			return;
		}
		count++;
		current = current ->next;
	}
	order(a,b,count);
}

void	order(t_list **a, t_list **b, int count)
{
	if (count <= (ft_lstsize(*a)/2))
	{
		while (count != 0)
		{
			tri(a, b, 9);
			count--;
		}
		tri(a, b, 4);
		sort(a);
	}
	else 
	{
		count = ft_lstsize(*a) - count;
		while (count != 0)
		{
			tri(a, b, 6);
			count--;
		}
		tri(a, b, 4);
		sort(a);
	}
}

void	sort(t_list **stack)
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
	if (count <= (ft_lstsize(*stack) / 2))
	{
		while (count > 0)		
		{
			tri(stack, NULL, 9);
			count--;
		}
	}
	else
	{
		count = ft_lstsize(*stack) - count;
		while (count > 0)		
		{
			tri(stack, NULL, 6);
			count--;
		}
	}
}


void	five(t_list **a, t_list **b)
{
	tri(a, b, 5);
	tri(a, b, 5);
	three(a);
	hundred(a, b);
	hundred(a, b);
}


void	three(t_list **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->next->next->content;
	mid = (*a)->next->content;
	bot = (*a)->content;
	if (bot > mid && bot < top && mid < top)
		tri(a, NULL, 6);
	else if (bot < mid && bot < top && mid < top)
	{
		tri(a,  NULL, 1);
		tri(a, NULL, 9);
	}
	else if (bot > mid && bot > top && mid < top)
		tri(a, NULL, 1);
	else if (bot < mid && bot > top && mid > top)
	{
		tri(a, NULL, 1);
		tri(a, NULL, 6);
	}
	else if (bot < mid && bot < top && mid > top)
		tri(a, NULL, 9);
}
