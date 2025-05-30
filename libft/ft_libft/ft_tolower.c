/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:53:17 by kaara             #+#    #+#             */
/*   Updated: 2024/06/25 20:03:14 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 32;
	return (c);
}
