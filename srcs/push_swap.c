/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:45:52 by uclement          #+#    #+#             */
/*   Updated: 2023/04/24 16:20:36 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"


void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit (0);
}
	// write(1,"ping\n", 5);


// foutre tous les elements dans la pile A  -----DONE

// creer toutes les fonctions

// trier

void	to_list_a(char *argv, t_list **stack_a)
{
	int				nbr;
	t_list			*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	nbr = ft_atoi(argv);
	new_node->content = nbr;
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

int	main(int argc, char **argv)
{
	int	i;
	t_list	*stack_a = NULL;
	// t_list	*stack_b = NULL;

	i = 1;
	if (argc <= 1)
		error_exit();
	while (i < argc)
	{
		to_list_a(argv[i], &stack_a);
		i++;
	}
	printf("\n Linked list before calling pairWiseSwap() ");
	print_list(stack_a);

	// printf("\n rotate ----------");
	// rotate(&stack_a);
	// print_list(stack_a);

	// printf("\n pair_swap ----------");
	// pair_swap(&stack_a);
	// print_list(stack_a);

	// printf("\n push ----------");
	// push(&stack_b, &stack_a);
	// printf("\n a :");
	// print_list(stack_a);
	// printf("\n b :");
	// print_list(stack_b);

	printf("\n reverse ----------");
	reverse(&stack_a);
	print_list(stack_a);

	free_lst(stack_a);
	// free_lst(stack_b);

}
