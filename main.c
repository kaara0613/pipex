/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:17:24 by kaara             #+#    #+#             */
/*   Updated: 2025/01/17 16:17:24 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, const char **envp)
{
	t_pipex	*pipex;

	if (argc == 1)
		return (0);
	pipex = allocation_pipex();
	store_args_in_struct(pipex, argc, argv);
	pipex->path = get_path_from_envp(envp, pipex);
	spawn_child_and_process(pipex, envp);
	free_exit(pipex, true);
	return (pipex->final_exit_status);
}
