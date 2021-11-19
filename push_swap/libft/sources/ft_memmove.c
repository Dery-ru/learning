/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:04:20 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 14:04:20 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr;
	char	*ptr2;

	if (!dst && !src)
		return (NULL);
	ptr = (char *)dst;
	ptr2 = (char *)src;
	if (ptr2 >= ptr)
		return (ft_memcpy(ptr, ptr2, len));
	while (len--)
		ptr[len] = ptr2[len];
	return (dst);
}
