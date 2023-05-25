/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:12:39 by uclement          #+#    #+#             */
/*   Updated: 2023/05/24 14:14:38 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_list	*dele(t_list *head)
{
	t_list	*current;
	t_list	*prev;

	current = head;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	if (current != NULL)
		free(current);
	return (head);
}

t_list	*ps_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	free_lst(t_list	**lst)
{
	t_list	*tmp;

	while ((*lst) != NULL)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free(tmp);
	}
}

void	free_lst_2(t_list	*lst)
{
	t_list	*tmp;

	while ((lst) != NULL)
	{
		tmp = (lst);
		(lst) = (lst)->next;
		free(tmp);
	}
}

long long int	ps_atoi(const char *nptr)
{
	long long int	num;
	int				i;
	long long int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - 48);
		if (nptr[i] < '0' && nptr[i] > '9')
			error_exit();
		i++;
	}
	return (num * neg);
}
