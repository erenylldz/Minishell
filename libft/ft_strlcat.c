/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:45:05 by eryildiz          #+#    #+#             */
/*   Updated: 2023/10/25 18:40:26 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned long				a;
	unsigned int				destlen;
	unsigned int				srclen;

	a = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size == 0 || size <= destlen)
		return (srclen + size);
	while (src[a] != '\0' && a < size - destlen - 1)
	{
		dest[destlen + a] = src[a];
		a++;
	}
	dest[destlen + a] = '\0';
	return (destlen + srclen);
}
