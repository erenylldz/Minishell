/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:18:15 by eryildiz          #+#    #+#             */
/*   Updated: 2023/11/01 14:53:38 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			*string;
	size_t					a;
	unsigned char			value;

	a = 0;
	value = (unsigned char)c;
	string = (unsigned char *)s;
	if (n > 0)
	{
		while (a < n)
		{
			if (string[a] == value)
				return (string + a);
			a++;
		}
	}
	return (0);
}
