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

int	main(int argc, char **argv, char *const *envp)
{
	t_pipex	*pipex;
	int		exit_status;

	if (argc <= 4)
	{
		perror("Missing argument");
		return (0);
	}
	pipex = allocation_pipex();
	store_args_in_struct(pipex, argc, argv);
	pipex->path = get_path_from_envp(envp, pipex);
	exit_status = spawn_child_and_process(pipex, envp, 0);
	free_exit(pipex, 0);
	return (exit_status);
}
