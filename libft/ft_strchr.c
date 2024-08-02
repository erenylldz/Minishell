/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:08:13 by eryildiz          #+#    #+#             */
/*   Updated: 2023/10/26 17:34:24 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	c = (unsigned char)c;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
