/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:03:19 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 14:03:22 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list1 **lst, void (*del)(void*))
{
	t_list1	*l;
	t_list1	*last_save;

	l = *lst;
	while (l)
	{
		last_save = l->next;
		if (del)
			del(l->content);
		free(l);
		l = last_save;
	}
	*lst = NULL;
}
