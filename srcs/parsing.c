/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:08:42 by uclement          #+#    #+#             */
/*   Updated: 2023/05/11 16:01:39 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	parsing(t_list	*lst)
{
	t_list	*tmp;

	while (lst->next != NULL)
	{
		tmp = lst->next;
		while (tmp != NULL)
		{
			if (lst->content == tmp->content)
				return (0);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (1);
}

int	is_sort(t_list *a)
{
	while (a->content > a->next->content)
	{
		a = a->next;
		if (a->next == NULL)
			return (0);
	}
	return (1);
}