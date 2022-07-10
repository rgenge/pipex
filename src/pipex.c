/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:01:27 by acosta-a          #+#    #+#             */
/*   Updated: 2022/07/09 02:02:48 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	child(char *argv[], char *envp[], int *pipefd)
{
	dup2 (pipefd[OUT], STDOUT);
	close (pipefd[IN]);
	execute (argv[2], envp);
}

void	parent(char *argv[], char *envp[], int *pipefd)
{
	dup2(pipefd[IN], STDIN);
	close(pipefd[OUT]);
	execute(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		input;
	int		output;
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if (argc == 5)
	{
		input = openfile(argv[1], IN);
		output = openfile(argv[4], OUT);
		dup2(input, STDIN);
		dup2(output, STDOUT);
		pipe (pipefd);
		if (input < 0)
			invalid_msg();
		if (output < 0)
			entry_error();
		pid = fork();
		if (pid == 0)
			child(argv, envp, pipefd);
		waitpid(pid, &status, 0);
		parent(argv, envp, pipefd);
	}
	else
		entry_error();
}
