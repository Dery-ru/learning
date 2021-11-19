/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:41:10 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 13:41:11 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_node **list, char *s)
{
	t_node	*ptr;

	ptr = (*list)->next;
	(*list)->next = ptr->next;
	if ((*list)->next)
		(*list)->next->prev = *list;
	(*list)->prev = ptr;
	ptr->prev = NULL;
	ptr->next = *list;
	*list = ptr;
	write(1, s, 3);
}

void	rotate(t_node **list, char *s)
{
	t_node	*ptr;

	ptr = *list;
	if (!(*list)->prev)
		while (ptr->next)
			ptr = ptr->next;
	ptr->next = *list;
	(*list)->prev = ptr;
	ptr = (*list)->next;
	(*list)->next->prev = NULL;
	(*list)->next = NULL;
	*list = ptr;
	write(1, s, 3);
}

void	push(t_node **list, t_node **dest, char *s)
{
	t_node	*ptr;

	ptr = *list;
	*list = (*list)->next;
	if (*list)
		(*list)->prev = NULL;
	if (!(*dest))
	{
		*dest = ptr;
		(*dest)->next = NULL;
		(*dest)->prev = NULL;
		write(1, s, 3);
		return ;
	}
	(*dest)->prev = ptr;
	(*dest)->prev->next = *dest;
	*dest = (*dest)->prev;
	(*dest)->prev = NULL;
	write(1, s, 3);
}

void	reverse_rotate(t_node **list, char *s)
{
	t_node	*ptr;

	ptr = *list;
	if (!(*list)->prev)
		while (ptr->next)
			ptr = ptr->next;
	(*list)->prev = ptr;
	ptr->next = (*list);
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	*list = ptr;
	write(1, s, 4);
}
