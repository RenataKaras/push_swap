/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 13:50:13 by rkaras        #+#    #+#                 */
/*   Updated: 2024/03/22 15:53:53 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	input_checker(argc, argv);
	if (argc == 2)
		stack_a = string_to_stack(stack_a, &argv[1]);
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
			stack_a = add_node(stack_a, ft_atoi(argv[i++]));
	}
	check_duplicates(stack_a);
	if (stack_sorted(&stack_a) == true)
		return (0);
	stack_a = sort(stack_a, stack_b);
	free_stack(stack_a);
	return (0);
}
