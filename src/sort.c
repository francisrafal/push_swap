/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:12:54 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 11:31:46 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int				index;

	i = 0;
	while (!is_sorted(data))
	{
		runner = data->a->head;
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
