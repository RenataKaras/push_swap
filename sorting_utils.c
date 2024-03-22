/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/01 14:48:43 by rkaras        #+#    #+#                 */
/*   Updated: 2024/03/20 16:54:26 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while (max_num > 0)
	{
		max_num = max_num >> 1;
		max_bits++;
	}
	return (max_bits);
}

bool	stack_sorted(t_stack **stack)
{
	t_stack	*copy;
	t_stack	*temp;

	if (stack == NULL)
		exit (true);
	copy = *stack;
	while (copy && copy->next)
	{
		temp = copy->next;
		if ((copy)->number > temp->number)
			return (false);
		copy = copy->next;
	}
	return (true);
}

t_stack	*find_biggest(t_stack *stack)
{
	int		biggest;
	t_stack	*biggest_number;

	if (stack == NULL)
		return (NULL);
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->number > biggest)
		{
			biggest = stack->number;
			biggest_number = stack;
		}
		stack = stack->next;
	}
	return (biggest_number);
}

t_stack	*find_lowest(t_stack *stack)
{
	int		lowest;
	t_stack	*lowest_number;

	if (stack == NULL)
		return (NULL);
	lowest = INT_MAX;
	while (stack != NULL)
	{
		if (stack->number < lowest)
		{
			lowest = stack->number;
			lowest_number = stack;
		}
		stack = stack->next;
	}
	return (lowest_number);
}

void	set_index(t_stack *a, int length)
{
	t_stack	*max_number;
	t_stack	*temp;

	while (length > 0)
	{
		length--;
		max_number = NULL;
		temp = a;
		while (temp != NULL)
		{
			if (temp->index == 0 && (max_number == NULL
					|| temp->number > max_number->number))
				max_number = temp;
			temp = temp->next;
		}
		if (max_number != NULL)
			max_number->index = length;
	}
}
