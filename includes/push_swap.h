/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:16:47 by frafal            #+#    #+#             */
/*   Updated: 2023/01/18 14:11:06 by frafal           ###   ########.fr       */
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
	int				*pre_sort_arr;
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
int				ft_issign(int c);
unsigned int	arrlen(char **tmp);
long			getvalidint(char *cur);
void			free_str_arr(char **str_arr);
void			fill_split(t_data *data, char **tmp, unsigned int len);
void			fill_single(t_data *data, char **tmp, char *cur);
void			fill_stack(t_data *data, int argc, char **argv);
int				has_duplicates(t_data *data);
t_data			*init_data(void);
void			pa(t_data *data);
void			pb(t_data *data);
void			sa(t_data *data);
void			sb(t_data *data);
void			ss(t_data *data);
void			ra(t_data *data);
void			rb(t_data *data);
void			rr(t_data *data);
void			rra(t_data *data);
void			rrb(t_data *data);
void			rrr(t_data *data);
long			index_of(int *arr, int search_key, unsigned int size);
int				is_sorted(t_data *data, unsigned int size);
void			sort(t_data *data);
int				swap(int *a, int *b);
void			fill_pre_sort_arr(t_data *data);
void			pre_sort(t_data *data);

#endif
