/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 16:47:29 by rkaras        #+#    #+#                 */
/*   Updated: 2024/03/20 16:54:57 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*string_to_stack(t_stack *stack_a, char *argv[])
{
	int		num;
	char	**array;
	int		i;

	i = 0;
	array = ft_split(*argv, ' ');
	i = 0;
	while (array[i] != NULL)
	{
		num = ft_atoi(array[i]);
		stack_a = add_node(stack_a, num);
		i++;
	}
	free_split(array);
	return (stack_a);
}

t_stack	*find_last_node(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

t_stack	*add_node(t_stack *head, int num)
{
	t_stack	*node;
	t_stack	*last_node;

	node = (t_stack *)malloc(1 * sizeof(t_stack));
	if (!node)
	{
		free_stack(node);
		return (NULL);
	}
	node->number = num;
	node->index = 0;
	node->next = NULL;
	if (head == NULL)
	{
		head = node;
		return (head);
	}
	else
	{
		last_node = find_last_node(head);
		last_node->next = node;
	}
	return (head);
}

int	list_length(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
