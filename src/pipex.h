/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 02:26:43 by acosta-a          #+#    #+#             */
/*   Updated: 2022/07/09 03:06:20 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "../libft/libft.h"
#define ERROR 1
#define IN 0
#define OUT 1
#define STDIN 0
#define STDOUT 1
#define STDEER 2

void	entry_error(void);
int		msg_error(char *err);
void	invalid_msg(void);
void	command_error(char **cmd);
int		openfile(char *filename, int mode);
void	*pathexec(char *cmd, char *envp[]);
char	*cmd_space_substitution(char *argv);
char	**cmd_one_substitution(char **cmd);
void	one_substitution_2(char **cmd, int i, int x);
void	execute(char *argv, char *envp[]);
void	path_error(char *path, char **cmd);
void	child(char *argv[], char *envp[], int *pipefd);
void	parent(char *argv[], char *envp[], int *pipefd);
int		main(int argc, char *argv[], char *envp[]);

#endif
