/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:06:49 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 11:10:01 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
