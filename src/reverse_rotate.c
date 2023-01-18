/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:10:11 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 11:10:32 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
