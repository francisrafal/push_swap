/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:12 by frafal            #+#    #+#             */
/*   Updated: 2023/01/16 17:19:46 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	push(data->a, pop(data->b), data);
	ft_printf("pa\n");
}

void	pb(t_data *data)
{
	push(data->b, pop(data->a), data);
	ft_printf("pb\n");
}

void	sa(t_data *data)
{
	t_node	*tmp;
	
	if (data->a->size <= 1)
		return ;
	tmp = data->a->head;
	data->a->head = tmp->next;
	tmp->next = data->a->head->next;
	data->a->head->next = tmp;
	ft_printf("sa\n");
}

void	sb(t_data *data)
{
	t_node	*tmp;
	
	if (data->b->size <= 1)
		return ;
	tmp = data->b->head;
	data->b->head = tmp->next;
	tmp->next = data->b->head->next;
	data->b->head->next = tmp;
	ft_printf("sb\n");
}
/*
void	ss(t_data *data)
{
	sa(data);
	sb(data);
	ft_printf("ss\n");
}
*/
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
	pb(data);	
	print_stacks(*(data->a), *(data->b));
	pb(data);	
	print_stacks(*(data->a), *(data->b));
	sa(data);	
	print_stacks(*(data->a), *(data->b));
	sb(data);	
	print_stacks(*(data->a), *(data->b));
/*	ss(data);	
	print_stacks(*(data->a), *(data->b));
*/	free_data(data);
	return (0);
}
