/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_setup_pipefd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:15 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:25:15 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void	setup_pipefd(t_pipex *pipex, int cmdc_i)
{
	if (cmdc_i != 0)
	{
		if (dup2(pipex->pre_pipefd, STDIN_FILENO) == -1)
		{
			ft_dprintf("dup2 return -1.\n");
			free_exit(pipex, EXIT_FAILURE);
		}
		close(pipex->pre_pipefd);
	}
	if (pipex->cmdc - 1 != cmdc_i)
	{
		if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
		{
			ft_dprintf("dup2 return -1.\n");
			free_exit(pipex, EXIT_FAILURE);
		}
		close(pipex->pipe_fd[1]);
		close(pipex->pipe_fd[0]);
	}
}
