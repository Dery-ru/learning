/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duo_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:40:52 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 13:40:53 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	duo_swap(t_node **list, t_node **dest, char *s)
{
	if (*list == NULL || (*list)->next == NULL)
		return ;
	if (*dest == NULL || (*dest == NULL))
		return ;
	swap (list, 0);
	swap (dest, s);
}

void	duo_rotate(t_node **list, t_node **dest, char *s)
{
	if (*list == NULL || (*list)->next == NULL)
		return ;
	if (*dest == NULL || (*dest == NULL))
		return ;
	rotate (list, 0);
	rotate (dest, s);
}

void	duo_reverse_rotate(t_node **list, t_node **dest, char *s)
{
	if (*list == NULL || (*list)->next == NULL)
		return ;
	if (*dest == NULL || (*dest == NULL))
		return ;
	reverse_rotate (list, 0);
	reverse_rotate (dest, s);
}
