/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:27:40 by kaara             #+#    #+#             */
/*   Updated: 2025/01/24 13:27:40 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(int argc, char **argv, char *const *envp)
// {
// 	t_pipex	*pipex;

// 	if (argc == 1)
// 		return (0);
// 	pipex = allocation_pipex();
//     store_args_in_struct(pipex, argc, argv);
// 	pipex->path = get_path_from_envp(envp, pipex);
// 	pipex->final_exit_status = spawn_child_and_process(pipex, envp);
// 	close(pipex->outfile_fd);
// 	free_exit(pipex, true);
// 	return (pipex->final_exit_status);
// }
