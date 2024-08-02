/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:22:55 by eryildiz          #+#    #+#             */
/*   Updated: 2023/10/25 16:36:18 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		a;
	char	*str;

	a = 0;
	str = 0;
	while (s[a])
	{
		if (s[a] == (unsigned char)c)
			str = (char *)(s + a);
		a++;
	}
	if (s[a] == (unsigned char)c)
		str = (char *)(s + a);
	return (str);
}
