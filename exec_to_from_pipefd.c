/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_to_from_pipefd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:15 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:25:15 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_to_from_pipefd(t_pipex *pipex, const char **envp)
{
	pipex->full_path = validate_cmd_full_path(pipex,
			pipex->cmdv[pipex->cmdc_i][0]);
	execve(pipex->full_path, );
    
}