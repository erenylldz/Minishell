/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:14:37 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/01 18:50:18 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	srclen;
	unsigned int	a;

	a = 0;
	srclen = 0;
	while (src[srclen] != '\0')
	{
		srclen++;
	}
	if (size != 0)
	{
		while (src[a] != '\0' && a < size - 1)
		{
			dest[a] = src[a];
			a++;
		}
		dest[a] = '\0';
	}
	return (srclen);
}
