/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:47 by frafal            #+#    #+#             */
/*   Updated: 2023/01/16 15:35:05 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "unistd.h"
#include "stdlib.h"

#define INTERROR 0x8000000000000000L

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	struct s_node	*head;
	unsigned int	size;
}					t_stack;

typedef struct		s_data
{
	struct s_stack	*a;
	struct s_stack	*b;
}					t_data;

#endif
