/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:32:36 by eryildiz          #+#    #+#             */
/*   Updated: 2023/11/01 14:45:45 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	a;

	if (dest == src)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	a = 0;
	if (s < d)
	{
		while (len-- > 0)
		{
			d[len] = s[len];
		}
	}
	else
	{
		while (a < len)
		{
			d[a] = s[a];
			a++;
		}
	}
	return (dest);
}
