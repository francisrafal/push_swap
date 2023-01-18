/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:12:54 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 15:12:06 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_data *data, unsigned int size)
{
	t_node			*runner;
	unsigned int	i;

	runner = data->a->head;
	i = 0;
	while (i < size)
	{
		if (data->pre_sort_arr[i] != runner->data)
			return (0);
		runner = runner->next;
		i++;
	}
	return (1);
}

void	sort_3(t_data *data)
{
	int				arr[3];
	t_node			*runner;
	unsigned int	i;

	while (!is_sorted(data, 3))
	{
		runner = data->a->head;
		i = 0;
		while (runner)
		{
			arr[i] = index_of(data->pre_sort_arr, runner->data,
					data->list_size);
			runner = runner->next;
			i++;
		}
		if (arr[0] == 1 && arr[1] == 2 && arr[2] == 0)
			rra(data);
		else if (arr[0] == 2 && arr[1] == 0 && arr[2] == 1)
			ra(data);
		else
			sa(data);
	}
}

void	sort_5(t_data *data)
{
	int				arr[5];
	t_node			*runner;
	unsigned int	i;
	int				three_sorted;

	three_sorted = 0;
	while (!is_sorted(data, data->list_size))
	{
		runner = data->a->head;
		i = 0;
		while (runner)
		{
			arr[i] = index_of(data->pre_sort_arr, runner->data,
					data->list_size);
			runner = runner->next;
			i++;
		}
		if (!three_sorted)
		{
			i = 0;
			while (i < data->list_size)
			{
				if (arr[i] == 3 || arr[i] == 4)
					pb(data);
				else
					ra(data);
				i++;
			}
			sort_3(data);
			three_sorted = 1;
			i = 3;
			while (i < data->list_size)
			{
				pa(data);
				i++;
			}
		}
		else
		{
			if (data->list_size == 5 && arr[0] > arr[1])
				sa(data);
			i = 3;
			while (i < data->list_size)
			{
				ra(data);
				i++;
			}
		}
	}
}

void	sort_big(t_data *data)
{
	unsigned int	i;
	unsigned int	j;
	int				index;

	i = 0;
	while (!is_sorted(data, data->list_size))
	{
		j = 0;
		while (j < data->list_size)
		{
			index = index_of(data->pre_sort_arr,
					data->a->head->data, data->list_size);
			if ((index >> i) & 1)
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

void	sort_2(t_data *data)
{
	if (data->a->head->data > data->a->head->next->data)
		sa(data);
}

void	sort(t_data *data)
{
	if (data->list_size == 2)
		sort_2(data);
	else if (data->list_size == 3)
		sort_3(data);
	else if (data->list_size <= 5)
		sort_5(data);
	else
		sort_big(data);
}
