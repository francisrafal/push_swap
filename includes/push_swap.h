/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:47 by frafal            #+#    #+#             */
/*   Updated: 2023/01/17 19:27:57 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "unistd.h"
#include "stdlib.h"

#define INTERROR 0x8000000000000000L
#define	CALLED_DIRECTLY	1
#define	CALLED_WRAPPED	0

typedef struct		s_node
{
	int				data;
	unsigned int	key;
	int				key_data;
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
	int				called_directly;
	unsigned int	list_size;
}					t_data;

void			free_null(void *ptr);
int				pop(t_stack *stack);
void			free_stack(t_stack *stack);
void			free_data(t_data *data);
void			print_error_exit(char *errmsg, t_data *data);
t_stack			*push(t_stack *stack, int n, t_data *data);
t_stack			*init_stack(t_data *data);
void			print_stacks(t_stack a, t_stack b);
void			print_key_data(t_stack a, t_stack b);
void			print_keys(t_stack a, t_stack b);
int				ft_issign(int c);
unsigned int	arrlen(char **tmp);
long			getvalidint(char *cur);
void			free_str_arr(char **str_arr);
void			fill_stack(t_data *data, int argc, char **argv);
int				hasDuplicates(t_data *data);

#endif
