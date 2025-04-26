/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_pipefd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:06:39 by kaara             #+#    #+#             */
/*   Updated: 2025/04/26 23:06:46 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void	spawn_pipefd(t_pipex *pipex, int cmdc_i)
{
	if (pipex->cmdc - 1 == cmdc_i)
		return ;
	if (pipe(pipex->pipe_fd) == -1)
	{
		ft_dprintf("pipe return -1.\n");
		free_exit(pipex, EXIT_FAILURE);
	}
}
