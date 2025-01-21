/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cmd_full_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:48:56 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 20:48:56 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *validate_cmd_full_path(pipex_t *pipex, char *cmd)
{
	int		i;
	char	*add_slash;
	char	*full_path;

	while (pipex->path[i] != NULL)
	{
		add_slash = ft_strjoin(pipex->path[i], '/');
		full_path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		free(full_path);
	}
}

