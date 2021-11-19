/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:41:15 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 13:41:16 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	get_min_val(t_node *list)
{
	int	min;

	min = list->data;
	list = list->next;
	while (list)
	{
		if (list->data < min)
			min = list->data;
		list = list->next;
	}
	return (min);
}

int	get_min_ord(t_node *list)
{
	int	i;

	i = list->order;
	list = list->next;
	while (list)
	{
		if (list->order < i)
			i = list->order;
		list = list->next;
	}
	return (i);
}

void	get_min_max(t_node *list, t_list *stacks)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	max = list->data;
	min = max;
	while (list)
	{
		if (list->data > max)
		{
			max = list->data;
			stacks->max = i;
		}
		if (list->data < min)
		{
			min = list->data;
			stacks->min = i;
		}
		i++;
		list = list->next;
	}
}

int	get_max_val(t_node *list)
{
	int	max;

	max = list->data;
	list = list->next;
	while (list)
	{
		if (list->data > max)
			max = list->data;
		list = list->next;
	}
	return (max);
}
