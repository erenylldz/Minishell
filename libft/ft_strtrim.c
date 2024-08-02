/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:01:34 by eryildiz          #+#    #+#             */
/*   Updated: 2023/10/26 14:45:54 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	bas;
	size_t	s1_len;
	size_t	cstr_len;
	char	*cstr;

	bas = 0;
	s1_len = ft_strlen(s1);
	while (s1[bas] != '\0' && ft_strchr(set, s1[bas]) != NULL)
		bas++;
	if (bas == s1_len)
		return (ft_strdup(""));
	while (s1_len > 0 && ft_strchr(set, s1[s1_len - 1]) != NULL)
		s1_len--;
	cstr_len = s1_len - bas;
	cstr = (char *)malloc(cstr_len + 1);
	if (cstr == NULL)
		return (NULL);
	ft_memcpy(cstr, s1 + bas, cstr_len);
	cstr[cstr_len] = '\0';
	return (cstr);
}
