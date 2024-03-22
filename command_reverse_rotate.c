/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_reverse_rotate.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 15:30:44 by rkaras        #+#    #+#                 */
/*   Updated: 2024/02/23 14:09:00 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*new_last_node;

	if (*stack == NULL || stack == NULL)
		exit(1);
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = last_node;
	new_last_node = *stack;
	while (new_last_node->next != last_node)
		new_last_node = new_last_node->next;
	new_last_node->next = NULL;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
