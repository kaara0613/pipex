/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_child_and_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:22:01 by kaara             #+#    #+#             */
/*   Updated: 2025/04/26 23:09:44 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static void	close_fd(t_pipex *pipex, int cmdc_i);

int	spawn_child_and_process(t_pipex	*pipex, char *const *envp, int cmdc_i)
{
	pid_t	pid;
	int		exit_status;
	int		pre_exit_status;

	if (cmdc_i >= pipex->cmdc)
		return (0);
	spawn_pipefd(pipex, cmdc_i);
	pid = fork();
	if (pid < 0)
		false_fork(pipex);
	else if (pid == 0)
		chiled_process(pipex, envp, cmdc_i);
	close_fd(pipex, cmdc_i);
	pipex->pre_pipefd = pipex->pipe_fd[0];
	exit_status = spawn_child_and_process(pipex, envp, cmdc_i + 1);
	if (cmdc_i == pipex->cmdc - 1)
	{
		waitpid(pid, &pre_exit_status, 0);
		exit_status = WEXITSTATUS(pre_exit_status);
	}
	else
		waitpid(pid, &pre_exit_status, 0);
	return (exit_status);
}

static void	close_fd(t_pipex *pipex, int cmdc_i)
{
	if (cmdc_i != pipex->cmdc - 1)
		close(pipex->pipe_fd[1]);
	if (cmdc_i != 0)
		close(pipex->pre_pipefd);
}
