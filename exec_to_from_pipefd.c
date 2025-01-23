/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_to_from_pipefd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:15 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:25:15 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_to_from_pipefd(t_pipex *pipex, char *const *envp)
{
	pipex->full_path = validate_cmd_full_path(pipex,
			pipex->cmdv[pipex->cmdc_i][0]);
	pipex->execve_argv
		= store_execve_argv(pipex, pipex->cmdv[pipex->cmdc_i]);
	if (dup2(pipex->pipe_fd[1], STDIN_FILENO) == -1)
	{
		perror("dup2 return -1.");
		exit(EXIT_FAILURE);
	}
	close(pipex->pipe_fd[1]);
	if (pipe(pipex->pipe_fd) == -1)
	{
		perror("pipe return -1.");
		exit(EXIT_FAILURE);
	}
	if (dup2(STDOUT_FILENO, pipex->pipe_fd[0]) == -1)
	{
		perror("dup2 return -1.");
		exit(EXIT_FAILURE);
	}
	execve(pipex->full_path, pipex->execve_argv, envp);
	perror("execve failed");
	exit(EXIT_FAILURE);
}
