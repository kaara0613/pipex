/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_child_and_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:22:01 by kaara             #+#    #+#             */
/*   Updated: 2025/01/29 10:56:49 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	spawn_child_and_process(t_pipex	*pipex, char *const *envp, int cmdc_i)
{
	pid_t	pid;
	int		exit_status;
	int		no_use_exit_status;

	if (cmdc_i >= pipex->cmdc)
		return (0);
	setup_pipefd(pipex);
	pid = fork();
	if (pid < 0)
		false_fork(pipex);
	else if (pid == 0)
		chiled_process(pipex, envp, cmdc_i);
	exit_status = spawn_child_and_process(pipex, envp, cmdc_i + 1);
	if (cmdc_i == pipex->cmdc - 1)
		waitpid(pid, &exit_status, 0);
	else
		waitpid(pid, &no_use_exit_status, 0);
	return (WEXITSTATUS(exit_status));
}
