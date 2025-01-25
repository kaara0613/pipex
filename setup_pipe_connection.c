/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipe_connection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:30:25 by kaara             #+#    #+#             */
/*   Updated: 2025/01/25 10:30:25 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup_pipe_connection(t_pipex *pipex)
{
		//
		printf("setup_pipe_connection\n");
		//
	if (pipex->cmdc_i == 0)
		from_infile(pipex);
	else if (pipex->cmdc_i == pipex->cmdc - 1)
		to_outfile(pipex);
	else
		to_from_pipefd(pipex);
}
