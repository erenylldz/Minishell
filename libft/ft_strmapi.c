/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:42:55 by eryildiz          #+#    #+#             */
/*   Updated: 2023/10/31 20:09:51 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char c))
{
	unsigned int	len;
	unsigned int	index;
	char			*array;

	index = 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	array = (char *)malloc(len + 1);
	if (array == NULL)
	{
		return (NULL);
	}
	while (s[index] != '\0')
	{
		array[index] = f(index, s[index]);
		index++;
	}
	array[len] = '\0';
	return (array);
}
