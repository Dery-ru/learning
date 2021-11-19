/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:40:25 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 15:24:13 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_list(int data)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	deletet_list(t_node **list)
{
	while ((*list)->next)
	{
		*list = (*list)->next;
		free((*list)->prev);
		(*list)->prev = NULL;
	}
	free(*list);
	(*list) = NULL;
}

void	pushBack(t_node **list, int data)
{
	t_node	*tmp;
	t_node	*new;

	tmp = create_list(data);
	if ((*list) == NULL)
	{
		(*list) = tmp;
		return ;
	}
	new = (*list);
	while (new->next)
		new = new->next;
	new->next = tmp;
	tmp->prev = new;
}

int	list_len(t_node *list)
{
	int		i;
	t_node	*temp;

	if (!list)
		return (0);
	temp = list;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
