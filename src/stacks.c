/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:20:45 by frafal            #+#    #+#             */
/*   Updated: 2023/01/16 16:25:01 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_stack *stack)
{
	int	n;
	t_node	*tmp;

	tmp = stack->head;
	n = tmp->data;
	stack->head = tmp->next;
	free_null(tmp);
	stack->size = stack->size - 1;
	return (n);
}

void	free_stack(t_stack *stack)
{
	while (stack->head)
		pop(stack);
	free_null(stack);
}

t_stack	*push(t_stack *stack, int n, t_data *data)
{
	t_node*	node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		print_error_exit("malloc fail", data);
	node->data = n;
	node->next = stack->head;
	stack->head = node;
	stack->size = stack->size + 1;
	return (stack);
}

t_stack	*init_stack(t_data *data)
{
	t_stack	*stack;

	stack = malloc(sizeof (t_stack));
	if (stack == NULL)
		print_error_exit("malloc fail", data);
	*stack = (t_stack){NULL, 0};
	return (stack);
}

void	fill_stack(t_data *data, int argc, char **argv)
{
	unsigned int	len;
	char			*cur;
	char			**tmp;
	long			validint;

	while (argc > 1)
	{
		cur = argv[argc - 1];
		if (!ft_isdigit(cur[0]) && !ft_issign(cur[0]))
			print_error_exit("Error\n", data);
		tmp = ft_split(cur, ' ');
		len = arrlen(tmp);	
		if (len > 1)
		{
			while (len > 0)
			{
				validint = getvalidint(tmp[len - 1]);
				if (validint == (long)INTERROR)
				{
					free_str_arr(tmp);
					print_error_exit("Error\n", data);
				}
				push(data->a, validint, data);
				len--;
			}
		}
		else
		{
			validint = getvalidint(cur);
			if (validint == (long)INTERROR)
			{
				free_str_arr(tmp);
				print_error_exit("Error\n", data);
			}
			push(data->a, validint, data);
		}
		free_str_arr(tmp);
		argc--;
	}
}
