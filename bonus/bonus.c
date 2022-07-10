/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:01:27 by acosta-a          #+#    #+#             */
/*   Updated: 2022/07/10 15:50:35 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	in_out_check(int input, int output)
{
	if (input < 0)
		invalid_msg();
	if (output < 0)
		entry_error();
}

void	execute(char *argv, char *envp[])
{
	char	**cmd;
	char	*path;

	cmd_space_substitution(argv);
	cmd = ft_split(argv, ' ');
	cmd_one_substitution (cmd);
	if (cmd[0] == NULL)
	{
		free(cmd[0]);
		free(cmd);
		entry_error();
	}
	path = pathexec(cmd[0], envp);
	if (path == 0)
		command_error(cmd);
	path_error(path, cmd);
	if (execve(path, cmd, envp) == -1)
		entry_error();
}

void	child(char *argv, char *envp[], int *pipefd)
{
	close (pipefd[IN]);
	dup2 (pipefd[OUT], STDOUT);
	execute (argv, envp);
}

void	parent(int output, int *pipefd, pid_t pid)
{
	waitpid(pid, NULL, 0);
	dup2(output, STDOUT);
	close(pipefd[OUT]);
	dup2(pipefd[IN], STDIN);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		input;
	int		output;
	int		pipefd[2];
	pid_t	pid;
	int		i;

	i = 1;
	if (argc >= 5)
	{
		input = openfile(argv[1], IN);
		output = openfile(argv[argc - 1], OUT);
		dup2(input, STDIN);
		in_out_check(input, output);
		while (i++ < (argc - 2))
		{
			pipe(pipefd);
			pid = fork();
			if (pid == 0)
				child(argv[i], envp, pipefd);
			else
				parent(output, pipefd, pid);
		}
		execute(argv[argc - 2], envp);
	}
	entry_error();
}
