/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_execve_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:43:48 by kaara             #+#    #+#             */
/*   Updated: 2025/01/22 16:46:23 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_execve_argv(char **execve_argv)
{
	int	i;

	i = 0;
	while (execve_argv[i] != NULL)
		free(execve_argv[i]);
	free(execve_argv);
}
