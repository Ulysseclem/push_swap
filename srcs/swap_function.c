/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:37:03 by uclement          #+#    #+#             */
/*   Updated: 2023/05/11 15:59:14 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	pair_swap(t_list **stack)
{
	t_list	*prev;
	t_list	*current;
	t_list	*last;

	prev = NULL;
	current = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (current->next->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	last = current->next;
	current->next = NULL;
	last->next = current;
	if (prev != NULL)
		prev->next = last;
	else
		*stack = last;
}

void	push(t_list **receiver, t_list **sender)
{
	t_list	*curr;

	if (*sender == NULL)
		return ;
	if ((*sender)->next == NULL)
	{
		if (*receiver == NULL)
			*receiver = *sender;
		else
		{
			curr = ft_lstlast(*receiver);
			curr->next = *sender;
		}
		*sender = NULL;
		return ;
	}
	curr = *sender;
	push_suite(receiver, curr);
}

void	push_suite(t_list **receiver, t_list *curr)
{
	t_list	*prev;
	t_list	*tmp;

	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	if (*receiver == NULL)
		*receiver = curr;
	else
	{
		tmp = ft_lstlast(*receiver);
		tmp->next = curr;
	}
	prev->next = NULL;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	current = ft_lstlast(*stack);
	tmp = ps_lstnew(current->content);
	tmp->index = current->index;
	tmp->next = NULL;
	ft_lstadd_front(stack, tmp);
	*stack = dele(*stack);
}

void	reverse(t_list	**stack)
{
	t_list	*tmp;
	t_list	*current;

	tmp = ps_lstnew((*stack)->content);
	tmp->index = (*stack)->index;
	tmp->next = NULL;
	current = ft_lstlast(*stack);
	current->next = tmp;
	*stack = (*stack)->next;
}
