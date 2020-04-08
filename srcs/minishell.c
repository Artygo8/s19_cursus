#include "minishell.h"

void banner(void)
{
	size_t i;
	size_t len;
	char *banner;
	char *sign;

	i = 0;
	len = 1;
	sign = "by pmaldagu && agossuin";
	banner = "\n                                                                       ____                         \n      .'. .`.       | |..          | |             ..'''' |         | |            |        |       \n    .'   `   `.     | |  ``..      | |          .''       |_________| |______      |        |       \n  .'           `.   | |      ``..  | |       ..'          |         | |            |        |       \n.'               `. | |          ``| | ....''             |         | |___________ |_______ |_______\n";
	while (banner[len] != '\n')
		len++;
	len -= ft_strlen(sign) + 1;
	write(1, banner, ft_strlen(banner));
	while (i < len)
	{
		write(1, " ", 1);
		i++;
	}
	write(1, sign, ft_strlen(sign));
	write(1, "\n\n\n", 3);
}

int main(int argc, char const *argv[], char **envp)
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		return (12);
	ft_bzero(cmd, sizeof(t_cmd));
	cmd->env = (t_list *)ft_lstenv(envp);
	cmd->vars = ft_lstnew(NULL);
	cmd->fd_output = 1;
	banner();
	ft_prompt("minishell $", cmd);
//	ft_putenv(cmd->env);
//	put_cmd(cmd);
/*	ft_lstclear(&(cmd->args), free); */
	ft_lstclear(&(cmd->env), free);
	ft_lstclear(&(cmd->vars), free);
	free(cmd);
	return (0);
}
