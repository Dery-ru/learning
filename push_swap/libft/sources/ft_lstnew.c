/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:03:45 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 14:03:46 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list1	*ft_lstnew(void *content)
{
	t_list1	*lst;

	lst = (t_list1 *)malloc(sizeof(t_list1));
	if (!lst)
		return (0);
	lst->content = (void *)content;
	lst->next = NULL;
	return (lst);
}
