#include "minishell.h"

void	ft_pwd(t_cmd *str)
{
	char	*c;

	c = getcwd(NULL, 0);
	if (!c)
	{
		perror("getcwd");
		str->status = BUILTIN;
		return;
	}
	printf("%s\n", c);
	free(c);
}
