/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:15:54 by eryildiz          #+#    #+#             */
/*   Updated: 2023/10/25 16:31:19 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;

	negative = 1;
	i = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str - 48);
		++str;
	}
	return (i * negative);
}
