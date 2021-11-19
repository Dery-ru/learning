/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:02:09 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 14:02:29 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list1 **lst, t_list1 *new)
{
	t_list1	*start;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	start = *lst;
	while (start->next)
		start = start->next;
	start->next = new;
}
