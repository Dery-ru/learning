/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:05:59 by rhoke             #+#    #+#             */
/*   Updated: 2021/10/09 14:06:00 by rhoke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	if (j > size)
		j = size;
	if (j == size || size == 0)
		return (i + j);
	if (i < (size - j))
		ft_memcpy(dst + j, src, (i + 1));
	else
	{
		ft_memcpy(dst + j, src, (size - j - 1));
		dst[size - 1] = '\0';
	}
	return (i + j);
}
