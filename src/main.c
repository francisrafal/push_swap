/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:12 by frafal            #+#    #+#             */
/*   Updated: 2023/01/13 19:47:56 by frafal           ###   ########.fr       */
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

void	print_stacks(t_stack a, t_stack b)
{
	(void)b;

	ft_printf("--------------------------------------------\n\n");
	while (a.head)
	{
		ft_printf("%d\n", a.head->data);
		a.head = a.head->next;
	}
	ft_printf("_ _\n");
	ft_printf("a b\n\n");
}

int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

void	fill_stack(t_stack *stack, int argc, char **argv)
{
	int		i;
	char	*a;
	char	*cur;

	while (argc > 1)
	{
		cur = argv[argc - 1];
		if (!ft_isdigit(cur[0]) && !ft_issign(cur[0]))
			print_error_exit("Error\n");
		i = ft_atoi(cur);
		a = ft_itoa(i);
		if (cur[0] == '+')
			cur = argv[argc - 1] + 1;
		if (ft_strncmp(a, cur, ft_strlen(a)))
			print_error_exit("Error\n");
		push(stack, i);
		argc--;
	}
// Implement error on duplicates
// Handle Input Strings with Quotes with ft_split (All in one quote or mixed numbers, quotes and non-quotes)
}

int	main(int argc, char **argv)
{
	(void)argv;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		exit(EXIT_FAILURE);
	a = init_stack();
	b = init_stack();
	fill_stack(a, argc, argv);
	print_stacks(*a, *b);
	free_stack(a);
	return (0);
}
