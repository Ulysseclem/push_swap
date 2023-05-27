/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:53:31 by uclement          #+#    #+#             */
/*   Updated: 2023/05/27 15:54:32 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		error_exit();
	while (i < argc)
	{
		nbr = ps_atoi(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			error_exit();
		if (i == 1)
			*stack_a = create_stack(nbr);
		else
		{
			new_node = create_stack(nbr);
			ft_lstadd_front(stack_a, new_node);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	to_list_a(argv, argc, &stack_a);
	if (parsing(stack_a) == 0)
	{
		free_lst(&stack_a);
		error_exit();
	}
	if (is_sort(stack_a) == 0)
	{
		free_lst(&stack_a);
		return (0);
	}
	index_maker(&stack_a);
	median_sort(&stack_a, &stack_b);
	while (stack_b)
		iter_index(&stack_a, &stack_b);
	last_sort(&stack_a, &stack_b);
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (0);
}