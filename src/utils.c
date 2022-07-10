/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:01:27 by acosta-a          #+#    #+#             */
/*   Updated: 2022/07/09 00:20:50 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	entry_error(void)
{
	ft_putstr_fd("Input must be: ./pipex [file1] [cmd1] [cmd2] [file2]\n", 2);
	exit(ERROR);
}

void	invalid_msg(void)
{
	ft_putstr_fd("Permission denied\n", 2);
	exit(0);
}

void	command_error(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	perror("Command not found");
	exit(127);
}

int	msg_error(char *err)
{
	perror(err);
	exit(ERROR);
}

int	openfile(char *filename, int mode)
{
	if (mode == IN)
	{
		if (access(filename, F_OK))
		{
			perror(" ");
			exit(ERROR);
		}
		return (open(filename, O_RDONLY, 0644));
	}
	else
		return (open(filename, O_TRUNC | O_CREAT | O_RDWR, 0644));
}
