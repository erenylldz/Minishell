/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:35:43 by eryildiz          #+#    #+#             */
/*   Updated: 2024/09/01 14:59:39 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	len;

	len = ft_strnlen(s, n);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len);
	dup[len] = '\0';
	return (dup);
}

size_t	ft_strnlen(const char *src, size_t i)
{
	size_t	idx;

	idx = 0;
	while (src[idx] && idx < i)
	{
		idx++;
	}
	return (idx);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	print_cmd(t_cmd *str)// silinecek fonksiyon
{
	int z;
	int y;
	z = 0;
	while (str->command[z] != NULL)
	{
		y = 0;
		printf("Command %d:\n", z);
		while (str->command[z][y] != NULL)
		{
			printf("  Arg %d: %s\n", y, str->command[z][y]);
			y++;
		}
		z++;
	}
}
