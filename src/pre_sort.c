/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:11:49 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 11:12:41 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
