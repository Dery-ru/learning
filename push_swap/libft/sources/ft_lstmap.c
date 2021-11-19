/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:03:40 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 14:03:41 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list1	*ft_lstmap(t_list1 *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list1	*dst;
	t_list1	*elem;

	if (!lst || !f)
		return (NULL);
	dst = NULL;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&elem, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&dst, elem);
	}
	return (dst);
}
