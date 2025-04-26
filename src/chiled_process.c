/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chiled_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:47:32 by kaara             #+#    #+#             */
/*   Updated: 2025/01/29 10:47:32 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void	chiled_process(t_pipex *pipex, char *const *envp, int cmdc_i)
{
	setup_filefd(pipex, cmdc_i);
	pipex->execve_argv
		= store_execve_argv(pipex, pipex->cmdv[cmdc_i]);
	execve(pipex->full_path, pipex->execve_argv, envp);
	ft_dprintf("execve failed.\n");
	exit(EXIT_FAILURE);
}
