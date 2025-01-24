/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_execve_argv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:12:27 by kaara             #+#    #+#             */
/*   Updated: 2025/01/24 22:40:20 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**store_execve_argv(t_pipex *pipex, char **cmd)
{
	int		execve_argc_i;
	char	**execve_argv;

	execve_argc_i = 0;
	execve_argv = NULL;
	pipex->full_path = validate_cmd_full_path(pipex,
		pipex->cmdv[pipex->cmdc_i][0]);
	if (pipex->full_path == NULL)
		free_exit(pipex, false);
	//
	//
	while (cmd[execve_argc_i] != NULL)
		execve_argc_i++;
	execve_argv = (char **)malloc(sizeof(char *) * execve_argc_i - 1);
	if (execve_argv == NULL)
		free_exit(pipex, false);
	execve_argc_i = 0;
	execve_argv[execve_argc_i] = allocation_and_cpy(pipex->full_path);
	execve_argc_i++;
	while (cmd[execve_argc_i] != NULL)
	{
		execve_argv[execve_argc_i] = allocation_and_cpy(cmd[execve_argc_i]);
		execve_argc_i++;
	}
	execve_argv[execve_argc_i] = NULL;
	return (execve_argv);
}

	////
	// int i = 0;
	// printf("%s\n", pipex->full_path);
	// return (0);
	// while (pipex->execve_argv[i] != NULL)
	// 	printf("%s\n", pipex->execve_argv[i++]);
	////