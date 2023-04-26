/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:12:39 by uclement          #+#    #+#             */
/*   Updated: 2023/04/26 19:06:29 by uclement         ###   ########.fr       */
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
