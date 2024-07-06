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

void	setio(int infd, int outfd);
void	func(int infd, int outfd, char *argv, char **envp);
void	input_redirect(int *pipe_fd, char *file_name, char *cmd, char **envp);
void	output_redirect(int *pipe_fd, char *file_name, char *cmd, char **envp);

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		fd;
	pid_t	pid;

	if (argc < 5)
		exit(1);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (0);
	}
	pid = fork();
	if (pid == 0)
		input_redirect(pipe_fd, argv[1], argv[2], envp);
	pid = fork();
	if (pid == 0)
		output_redirect(pipe_fd, argv[4], argv[3], envp);
	return (0);
}

void	func(int infd, int outfd, char *argv, char **envp)
{
	char	**cmd_arg;
	char	*cmd_path;

	setio(infd, outfd);
	cmd_arg = cmd_args(argv);
	cmd_path = path(envp, cmd_arg[0]);
	if (execve(cmd_path, cmd_arg, envp) == -1)
	{
		perror(cmd_path);
		exit(1);
	}
	exit(1);
}

void	setio(int infd, int outfd)
{
	dup2(infd, 0);
	dup2(outfd, 1);
}

void	input_redirect(int *pipe_fd, char *file_name, char *cmd, char **envp)
{
	int	fd;

	close(pipe_fd[0]);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror(file_name);
		exit(1);
	}
	func(fd, pipe_fd[1], cmd, envp);
}

void	output_redirect(int *pipe_fd, char *file_name, char *cmd, char **envp)
{
	int	fd;

	close(pipe_fd[1]);
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(file_name);
		exit(1);
	}
	func(pipe_fd[0], fd, cmd, envp);
}
