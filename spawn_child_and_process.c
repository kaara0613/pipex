/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_child_and_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:22:01 by kaara             #+#    #+#             */
/*   Updated: 2025/01/26 16:15:55 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	spawn_child_and_process(t_pipex	*pipex, char *const *envp, int cmdc_i)
{
	pid_t	pid;
	int		exit_status;
	int		no_use_exit_status;

	if (pipex->cmdc_i >= pipex->cmdc)//再起の終了
		return (0);
	setup_pipe_connection(pipex);
	pid = fork();
	if (pid < 0)
		false_fork(pipex);
	else if (pid == 0)
	{
		pipex->execve_argv
			= store_execve_argv(pipex, pipex->cmdv[cmdc_i]);
		execve(pipex->full_path, pipex->execve_argv, envp);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	close(pipex->pipe_fd[1]);
	// free_execve_argv(pipex->execve_argv);
	exit_status = spawn_child_and_process(pipex, envp, cmdc_i++);
	if (pipex->cmdc_i >= pipex->cmdc)
		waitpid(pid, &exit_status, 0);
	waitpid(pid, &no_use_exit_status, 0);
	return (WEXITSTATUS(exit_status));
}
