/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:53:14 by kaara             #+#    #+#             */
/*   Updated: 2025/01/24 23:21:01 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	free_exit(t_pipex	*pipex, bool	exit_status)
{
	int	i;

	i = 0;
	free(pipex->infile_name);
	free(pipex->outfile_name);
	pipex->cmdc_i = 0;
	while (pipex->cmdv[pipex->cmdc_i] != NULL)
	{
		while (pipex->cmdv[pipex->cmdc_i][i] != NULL)
			free(pipex->cmdv[pipex->cmdc_i][i++]);
		free(pipex->cmdv[pipex->cmdc_i++]);
		i = 0;
	}
	free(pipex->cmdv);
	while (pipex->path[i] != NULL)
		free(pipex->path[i++]);
	free(pipex->path);
	free(pipex);
	if (exit_status == false)
		exit (EXIT_FAILURE);
	else
		return (0);
}
