/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:03:34 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 14:03:35 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list1	*ft_lstlast(t_list1 *lst)
{
	t_list1	*last;

	last = lst;
	if (last)
	{
		while (last->next)
			last = last->next;
		return (last);
	}
	return (NULL);
}
