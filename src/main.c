/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:12 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 11:29:42 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	if (data == NULL)
		print_error_exit("malloc fail\n", data);
	data->a = init_stack(data);
	data->b = init_stack(data);
	data->called_directly = CALLED_DIRECTLY;
	data->pre_sort_arr = NULL;
	data->list_size = 0;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		exit(EXIT_FAILURE);
	data = init_data();
	fill_stack(data, argc, argv);
	if (has_duplicates(data))
		print_error_exit("Error\n", data);
	pre_sort(data);
	sort(data);
	free_data(data);
	return (0);
}

// Sort small
// Sort BIG
// Bei 2: max 1 move
// Bei 3: max 3 moves
// Bei 5: max 12 moves
// Norm check!!!!
