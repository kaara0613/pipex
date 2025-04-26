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
#include "ft_printf.h"

void	false_fork(t_pipex	*pipex)
{
	ft_dprintf("false fork\n");
	free_exit(pipex, 1);
}
