/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:17:08 by eryildiz          #+#    #+#             */
/*   Updated: 2023/10/25 16:51:00 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	value;
	size_t			a;

	p = (unsigned char *)b;
	value = (unsigned char)c;
	a = 0;
	while (a < len)
	{
		p[a] = value;
		a++;
	}
	return (b);
}
