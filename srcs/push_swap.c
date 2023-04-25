/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:45:52 by uclement          #+#    #+#             */
/*   Updated: 2023/04/25 19:09:07 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	index_maker(t_list **stack)
{
	t_list	*tmp;
	t_list	*first;
	int		i;

	first = *stack;
	tmp = (*stack)->next;
	while ((*stack) != NULL)
	{		
		i = 1;
		while (tmp != NULL)
		{
			if (((*stack)->content) > (tmp->content))
				i++;
			tmp = tmp->next;
		}
		tmp = first;
		(*stack)->index = i;
		*stack = (*stack)->next;
	}
	*stack = first;
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

void	to_list_a(char *argv, t_list **stack_a)
{
	int				nbr;
	t_list			*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	nbr = ft_atoi(argv);
	new_node->content = nbr;
	new_node->index = 0;
	new_node->next = NULL;
	ft_lstadd_front(stack_a, new_node);
}

void	print_list(t_list *node)
{
	while (node != NULL)
	{
		printf("%d ", node->content);
		node = node->next;
	}
}
void	print_index(t_list *node)
{
	while (node != NULL)
	{
		printf("%d ", node->index);
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_list	*stack_a = NULL;

	i = 1;
	if (argc <= 1)
		error_exit();
	while (i < argc)
	{
		to_list_a(argv[i], &stack_a);
		i++;
	}
	if (parsing(stack_a) == 0)
		error_exit();
	index_maker(&stack_a);
	print_list(stack_a);
	printf("\n");
	print_index(stack_a);
	free_lst(stack_a);
}
