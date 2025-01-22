/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:24:32 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:24:32 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_pipex
{
	char	*infile_name;
	char	*outfile_name;
	int		cmdc;
	int		cmdc_i;
	char	***cmdv;
	char	**path;
	char	*full_path;
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];
	char	**execve_argv;
	int		exit_status;
	int		final_exit_status;
}	t_pipex;

//allocation_pipex.c
t_pipex	*allocation_pipex(void);

//get_path_from_envp.c
char	*get_path_from_envp(const char **envp, t_pipex *pipex);

//spawn_child_and_process.c
int		spawn_child_and_process(t_pipex	*pipex,
			const char **envp);


//free_exit.c
void	free_exit(t_pipex	*pipex, bool	exit_status);

#endif
