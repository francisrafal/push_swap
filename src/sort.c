/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:12:54 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 16:35:35 by frafal           ###   ########.fr       */
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
