/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:20:23 by yunseo            #+#    #+#             */
/*   Updated: 2024/05/25 15:20:24 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_env_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			path = ft_strdup(envp[i] + 5);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*tmp_path;

	if (access(cmd, X_OK) != -1)
		return (cmd);
	i = 0;
	cmd_path = ft_strjoin("/", cmd);
	while (paths[i] != NULL)
	{
		tmp_path = ft_strjoin(paths[i], cmd_path);
		if (access(tmp_path, X_OK))
		{
			free(cmd_path);
			return (tmp_path);
		}
		free(tmp_path);
		i++;
	}
	free(cmd_path);
	return (NULL);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i] != NULL)
		free(paths[i++]);
	free(paths);
}

char	*path(char **envp, char *cmd)
{
	char	*env_path;
	char	**paths;
	char	*cmd_path;

	env_path = find_env_path(envp);
	paths = ft_split(env_path, ':');
	cmd_path = find_cmd_path(paths, cmd);
	free_paths(paths);

	return (NULL);
}

int main(int argc, char **argv, char **envp)
{
	char	*path;

	if (argc != 2)
	{
		printf("usage : %s cmd\n", argv[0]);
		return (0);
	}
	path = path(envp, argv[1]);
	printf("%s\n", path);
}
