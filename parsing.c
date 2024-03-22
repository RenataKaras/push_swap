/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/01 14:51:28 by rkaras        #+#    #+#                 */
/*   Updated: 2024/03/22 15:24:11 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*temp;

	if (stack_a == NULL)
		exit (1);
	current = stack_a;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->number == temp->number)
			{
				ft_printf("Error\n");
				exit (1);
			}
			temp = temp->next;
		}
		current = current->next;
	}
}

void	input_checker(int argc, char *argv[])
{
	int			i;
	long int	temp_num;
	char		**array_num;

	i = 0;
	if (argc == 2)
		array_num = ft_split(argv[1], ' ');
	else
		array_num = argv + 1;
	while (array_num[i])
	{
		temp_num = ft_atol(array_num[i]);
		if ((temp_num < INT_MIN || temp_num > INT_MAX)
			|| is_it_number(array_num[i]) == false)
		{
			ft_printf("Error\n");
			exit (1);
		}
		i++;
	}
	if (argc == 2)
		free_split(array_num);
}

bool	is_it_number(char	*argv)
{
	int			i;

	i = 0;
	if (argv[i] == ' ')
		i++;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
