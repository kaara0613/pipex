/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_and_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:42:13 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:02:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

// void	pipe_and_fork(t_pipex	*pipex, int argc, char **argv)
// {
// 	int	command_nbr;
// 	int	*pipe_fd;
// 	int	return_pipe;

// 	command_nbr = argc - 3;
// 	pipe_fd = NULL;
// 	while (command_nbr > 0)
// 	{
// 		return_pipe = pipe(pipe_fd);
// 		if (return_pipe == -1)
// 		{
// 			perror("pipe return -1");
// 			free_exit(pipex);
// 		}
// 		spawn_child_process(pipex);
// 		command_nbr--;
// 	}
// }
