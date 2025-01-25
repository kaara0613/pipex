/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_child_and_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:22:01 by kaara             #+#    #+#             */
/*   Updated: 2025/01/25 18:17:38 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	spawn_child_and_process(t_pipex	*pipex, char *const *envp,int cmdc_i)
{
	pid_t	pid;
	int		exit_status;
	int		exit_status_tmp;

	if (cmdc_i > pipex->cmdc - 1)
		return (0);
	pipex->execve_argv
		= store_execve_argv(pipex, pipex->cmdv[cmdc_i]);
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
	free_execve_argv(pipex->execve_argv);
	close(pipex->pipe_fd[1]);
	exit_status = spawn_child_and_process(pipex, envp, cmdc_i + 1);
	if (cmdc_i == pipex->cmdc - 1){
		waitpid(pid, &exit_status_tmp, 0);
		exit_status = WEXITSTATUS(exit_status_tmp);
	    return (exit_status);
	}
	waitpid(pid, &pipex->exit_status, 0);
	return (exit_status);
}

