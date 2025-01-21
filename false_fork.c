/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   false_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:00 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:25:00 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	false_fork(t_pipex	*pipex)
{
	perror("false fork");
	free_exit(pipex, false);
}