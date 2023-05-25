/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:45:52 by uclement          #+#    #+#             */
/*   Updated: 2023/05/24 15:10:25 by ulysse           ###   ########.fr       */
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

void	to_list_a(char **argv, int argc, t_list **stack_a)
{
	long long int	nbr;
	t_list			*new_node;
	int				i;

	i = 1;
	if (argc <= 2)
	{
		free(*stack_a);
		error_exit();
	}
	while (i < argc)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return ;
		nbr = ps_atoi(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
		{
			error_exit();
		}
		new_node->content = nbr;
		new_node->index = 0;
		new_node->next = NULL;
		ft_lstadd_front(stack_a, new_node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = malloc(sizeof(t_list));
	if (!stack_a)
		return (0);
	stack_a->next = NULL;
	stack_a->content = 0;
	stack_a->index = 0;
	to_list_a(argv, argc, &stack_a);
	if (parsing(stack_a) == 0)
	{
		free_lst(&stack_a);
		error_exit();
	}
	free_lst(&stack_a);
	return(0);
	if (is_sort(stack_a) == 0)
	{
		free_lst(&stack_a);
		return (0);
	}
	index_maker(&stack_a);

	stack_b = malloc(sizeof(t_list));
	if (!stack_b)
		return (0);
	stack_b->index = 0;
	stack_b->content = 0;
	stack_b->next = NULL;
	median_sort(&stack_a, &stack_b);
	free_lst(&stack_a);
	free_lst(&stack_b);
	return(0);
	while (stack_b)
		iter_index(&stack_a, &stack_b);
	last_sort(&stack_a, &stack_b);
	free_lst(&stack_a);
	free_lst(&stack_b);
}
