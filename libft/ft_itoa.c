/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:02:43 by eryildiz          #+#    #+#             */
/*   Updated: 2023/10/25 16:33:00 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_digits(int n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		digits;
	long int	num;

	num = n;
	digits = ft_digits(n);
	if (n <= 0)
	{
		num *= -1;
		digits++;
	}
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	*(str + digits) = 0;
	while (digits--)
	{
		*(str + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
