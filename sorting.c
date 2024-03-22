/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/21 13:54:17 by rkaras        #+#    #+#                 */
/*   Updated: 2024/03/20 17:13:01 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest_number;

	biggest_number = find_biggest(*a);
	if (*a == biggest_number)
		ra(a);
	else if ((*a)->next == biggest_number)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*lowest_number;

	lowest_number = find_lowest(*a);
	while (*a != lowest_number)
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*lowest_number;

	lowest_number = find_lowest(*a);
	while (*a != lowest_number)
		ra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	radix_sorting(t_stack **a, t_stack **b)
{
	int		i;
	int		j;
	int		max_bits;
	t_stack	*max_num;

	max_num = find_biggest(*a);
	max_bits = find_max_bits(max_num->index);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j <= max_num->index)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b != NULL)
			pa(a, b);
		i++;
	}
}

t_stack	*sort(t_stack *a, t_stack *b)
{
	set_index(a, list_length(a));
	if (list_length(a) <= 3)
		sort_three(&a);
	else if (list_length(a) == 4)
		sort_four(&a, &b);
	else if (list_length(a) == 5)
		sort_five(&a, &b);
	else
		radix_sorting(&a, &b);
	return (a);
}
