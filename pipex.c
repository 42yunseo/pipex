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

void	exec(int infd, int outfd, char *cmd, char **envp);
void	input_redirect(int *pipe_fd, char *file_name, char *cmd, char **envp);
void	output_redirect(int *pipe_fd, char *file_name, char *cmd, char **envp);

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		status;

	if (argc < 5)
		exit(EXIT_FAILURE);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	input_redirect(pipe_fd, argv[1], argv[2], envp);
	output_redirect(pipe_fd, argv[4], argv[3], envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(&status);
	wait(&status);
	exit(status);
}

void	exec(int infd, int outfd, char *cmd, char **envp)
{
	char	**cmd_arg;
	char	*cmd_path;

	dup2(infd, 0);
	dup2(outfd, 1);
	cmd_arg = cmd_args(cmd);
	cmd_path = path(envp, cmd_arg[0]);
	if (cmd_path == NULL)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(cmd, 2);
		free_args(cmd_arg);
		exit(127);
	}
	if (execve(cmd_path, cmd_arg, envp) == -1)
		exit(EXIT_FAILURE);
}

void	input_redirect(int *pipe_fd, char *file_name, char *cmd, char **envp)
{
	pid_t	pid;
	int		fd;

	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		fd = open(file_name, O_RDONLY);
		if (fd == -1)
		{
			perror(file_name);
			exit(EXIT_FAILURE);
		}
		exec(fd, pipe_fd[1], cmd, envp);
	}
}

void	output_redirect(int *pipe_fd, char *file_name, char *cmd, char **envp)
{
	pid_t	pid;
	int		fd;

	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[1]);
		fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror(file_name);
			exit(EXIT_FAILURE);
		}
		exec(pipe_fd[0], fd, cmd, envp);
	}
}
