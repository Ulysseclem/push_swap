/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:37:03 by uclement          #+#    #+#             */
/*   Updated: 2023/05/26 16:26:07 by uclement         ###   ########.fr       */
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
	t_list	*end;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	end = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end->next = tmp;
	(*stack)->next = NULL;
	*stack = end;
}

void	reverse(t_list	**stack)
{
	t_list	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	head->next = NULL;
	ft_lstlast(*stack)->next = head;
}
