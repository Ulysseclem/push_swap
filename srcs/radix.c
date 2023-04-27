/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:26:01 by uclement          #+#    #+#             */
/*   Updated: 2023/04/27 17:35:52 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

// void	compteur(t_list *a, t_list **b)
// {
// /*Je prends le b->content et je cherche la position ou il faut le mettre
// 	- je parcours une liste trie, je le positionne entre la valeur < et >
// 	- je count la chaine parcouru pour savoir si je dois rotate ou reverse (si count superieusr a size/2 = rotate)
// 	- je simule les coups
// je pleure*/

// }


/* 

liste range -> je parcour les valeurs et j'insere la valeur des que b > que a->next (avant a->next)



*/

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
	t_list	*current;
	t_list	*curr_b;
	int		count;
	int		j;

	tri(a, b, 5);
	tri(a, b, 5);
	three(a);
	j = 2;
	while (j > 0)
	{
		count = 0;
		curr_b = ft_lstlast(*b);
		current = *a;
		while (current != NULL)
		{
			if (curr_b->content < current->content) 
				count++;
			current = current->next;
		}
		if (count < (ft_lstsize(*a)/2))
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
			// printf("\n liste :");
			// print_list(*a);
			sort(a);

		}
		j--;
	}
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
