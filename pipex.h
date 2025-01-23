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

//allocation_and_cpy.c
char	*allocation_and_cpy(const char *src);

//store_args_in_struct.c
void	store_args_in_struct(t_pipex *pipex, int argc, char **argv);

//get_path_from_envp.c
char	**get_path_from_envp(char *const *envp, t_pipex *pipex);

//spawn_child_and_process.c
int		spawn_child_and_process(t_pipex	*pipex,
			char *const *envp);

//false_fork.c
void	false_fork(t_pipex	*pipex);

//validate_cmd_full_path.c
char	*validate_cmd_full_path(t_pipex *pipex, char *cmd);

//store_execve_argv.c
char	**store_execve_argv(t_pipex *pipex, char **cmd);

//voidexec_from_infile.c
void	exec_from_infile(t_pipex *pipex, char *const *envp);

//exec_to_from_pipefd.c
int		exec_to_from_pipefd(t_pipex *pipex, char *const *envp);

//exec_to_outfile.c
int		exec_to_outfile(t_pipex *pipex, char *const *envp);

//free_execve_argv.c
void	free_execve_argv(char **execve_argv);

//free_exit.c
int		free_exit(t_pipex	*pipex, bool	exit_status);

#endif
