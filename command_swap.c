/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_swap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 14:26:00 by rkaras        #+#    #+#                 */
/*   Updated: 2024/02/23 14:38:34 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*second;

	if (*head == NULL || head == NULL)
		exit(1);
	second = (*head)->next;
	(*head)->next = second->next;
	second->next = *head;
	*head = second;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
