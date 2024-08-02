/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:06:22 by eryildiz          #+#    #+#             */
/*   Updated: 2023/10/25 21:41:40 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			sayac;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	sayac = 0;
	while (sayac < n)
	{
		if (string1[sayac] > string2[sayac])
			return (string1[sayac] - string2[sayac]);
		else if (string1[sayac] < string2[sayac])
			return (string1[sayac] - string2[sayac]);
		sayac++;
	}
	return (0);
}
