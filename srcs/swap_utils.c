/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:12:39 by uclement          #+#    #+#             */
/*   Updated: 2023/04/24 15:15:00 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_list	*dele(t_list *head)
{
	t_list	*curr;

	curr = head;

	if (head != NULL)
	{
		head = head->next;
		free(curr);
	}
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

void	free_lst(t_list	*lst)
{
	t_list	*current;
	t_list	*next;

	current = lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
