/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:58:13 by eryildiz          #+#    #+#             */
/*   Updated: 2023/10/25 18:01:45 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t element, size_t element_size)
{
	size_t	carpim;
	char	*ptr;

	carpim = element * element_size;
	ptr = malloc(carpim);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, carpim);
	}
	return (ptr);
}
