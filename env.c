#include "minishell.h"

// int count_environ(char **environ)
// {
//     int i;

//     i = 0;
//     if(!environ)
//         return (0);
//     while(environ[i])
//         i++;
//     return (i);
// }

// void add_env(char **env, char *str)
// {
// 	char **new;
// 	int env_len;
// 	int i;

// 	env_len = count_environ(env);
// 	new = malloc(sizeof(char *) * count_environ(env) + 2);
// 	i = 0;
// 	while (env[i])
// 	{
// 		new[i] = ft_strdup(env[i]);
// 		i++;
// 	}
// 	new[++env_len] = str;
// 	new[++env_len] = NULL;
// }

void	print_env(char **env, int status)
{
	char	**envr;

	envr = env;
	// add_env(envr, "a=b");
	while (*envr)
	{
		if (status == 1)
			printf("declare -x");
		printf("%s\n", *envr);
		envr++;
	}
}
