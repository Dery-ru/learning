/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:03:59 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 14:04:04 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	cn;
	size_t			i;

	dst = (unsigned char *)src;
	cn = (unsigned char)c;
	i = 0;
	while (n-- > 0)
	{
		if (*dst == cn)
		{
			return (dst);
		}
		dst++;
	}
	return (0);
}
