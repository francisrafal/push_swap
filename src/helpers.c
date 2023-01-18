/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:24:32 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 11:22:49 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	print_stacks(t_stack a, t_stack b)
{
	int		left;
	int		right;
	ft_printf("--------------------------------------------\n\n");
	while (a.head || b.head)
	{
		if (a.head)
			left = a.head->data;
		if (b.head)
			right = b.head->data;
		if (a.head && b.head)	
			ft_printf("%d\t\t%d\n", left, right);
		else if (a.head)
			ft_printf("%d\t\t\n", left);
		else if (b.head)
			ft_printf("\t\t%d\n", right);
		if (a.head)
			a.head = a.head->next;
		if (b.head)
			b.head = b.head->next;
	}
	ft_printf("_\t\t_\n");
	ft_printf("a\t\tb\n\n");
}
*/

void	free_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i] != NULL)
	{
		free_null(str_arr[i]);
		i++;
	}
	free_null(str_arr);
}

void	free_null(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_data(t_data *data)
{
	free_stack(data->a);
	free_stack(data->b);
	free_null(data->pre_sort_arr);
	free_null(data);
}

void	print_error_exit(char *errmsg, t_data *data)
{
	ft_putstr_fd(errmsg, 2);
	free_data(data);
	exit(EXIT_FAILURE);
}
