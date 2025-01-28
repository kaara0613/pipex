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
		perror("pipe return -1.\n");
	pipex->infile_fd = open(pipex->infile_name, O_RDONLY);
	if (pipex->infile_fd == -1)
		perror("open(infile_name, O_RDONLY); return -1.\n");
	else if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 return -1.\n");
		free_exit(pipex, 1);
	}
	close(pipex->infile_fd);
	if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 return -1.\n");
		free_exit(pipex, 1);
	}
	close(pipex->pipe_fd[1]);
}

//基本は親でpipeをつないでinfileからとoutfileへのfdを呼び出す場合だけ
//子プロセスで再度pipeを上書きしてからexcveする。
//openに失敗した場合は子からexit