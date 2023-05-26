/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:12:39 by uclement          #+#    #+#             */
/*   Updated: 2023/05/26 16:10:29 by uclement         ###   ########.fr       */
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

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = 0;
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

t_list	*create_stack(int content)
{
	t_list	*stack;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->index = 0;
	stack->next = NULL;
	return (stack);
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
