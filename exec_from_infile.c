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

int	voidexec_from_infile(t_pipex *pipex, const char **envp)
{
	pipex->full_path = validate_cmd_full_path(pipex,
			pipex->cmdv[pipex->cmdc_i][0]);
	execve(pipex->full_path, );
}
