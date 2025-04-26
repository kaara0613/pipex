/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_and_cpy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:18:30 by kaara             #+#    #+#             */
/*   Updated: 2025/01/22 00:18:30 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_libft.h"
#include "ft_printf.h"

char	*allocation_and_cpy(t_pipex *pipex, const char *src)
{
	char	*result_str;

	result_str = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (result_str == NULL)
	{
		ft_dprintf("allocation filed\n");
		free_exit(pipex, 1);
	}
	ft_strlcpy(result_str, src, sizeof(char) * ft_strlen(src) + 1);
	return (result_str);
}
