/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:06:25 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/03 17:22:41 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//return size until 0 or \n
int	ft_strlen_s(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i] && !(s[i] == '\n'))
		i++;
	return (i);
}
