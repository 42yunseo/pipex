#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		fd;
	pid_t	pid;
	char	**cmd_arg;
	char	*cmd_path;

	if (argc != 5)
	{
		printf("usage : %s infile cmd1 cmd2 outfile\n", argv[0]);
		return (0);
	}
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (0);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		exit(-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}




	if (pid != 0)
	{
		close(pipe_fd[0]);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror(argv[1]);
			exit(-1);
		}
		dup2(fd, 0);
		dup2(pipe_fd[1], 1);
		cmd_arg = cmd_args(argv[2]);
		cmd_path = path(envp, cmd_arg[0]);
		if (execve(cmd_path, cmd_arg, envp) == -1)
		{
			perror(cmd_path);
			exit(-1);
		}
		wait(&pid);
	}
	else
	{
		close(pipe_fd[1]);
		fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror(argv[4]);
			exit(-1);
		}
		dup2(pipe_fd[0], 0);
		dup2(fd, 1);
		cmd_arg = cmd_args(argv[3]);
		cmd_path = path(envp, cmd_arg[0]);
		if (execve(cmd_path, cmd_arg, envp) == -1)
		{
			perror(cmd_path);
			exit(-1);
		}
	}
	return (0);
}