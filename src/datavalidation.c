/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datavalidation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frafal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:26:34 by frafal            #+#    #+#             */
/*   Updated: 2023/01/16 16:26:54 by frafal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

unsigned int	arrlen(char **tmp)
{
	unsigned int	len;

	len = 0;	
	while (tmp[len])
		len++;
	return (len);
}

long	getvalidint(char *cur)
{
	long	num;
	int		i;
	char	*a;
	char	*tmp;

	num = ft_atoi(cur);
	a = ft_itoa(num);
	i = 0;
	if (ft_issign(cur[i]))
		i++;
	while (cur[i + 1] && cur[i] == '0')
		i++;
	if (cur[0] == '-')
	{
		tmp = ft_strjoin("-", cur + i);
		if (ft_strncmp(a, tmp, ft_strlen(a)))
			num = INTERROR;
		free_null(tmp);
	}	
	else
	{
		if (ft_strncmp(a, cur + i, ft_strlen(a)))
			num = INTERROR;
	}
	free_null(a);
	return (num);
}

int	hasDuplicates(t_data *data)
{
	t_node	*cur;
	t_node	*runner;

	cur = data->a->head;
	while (cur)
	{
		runner = cur->next;
		while (runner)
		{
			if (cur->data == runner->data)
				return (1);
			runner = runner->next;
		}
		cur = cur->next;
	}
	return (0);
}
