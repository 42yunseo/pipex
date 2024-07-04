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

void	func(int *pipe_fd, int flag, char *argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		fd;
	pid_t	pid;
	int		i;
	int		flag;
	char	**cmd_arg;
	char	*cmd_path;

	if (argc < 5)
	{
		ft_printf("usage : %s infile cmd1 cmd2 ... cmdn outfile\n", argv[0]);
		return (0);
	}
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (0);
	}
	flag = 0;

	pid = fork();
	if (pid == 0)
		{
		close(pipe_fd[flag]);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror(argv[1]);
			exit(-1);
		}
		dup2(fd, 0);
		dup2(pipe_fd[1 - flag], 1);
		cmd_arg = cmd_args(argv[2]);
		cmd_path = path(envp, cmd_arg[0]);
		if (execve(cmd_path, cmd_arg, envp) == -1)
		{
			perror(cmd_path);
			exit(-1);
		}
	}

	flag = 1 - flag;
	i = 2;

	while (argv[i + 3] != NULL)
	{
		pid = fork();
		if (pid == 0)
			func(pipe_fd, flag, argv[i], envp);
		i++;
		flag = 1 - flag;
	}

	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[1 - flag]);
		fd = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror(argv[i + 2]);
			exit(-1);
		}
		dup2(pipe_fd[flag], 0);
		dup2(fd, 1);
		cmd_arg = cmd_args(argv[i + 1]);
		cmd_path = path(envp, cmd_arg[0]);
		if (execve(cmd_path, cmd_arg, envp) == -1)
		{
			perror(cmd_path);
			exit(-1);
		}
	}
	return (0);
}

void	func(int *pipe_fd, int flag, char *argv, char **envp)
{
	char	**cmd_arg;
	char	*cmd_path;

	dup2(pipe_fd[flag], 0);
	dup2(pipe_fd[1 - flag], 1);
	cmd_arg = cmd_args(argv);
	cmd_path = path(envp, cmd_arg[0]);
	if (execve(cmd_path, cmd_arg, envp) == -1)
	{
		perror(cmd_path);
		exit(-1);
	}
}
