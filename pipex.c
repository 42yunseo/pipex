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

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		fd;
	pid_t	pid;
	int		i;

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
	i = 0;
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror(argv[1]);
			exit(-1);
		}
		func(fd, pipe_fd[1], argv[2], envp);
	}
	i += 2;
	while (i + 3 < argc)
	{
		pid = fork();
		if (pid == 0)
			func(pipe_fd[0], pipe_fd[1], argv[i], envp);
		i++;
		waitpid(pid, 0, 0);
	}
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[1]);
		fd = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror(argv[i + 2]);
			exit(-1);
		}
		func(pipe_fd[0], fd, argv[i + 1], envp);
	}
	return (0);
}

void	func(int infd, int outfd, char *argv, char **envp)
{
	char	**cmd_arg;
	char	*cmd_path;

	ft_printf("FUNC CALL!\n");
	setio(infd, outfd);
	cmd_arg = cmd_args(argv);
	cmd_path = path(envp, cmd_arg[0]);
	if (execve(cmd_path, cmd_arg, envp) == -1)
	{
		perror(cmd_path);
		exit(-1);
	}
	exit(1);
}

void	setio(int infd, int outfd)
{
	dup2(infd, 0);
	dup2(outfd, 1);
}
