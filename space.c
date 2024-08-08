/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:39:06 by eryildiz          #+#    #+#             */
/*   Updated: 2024/08/08 16:50:16 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_space(t_cmd *str)
{
	str->i = 0;
	str->ncmd_count = 0;
	while (str->ncmd[str->ncmd_count] != NULL )
		str->ncmd_count++;
	str->double_quote = false;
	str->single_quote = false;
	str->command = NULL;
	str->parts_counts = 0;
	str->idx = 0;
	while (str->idx < str->ncmd_count)
	{
		space_quotes()
		split_space()
	}


}
