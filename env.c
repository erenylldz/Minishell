/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryildiz <eryildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:20:21 by kgulfida          #+#    #+#             */
/*   Updated: 2024/08/24 18:36:10 by eryildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Yeni bir ortam değişkeni düğümü oluşturma fonksiyonu
t_env	*create_env_node(char *key, char *value)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

// Bağlı listeye bir düğüm ekleme fonksiyonu
void	add_env_node(t_env **env_list, char *key, char *value)
{
	t_env	*new_node;
	t_env	*temp;

	new_node = create_env_node(key, value);
	temp = *env_list;
	if (!new_node)
		return ;
	if (!*env_list)
	{
		*env_list = new_node;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

// Ortam değişkenlerini ayırma ve listeye ekleme fonksiyonu
void	parse_env(char **envp, t_env **env_list)
{
	int		i;
	char	*key;
	char	*value;
	char	*delimiter;

	i = 0;
	while (envp[i])
	{
		key = NULL;
		value = NULL;
		delimiter = ft_strchr(envp[i], '=');
		if (delimiter)
		{
			key = ft_strndup(envp[i], delimiter - envp[i]);
			// '=' öncesi kısmı al
			value = ft_strdup(delimiter + 1);
			// '=' sonrası kısmı al
			add_env_node(env_list, key, value);
		}
		i++;
	}
}

// Bağlı listeyi yazdırma fonksiyonu (debug için)
void	print_env_list(t_env *env_list)
{
	while (env_list)
	{
		printf("%s=%s\n", env_list->key, env_list->value);
		env_list = env_list->next;
	}
}

char	*get_env_value(t_env *env_list, char *key)
{
	if (!env_list)
		return (NULL);
	while (env_list != NULL)
	{
		// printf("***%s\n" , key);
		// printf("---%s\n", env_list->key);
		if (ft_strcmp(env_list->key, key) == 0)
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}
// Belleği serbest bırakma fonksiyonu
void	free_env_list(t_env *env_list)
{
	t_env	*temp;

	while (env_list)
	{
		temp = env_list;
		env_list = env_list->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

// Env de arama yapıp key value eşlemesi yapacak fonksiyon
