/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_to_outfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:09 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:25:09 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_printf.h"

void	to_outfile(t_pipex *pipex)
{
	pipex->outfile_fd = open(pipex->outfile_name,
			O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->outfile_fd == -1)
	{
		ft_dprintf("open outfile_name return -1.\n");
		free_exit(pipex, EXIT_FAILURE);
	}
	else if (dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
	{
		ft_dprintf("dup2 return -1.\n");
		free_exit(pipex, EXIT_FAILURE);
	}
	close(pipex->outfile_fd);
}
