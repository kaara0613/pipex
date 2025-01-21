/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:53:14 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 16:17:12 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_exit(t_pipex	pipx, bool	exit_status)
{
	free(pipex->path);
	free(pipex->infile_name);
	free(pipex->outfile_name);
	pipex->cmdc_i = 0;
	while (pipex->cmdc_i <= pipex->pipex->cmdc)
		free(pipex->cmdv[pipex->cmdc_i++]);
	free(pipex->cmdv);
	free(pipx);
	if (exit_status == false)
		exit (EXIT_FAILURE);
	else
		return (0);
}
