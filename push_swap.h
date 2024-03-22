/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 16:41:44 by rkaras        #+#    #+#                 */
/*   Updated: 2024/03/20 16:53:32 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include "./Libft/ft_printf.h"
# include "./Libft/get_next_line.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

int			main(int argc, char *argv[]);

//utils functions
void		print_list(t_stack *stack_a);
t_stack		*add_node(t_stack *head, int num);
t_stack		*string_to_stack(t_stack *stack_a, char *argv[]);
void		set_index(t_stack *a, int length);
int			find_max_bits(int max_num);

//sorting commands
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

//sorting functions
void		sort_three(t_stack **a);
void		sort_four(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b);
t_stack		*sort(t_stack *a, t_stack *b);
void		radix_sorting(t_stack **a, t_stack **b);

//parsing functions
void		check_duplicates(t_stack *stack_a);
bool		is_it_number(char	*argv);
void		input_checker(int argc, char *argv[]);

//stack utils functions
bool		stack_sorted(t_stack **stack);
t_stack		*find_biggest(t_stack *stack);
int			list_length(t_stack *stack);
t_stack		*find_lowest(t_stack *stack);
t_stack		*find_last_node(t_stack *head);

void		free_stack(t_stack *stack);
void		free_split(char **array);

#endif