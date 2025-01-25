/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_child_and_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:22:01 by kaara             #+#    #+#             */
/*   Updated: 2025/01/25 15:58:40 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	spawn_child_and_process(t_pipex	*pipex, char *const *envp)
{
	pid_t	pid;

	if (pipex->cmdc_i > pipex->cmdc - 1)
		return (pipex->final_exit_status);
	pipex->execve_argv
		= store_execve_argv(pipex, pipex->cmdv[pipex->cmdc_i]);
	setup_pipe_connection(pipex);
	pid = fork();
	if (pid < 0)
		false_fork(pipex);
	else if (pid == 0)
	{
		execve(pipex->full_path, pipex->execve_argv, envp);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	pipex->cmdc_i++;
	free_execve_argv(pipex->execve_argv);
	close(pipex->pipe_fd[1]);
	spawn_child_and_process(pipex, envp);
	waitpid(pid, &pipex->exit_status, 0);
	return (pipex->final_exit_status);
}
