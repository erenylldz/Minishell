/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:03:32 by eryildiz          #+#    #+#             */
/*   Updated: 2023/11/01 14:49:41 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = -1;
	d = (char *)dest;
	s = (char *)src;
	if (dest == src)
		return (dest);
	while (++i < n)
		d[i] = s[i];
	return (dest);
}
