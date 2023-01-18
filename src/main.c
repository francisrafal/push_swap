/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:12 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 09:51:30 by frafal           ###   ########.fr       */
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

void	sort(t_data *data)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	digit_checker;
	t_node			*runner;

	i = 0;
	while (i < 32)
	{
		digit_checker = 0;
		runner = data->a->head;
		while (runner)
		{
			digit_checker += ((runner->data ^ 0x80000000) >> i) & 0x1;
			runner = runner->next;
		}
		if (digit_checker != data->list_size && digit_checker != 0)
		{
			j = 0;
			while (j < data->list_size)
			{
				if (((data->a->head->data ^ 0x80000000) >> i) & 0x1)
					ra(data);
				else
					pb(data);
				j++;
			}
			while (data->b->size)
				pa(data);
		}
		i++;
	}
}

void	fill_keys(t_data *data)
{
	t_node			*runner;
	unsigned int	i;

	i = 0;
	runner = data->a->head;
	while (runner)
	{
		runner->key = i;
		runner->key_data = runner->data;
		runner = runner->next;
		i++;
	}
}

int	swap_keys(t_node *a, t_node *b)
{
	unsigned int	tmp_key;
	int				tmp_key_data;

	tmp_key = a->key;
	a->key = b->key;
	b->key = tmp_key;
	tmp_key_data = a->key_data;
	a->key_data = b->key_data;
	b->key_data = tmp_key_data;
	return (1);
}

void	sort_keys(t_data *data)
{
	t_node	*runner;
	int		swapped;

	swapped = 1;
	while (swapped)
	{
		runner = data->a->head;
		swapped = 0;
		while (runner->next)
		{
			if (runner->key_data > runner->next->key_data)
				swapped = swap_keys(runner, runner->next);
			runner = runner->next;
		}
	}
}

void	fill_pre_sort_arr(t_data *data)
{
	t_node			*runner;
	unsigned int	i;

	data->pre_sort_arr = malloc(data->list_size * sizeof (int));
	if (data->pre_sort_arr == NULL)
		print_error_exit("malloc fail\n", data);
	runner = data->a->head;
	i = 0;
	while (runner)
	{
		data->pre_sort_arr[i++] = runner->data;
		runner = runner->next;
	}
	/*
	i = 0;
	while (i < data->list_size)
		ft_printf("%d ", data->pre_sort_arr[i++]);
	ft_printf("\n");
	*/
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		exit(EXIT_FAILURE);
	data = malloc(sizeof (t_data));
	if (data == NULL)
		print_error_exit("malloc fail\n", data);
	*data = (t_data){init_stack(data), init_stack(data), CALLED_DIRECTLY, NULL, 0};
	fill_stack(data, argc, argv);
	if (hasDuplicates(data))
		print_error_exit("Error\n", data);
	fill_pre_sort_arr(data);
//	print_keys(*(data->a), *(data->b));
//	sort_keys(data);
//	print_keys(*(data->a), *(data->b));
//	print_key_data(*(data->a), *(data->b));
//	sort(data);
//	print_keys(*(data->a), *(data->b));
//	print_stacks(*(data->a), *(data->b));
//	print_stacks(*(data->a), *(data->b));
//	print_stacks(*(data->a), *(data->b));
	free_data(data);
	return (0);
}

// IMPORTANT: REPAIR push and pop to also return key and key_data

// Check if already sorted
// Sort small
// Simplify numbers
// Bei 2: max 1 move
// Bei 3: max 3 moves
// Bei 5: max 12 moves
// Bei 100: max 1100 moves / besser < 700
// Bei 500: max 8500 moves / besser < 5500
// Norm check!!!!
