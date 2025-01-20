/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_child_and_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:22:01 by kaara             #+#    #+#             */
/*   Updated: 2025/01/20 21:54:08 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	spawn_child_and_process(t_pipex	*pipex,
			int argc, char **argv)
{
	pid_t	pid;

	if (pipex->cmdc == 0)
		return (pipex->exit_status);
	pid = fork();
	if (pid < 0)
		false_fork(pipex);
	else if (pid == 0)
	{
		if (pipex->cmdc_i == pipex->cmdc)
			exec_from_infile();
		else if (pipex->cmdc_i == 1)
			exec_to_outfile();
		else
			exec_to_from_pipefd();
		exit(pipex->exit_status);
	}
	pipex->cmdc_i--;
	waitpid(pid, pipex->exit_status, 0);
	spawn_child_and_process(pipex, argc, argv);
}

void	false_fork(t_pipex	*pipex)
{
	perror("false fork");
	free_exit(pipex, false);
}
