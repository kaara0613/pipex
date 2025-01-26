/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_from_infile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:20 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:25:20 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	from_infile(t_pipex *pipex)
{
	if (pipe(pipex->pipe_fd) == -1)
	{
		perror("pipe return -1.");
		exit(EXIT_FAILURE);
	}
	pipex->infile_fd = open(pipex->infile_name, O_RDONLY);
	if (pipex->infile_fd == -1)
	{
		perror("open(infile_name, O_RDONLY); return -1.");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 return -1.");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 return -1.");
		exit(EXIT_FAILURE);
	}
	close(pipex->infile_fd);
}
