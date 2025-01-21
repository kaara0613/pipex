/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_and=cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:13:25 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 16:13:25 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*allocation_and_cpy(const char *src)
{
	char result_str;

	result_str = (char *)malloc(sizeof(char) * ft_strlen(src));
	if (result_str == NULL)
	{
		perror("allocation filed");
		return (NULL);
	}
	ft_memcpy(result_str, src, sizeof(char) * ft_strlen(argv[1]));
	return (str);
}
