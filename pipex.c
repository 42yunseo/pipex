/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:08:56 by yunseo            #+#    #+#             */
/*   Updated: 2024/05/15 18:22:00 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#define READ 0
#define WRITE 1

int main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	char	*infile_name;
	char	*outfile_name;
	int 	infd;
	int		outfd;
	pid_t	pid;

	if (argc != 5)
	{
		printf("usage : %s infile cmd1 cmd2 outfile\n", argv[0]);
		return (0);
	}
	infile_name = argv[2];
	outfile_name = argv[4];
	if (pipe(fd) == -1)
	{
		perror("pipe"); 
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}
	// parent process
	if (pid > 0)
	{
		close(fd[READ]);
		if (access(infile_name, R_OK) == -1)
		{
			perror("access");
			exit(0);
		}
		else
		{
			infd = open(infile_name, O_RDONLY);
			char *path;
			char **arg;
			arg = (char **)malloc(sizeof(char *) * 2);
			arg[0] = "ls";
			arg[1] = "-l";
			execve("usr/bin/ls", arg, envp);
		}
	}
	else // child process
	{
		close(fd[WRITE]);
		dup2(1, fd[1]);
		printf("This is child!\n");
	}
	exit(0);
}
