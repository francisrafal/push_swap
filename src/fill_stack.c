/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:54:50 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 12:55:15 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_split(t_data *data, char **tmp, unsigned int len)
{
	long	validint;

	while (len > 0)
	{
		validint = getvalidint(tmp[len - 1]);
		if (validint == (long)INTERROR)
		{
			free_str_arr(tmp);
			print_error_exit("Error\n", data);
		}
		push(data->a, validint, data);
		len--;
	}
}

void	fill_single(t_data *data, char **tmp, char *cur)
{
	long	validint;

	validint = getvalidint(cur);
	if (validint == (long)INTERROR)
	{
		free_str_arr(tmp);
		print_error_exit("Error\n", data);
	}
	push(data->a, validint, data);
}

void	fill_stack(t_data *data, int argc, char **argv)
{
	unsigned int	len;
	char			*cur;
	char			**tmp;

	while (argc > 1)
	{
		cur = argv[argc - 1];
		if (!ft_isdigit(cur[0]) && !ft_issign(cur[0]))
			print_error_exit("Error\n", data);
		tmp = ft_split(cur, ' ');
		len = arrlen(tmp);
		if (len > 1)
			fill_split(data, tmp, len);
		else
			fill_single(data, tmp, cur);
		free_str_arr(tmp);
		argc--;
	}
	data->list_size = data->a->size;
}
