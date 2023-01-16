/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:12 by frafal            #+#    #+#             */
/*   Updated: 2023/01/16 16:05:00 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_null(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

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

void	free_data(t_data *data)
{
	free_stack(data->a);
	free_stack(data->b);
	free_null(data);
}

void	print_error_exit(char *errmsg, t_data *data)
{
	ft_putstr_fd(errmsg, 2);
	free_data(data);
	exit(EXIT_FAILURE);
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

unsigned int	arrlen(char **tmp)
{
	unsigned int	len;

	len = 0;	
	while (tmp[len])
		len++;
	return (len);
}

long	getvalidint(char *cur)
{
	long	num;
	int		i;
	char	*a;
	char	*tmp;

	num = ft_atoi(cur);
	a = ft_itoa(num);
	i = 0;
	if (ft_issign(cur[i]))
		i++;
	while (cur[i + 1] && cur[i] == '0')
		i++;
	if (cur[0] == '-')
	{
		tmp = ft_strjoin("-", cur + i);
		if (ft_strncmp(a, tmp, ft_strlen(a)))
			num = INTERROR;
		free_null(tmp);
	}	
	else
	{
		if (ft_strncmp(a, cur + i, ft_strlen(a)))
			num = INTERROR;
	}
	free_null(a);
	return (num);
}

void	free_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i] != NULL)
	{
		free_null(str_arr[i]);
		i++;
	}
	free_null(str_arr);
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

int	hasDuplicates(t_data *data)
{
	t_node	*cur;
	t_node	*runner;

	cur = data->a->head;
	while (cur)
	{
		runner = cur->next;
		while (runner)
		{
			if (cur->data == runner->data)
				return (1);
			runner = runner->next;
		}
		cur = cur->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		exit(EXIT_FAILURE);
	data = malloc(sizeof (t_data));
	if (data == NULL)
		print_error_exit("malloc fail\n", data);
	data->a = init_stack(data);
	data->b = init_stack(data);
	fill_stack(data, argc, argv);
	if (hasDuplicates(data))
		print_error_exit("Error\n", data);
	print_stacks(*(data->a), *(data->b));
	free_data(data);
	return (0);
}
