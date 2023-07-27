/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:33:08 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/26 18:00:32 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	if (i <= 4)
		return (-1);
	if (ft_strncmp(&argv[1][i - 4], ".ber", 5))
		return (-1);
	return (1);
}
