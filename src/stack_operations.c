/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:20:45 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 12:55:21 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_stack *stack)
{
	int		n;
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
	t_node	*node;

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
