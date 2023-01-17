/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:12 by frafal            #+#    #+#             */
/*   Updated: 2023/01/17 15:27:53 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	push(data->a, pop(data->b), data);
	ft_printf("%s\n", __func__);
}

void	pb(t_data *data)
{
	push(data->b, pop(data->a), data);
	ft_printf("%s\n", __func__);
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
	if (data->called_directly == CALLED_DIRECTLY)
		ft_printf("%s\n", __func__);
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
	if (data->called_directly == CALLED_DIRECTLY)
		ft_printf("%s\n", __func__);
}

void	ss(t_data *data)
{
	data->called_directly = CALLED_WRAPPED;
	sa(data);
	sb(data);
	ft_printf("%s\n", __func__);
	data->called_directly = CALLED_DIRECTLY;
}

void	ra(t_data *data)
{
	t_node	*tmp;
	t_node	*runner;

	if (data->a->size <= 1)
		return ;
	tmp = data->a->head;
	runner = data->a->head;
	data->a->head = data->a->head->next;
	while (runner->next)
		runner = runner->next;
	runner->next = tmp;
	tmp->next = NULL;
	if (data->called_directly == CALLED_DIRECTLY)
		ft_printf("%s\n", __func__);
}

void	rb(t_data *data)
{
	t_node	*tmp;
	t_node	*runner;

	if (data->b->size <= 1)
		return ;
	tmp = data->b->head;
	runner = data->b->head;
	data->b->head = data->b->head->next;
	while (runner->next)
		runner = runner->next;
	runner->next = tmp;
	tmp->next = NULL;
	if (data->called_directly == CALLED_DIRECTLY)
		ft_printf("%s\n", __func__);
}

void	rr(t_data *data)
{
	data->called_directly = CALLED_WRAPPED;
	ra(data);
	rb(data);
	ft_printf("%s\n", __func__);
	data->called_directly = CALLED_DIRECTLY;
}

void	rra(t_data *data)
{
	t_node	*last;
	t_node	*second_to_last;

	if (data->a->size <= 1)
		return ;
	second_to_last = data->a->head;
	while (second_to_last->next->next)
		second_to_last = second_to_last->next;
	last = data->a->head;
	while (last->next)
		last = last->next;
	last->next = data->a->head;
	data->a->head = last;
	second_to_last->next = NULL;
	if (data->called_directly == CALLED_DIRECTLY)
		ft_printf("%s\n", __func__);
}

void	rrb(t_data *data)
{
	t_node	*last;
	t_node	*second_to_last;

	if (data->b->size <= 1)
		return ;
	second_to_last = data->b->head;
	while (second_to_last->next->next)
		second_to_last = second_to_last->next;
	last = data->b->head;
	while (last->next)
		last = last->next;
	last->next = data->b->head;
	data->b->head = last;
	second_to_last->next = NULL;
	if (data->called_directly == CALLED_DIRECTLY)
		ft_printf("%s\n", __func__);
}

void	rrr(t_data *data)
{
	data->called_directly = CALLED_WRAPPED;
	rra(data);
	rrb(data);
	ft_printf("%s\n", __func__);
	data->called_directly = CALLED_DIRECTLY;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		exit(EXIT_FAILURE);
	data = malloc(sizeof (t_data));
	if (data == NULL)
		print_error_exit("malloc fail\n", data);
	*data = (t_data){init_stack(data), init_stack(data), CALLED_DIRECTLY};
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
	ss(data);	
	print_stacks(*(data->a), *(data->b));
	ra(data);	
	print_stacks(*(data->a), *(data->b));
	rb(data);	
	print_stacks(*(data->a), *(data->b));
	rr(data);	
	print_stacks(*(data->a), *(data->b));
	rra(data);	
	print_stacks(*(data->a), *(data->b));
	rrb(data);	
	print_stacks(*(data->a), *(data->b));
	rrr(data);	
	print_stacks(*(data->a), *(data->b));
	free_data(data);
	return (0);
}
