/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_child_and_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:22:01 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 16:25:25 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	spawn_child_and_process(t_pipex	*pipex, const char **envp)
{
	pid_t	pid;

	if (pipex->cmdc == 0)
		return (pipex->final_exit_status);
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
		exit(pipex->exit_status);
	}
	pipex->cmdc_i--;
	waitpid(pid, pipex->exit_status, 0);
	spawn_child_and_process(pipex, envp);
}