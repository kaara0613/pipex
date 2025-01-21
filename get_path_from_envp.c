/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_from_envp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:36:50 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 20:33:34 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path_from_envp(const char **envp, t_pipex *pipex)
{
	int		i;
	char	**path;

	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", sizeof(char) * 5) == 0)
			break ;
		i++;
	}
	path = ft_split(envp[i] + 5, ':');
	return (path);
}
