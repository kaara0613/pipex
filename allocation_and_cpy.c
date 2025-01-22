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

char	*allocation_and_cpy(const char *src)
{
	char	result_str;

	result_str = (char *)malloc(sizeof(char) * ft_strlen(src));
	if (result_str == NULL)
	{
		perror("allocation filed");
		return (NULL);
	}
	ft_memcpy(result_str, src, sizeof(char) * ft_strlen(src));
	return (result_str);
}


//ここではexitしないから呼び出し元で全体freeする必要がある。