/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:41:44 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/13 14:45:39 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_dubs(t_node *list)
{
	t_node	*tmp;

	while (list)
	{
		tmp = list->prev;
		while (tmp)
		{
			if (tmp->data == list->data)
				ft_error();
			tmp = tmp->prev;
		}
		list = list->next;
	}
}

int	order_check(t_node *list)
{
	check_dubs(list);
	while (list->next)
	{
		if (list->data > list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}

int	*list_to_arr(t_node *list)
{
	int	i;
	int	*arr;

	check_dubs(list);
	arr = (int *)malloc(sizeof(int) * list_len(list));
	if (!arr)
		ft_error();
	i = 0;
	while (list)
	{
		arr[i] = list->data;
		list = list->next;
		i++;
	}
	return (arr);
}

void	set_order(t_node **list, int *arr)
{
	int		*temp;
	t_node	*temp_list;
	int		len;
	int		j;

	len = list_len(*list);
	temp = sort_arr(arr, len);
	temp_list = (*list);
	while (temp_list)
	{
		j = 0;
		while (temp[j] || len > j)
		{
			if (temp_list->data == temp[j])
				temp_list->order = (j + 1);
			j++;
		}
		temp_list = temp_list->next;
	}
}

int	*sort_arr(int *arr, int len)
{
	int	i;
	int	temp;
	int	flag;

	temp = 0;
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				flag = 1;
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
			i++;
		}
	}
	return (arr);
}
