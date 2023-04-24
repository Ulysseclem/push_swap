/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:37:03 by uclement          #+#    #+#             */
/*   Updated: 2023/04/24 16:52:44 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	pair_swap(t_list **head)
{
	t_list	*curr;
	t_list	*prev;

	if (!head)
		return ;
	if (head == NULL || (*head)->next == NULL)
		return ;
	curr = (*head)->next->next;
	prev = *head;
	*head = (*head)->next;
	(*head)->next = prev;
	prev->next = curr;
}

void	push(t_list **receiver, t_list **sender)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	tmp->content = (*sender)->content;
	tmp->next = NULL;
	ft_lstadd_front(receiver, tmp);
	*sender = dele(*sender);
	// free(tmp);
}

void	rotate(t_list	**stack)
{
	t_list	*tmp;

	tmp = ps_lstnew((*stack)->content);
	ft_lstadd_back(stack, tmp);
	*stack = dele(*stack);
	// print_list(*stack);
}

void	reverse(t_list	**stack)
{
	t_list	*last;
	t_list	*prev;

	last = *stack;
	while (last->next->next != NULL)
		last = last->next;
	prev = last;
	last = last->next;
	prev->next= NULL;
	last->next = *stack;
	*stack = last;
}
