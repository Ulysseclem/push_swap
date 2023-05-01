/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:37:03 by uclement          #+#    #+#             */
/*   Updated: 2023/05/01 16:19:36 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// void	pair_swap(t_list **head)
// {
// 	t_list	*curr;
// 	t_list	*prev;

// 	if (!head)
// 		return ;
// 	if (head == NULL || (*head)->next == NULL)
// 		return ;
// 	curr = (*head)->next->next;
// 	prev = *head;
// 	*head = (*head)->next;
// 	(*head)->next = prev;
// 	prev->next = curr;
// }

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
	t_list	*prev;
	t_list	*tmp;

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

void	tri(t_list **stack_a, t_list **stack_b, int call)
{
	if (call == 1)
		pair_swap(stack_a);
	else if (call == 2)
		pair_swap(stack_b);
	else if (call == 3)
	{
		pair_swap(stack_b);
		pair_swap(stack_b);
	}
	else if (call == 4)
		push(stack_a, stack_b);
	else if (call == 5)
		push(stack_b, stack_a);
	else if (call == 6)
		rotate(stack_a);
	else if (call == 7)
		rotate(stack_b);
	else if (call == 8)
	{
		rotate(stack_b);
		rotate(stack_b);
	}
	else if (call > 8)
		tri_2(stack_a, stack_b, call);
	print_tri(call,*stack_a ,*stack_b);
}


void	tri_2(t_list **stack_a, t_list **stack_b, int call)
{
	if (call == 9)
		reverse(stack_a);
	else if (call == 10)
		reverse(stack_b);
	else if (call == 11)
	{
		reverse(stack_b);
		reverse(stack_b);
	}
}

void	print_tri(int call, t_list *a, t_list *b)
{	
	static int	count;

	count = count + 0;
	if (call == 1)
		printf("sa\n");
	if (call == 2)
		printf("sb\n");
	if (call == 3)
		printf("ss\n");
	if (call == 4)
		printf("pa\n");
	if (call == 5)
		printf("pb\n");
	if (call == 6)
		printf("ra\n");
	if (call == 7)
		printf("rb\n");
	if (call == 8)
		printf("rr\n");
	if (call == 9)
		printf("rra\n");
	if (call == 10)
		printf("rrb\n");
	if (call == 11)
		printf("rrr\n");
	count++;
	printf("%d\n", count);
	print_list(a, b);

}
