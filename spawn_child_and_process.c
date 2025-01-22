/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_child_and_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:22:01 by kaara             #+#    #+#             */
/*   Updated: 2025/01/22 16:49:12 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	spawn_child_and_process(t_pipex	*pipex, const char **envp)
{
	pid_t	pid;

	if (pipex->cmdc_i >= pipex->cmdc - 1)
		return (pipex->final_exit_status);
	//store_execve_argvもってくるかも
	pid = fork();
	if (pid < 0)
		false_fork(pipex);
	else if (pid == 0)
	{
		if (pipex->cmdc_i == pipex->cmdc)
			exec_from_infile(pipex, envp);
		else if (pipex->cmdc_i == 1)
			exec_to_outfile(pipex, envp);
		else
			exec_to_from_pipefd(pipex, envp);
	}
	pipex->cmdc_i++;
	free_execve_argv(pipex->execve_argv);
	close(pipex->pipe_fd[0]);
	waitpid(pid, pipex->exit_status, 0);
	spawn_child_and_process(pipex, envp);
}
