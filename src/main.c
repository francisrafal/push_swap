/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:12 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 10:33:00 by frafal           ###   ########.fr       */
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

long	index_of(int *arr, int search_key, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == search_key)
			return (i);
		i++;
	}
	return (-1);
}

int	is_sorted(t_data *data)
{
	t_node			*runner;
	unsigned int	i;

	runner = data->a->head;
	i = 0;
	while (i < data->list_size)
	{
		if (data->pre_sort_arr[i] != runner->data)
			return (0);
		runner = runner->next;
		i++;
	}
	return (1);
}

void	sort(t_data *data)
{
	unsigned int	i;
	unsigned int	j;
	t_node			*runner;

	i = 0;
	while (!is_sorted(data))
	{
		runner = data->a->head;
		j = 0;
		while (j < data->list_size)
		{
			if ((index_of(data->pre_sort_arr, data->a->head->data, data->list_size) >> i) & 1)
				ra(data);
			else
				pb(data);
			j++;
		}
		while (data->b->size)
			pa(data);
		i++;
	}
}

int	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (1);
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
}

void	pre_sort(t_data *data)
{
	int				swapped;
	unsigned int	i;

	fill_pre_sort_arr(data);
	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < data->list_size - 1)
		{
			if (data->pre_sort_arr[i] > data->pre_sort_arr[i + 1])
				swapped = swap(data->pre_sort_arr + i, data->pre_sort_arr + i + 1);
			i++;
		}
	}
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
	pre_sort(data);
	sort(data);
	//print_stacks(*(data->a), *(data->b));
	free_data(data);
	return (0);
}

// Sort small
// Sort BIG
// Bei 2: max 1 move
// Bei 3: max 3 moves
// Bei 5: max 12 moves
// Norm check!!!!
