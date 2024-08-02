/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:28:49 by eryildiz          #+#    #+#             */
/*   Updated: 2023/10/25 16:35:12 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	int				s1_len;
	int				s2_len;
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof (*s1) * (s1_len + s2_len +1));
	if (!str)
		return (NULL);
	while (s1[a])
	{
		str[b++] = s1[a++];
	}
	a = 0;
	while (s2[a])
	{
		str[b++] = s2[a++];
	}
	str[b] = 0;
	return (str);
}
