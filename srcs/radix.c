/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:26:01 by uclement          #+#    #+#             */
/*   Updated: 2023/04/26 18:21:22 by uclement         ###   ########.fr       */
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

// void	five(t_list **stack)
// {
// 	/*Lire la chaine et stocker la valeur en haut de la pile
// 	- si le content est > a next->content et < haut de pile alors on regarde le suivant
// 	- si le content est < a next->content et < haute de pile alors on reverse le bas de la pile vers le haut
// 	- si le content est < a next->content et > haut de pile alors on push le haut de pile et on deplace le bas */

// }

void	three(t_list **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->next->next->content;
	mid = (*a)->next->content;
	bot = (*a)->content;

	if (bot > mid && bot > top && mid < top)
		tri(a, NULL, 1);
	else if (bot < mid && bot < top && mid < top)
	{
		tri(a,  NULL, 1);
		tri(a, NULL, 9);
	}
	else if (bot > mid && bot < top && mid < top)
		tri(a, NULL, 6);
	else if (bot < mid && bot > top && mid > top)
	{
		tri(a, NULL, 1);
		tri(a, NULL, 6);
	}
	else if (bot < mid && bot < top && mid > top)
		tri(a, NULL, 9);
}
