/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:12 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 11:13:18 by frafal           ###   ########.fr       */
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
	*data = (t_data){init_stack(data), init_stack(data), CALLED_DIRECTLY, NULL, 0};
	fill_stack(data, argc, argv);
	if (hasDuplicates(data))
		print_error_exit("Error\n", data);
	pre_sort(data);
	sort(data);
	//print_stacks(*(data->a), *(data->b));
	free_data(data);
	return (0);
}

// Sort small
// Sort BIG
// Bei 2: max 1 move
// Bei 3: max 3 moves
// Bei 5: max 12 moves
// Norm check!!!!
