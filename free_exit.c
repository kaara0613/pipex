/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:53:14 by kaara             #+#    #+#             */
/*   Updated: 2025/01/22 15:30:45 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_exit(t_pipex	*pipex, bool	exit_status)
{
	int	i;

	i = 0;
	free(pipex->path);
	free(pipex->infile_name);
	free(pipex->outfile_name);
	pipex->cmdc_i = 0;
	while (pipex->cmdc_i <= pipex->cmdc)
	{
		while (pipex->cmdv[pipex->cmdc_i++][i] != NULL)
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
