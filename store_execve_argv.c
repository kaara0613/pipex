/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_execve_argv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:12:27 by kaara             #+#    #+#             */
/*   Updated: 2025/01/23 16:27:19 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**store_execve_argv(t_pipex *pipex, char **cmd)
{
	int		i;
	int		execve_argc;
	char	**execve_argv;

	i = 1;
	execve_argc = 0;
	execve_argv = NULL;
	while (cmd[i] != NULL)
		execve_argc++;
	execve_argv[0] = allocation_and_cpy(pipex->full_path);
	while (cmd[i] != NULL)
	{
		execve_argv[i] = allocation_and_cpy(cmd[i]);
		i++;
	}
	execve_argv[i] = NULL;
	return (execve_argv);
}
