/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:32:52 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 16:34:21 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_arr(t_data *data, int *arr)
{
	unsigned int	i;
	t_node			*runner;

	runner = data->a->head;
	i = 0;
	while (runner)
	{
		arr[i] = index_of(data->pre_sort_arr, runner->data,
				data->list_size);
		runner = runner->next;
		i++;
	}
}

void	sort_2(t_data *data)
{
	if (data->a->head->data > data->a->head->next->data)
		sa(data);
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

void	sort_3_in_5(t_data *data, int *arr)
{
	unsigned int	i;

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
	i = 3;
	while (i < data->list_size)
	{
		pa(data);
		i++;
	}
}

void	sort_5(t_data *data)
{
	int				arr[5];
	unsigned int	i;
	int				three_sorted;

	three_sorted = 0;
	while (!is_sorted(data, data->list_size))
	{
		fill_arr(data, arr);
		if (!three_sorted)
		{
			sort_3_in_5(data, arr);
			three_sorted = 1;
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
