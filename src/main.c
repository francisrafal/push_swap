/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:12 by frafal            #+#    #+#             */
/*   Updated: 2023/01/13 18:21:19 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_exit(char *errmsg)
{
	ft_putstr_fd(errmsg, 2);
	exit(EXIT_FAILURE);
}

t_stack	*push(t_stack *stack, int n)
{
	t_node*	node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		print_error_exit("malloc fail");
	node->data = n;
	node->next = stack->head;
	stack->head = node;
	stack->size = stack->size + 1;
	return (stack);
}

int	pop(t_stack *stack)
{
	int	n;
	t_node	*tmp;

	tmp = stack->head;
	n = tmp->data;
	stack->head = tmp->next;
	free(tmp);
	stack->size = stack->size - 1;
	return (n);
}

void	free_stack(t_stack *stack)
{
	while (stack->head)
		pop(stack);
	free(stack);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof (t_stack));
	if (stack == NULL)
		print_error_exit("malloc fail");
	*stack = (t_stack){NULL, 0};
	return (stack);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_stack	*a;

	if (argc == 1)
		exit(EXIT_FAILURE);
	a = init_stack();
	push(a, 10);
	ft_printf("size: %u\n", a->size);
	ft_printf("data: %d\n", a->head->data);
	push(a, 20);
	ft_printf("size: %u\n", a->size);
	ft_printf("data: %d\n", a->head->data);
	pop(a);
	ft_printf("size: %u\n", a->size);
	ft_printf("data: %d\n", a->head->data);
	push(a, -40);
	ft_printf("size: %u\n", a->size);
	ft_printf("data: %d\n", a->head->data);
	free_stack(a);
	return (0);
}
