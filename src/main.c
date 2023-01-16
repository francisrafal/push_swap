/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:12 by frafal            #+#    #+#             */
/*   Updated: 2023/01/16 16:26:56 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		exit(EXIT_FAILURE);
	data = malloc(sizeof (t_data));
	if (data == NULL)
		print_error_exit("malloc fail\n", data);
	data->a = init_stack(data);
	data->b = init_stack(data);
	fill_stack(data, argc, argv);
	if (hasDuplicates(data))
		print_error_exit("Error\n", data);
	print_stacks(*(data->a), *(data->b));
	free_data(data);
	return (0);
}
