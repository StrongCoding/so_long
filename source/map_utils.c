/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:34:10 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/26 10:41:52 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//inits player coord and coint coint
void	ft_init_player_coord(char **map, t_init *init)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		while (map[i] != NULL && map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == GHOST)
			{
				init->y = i * 48;
				init->x = j * 48;
			}
			if (map[i][j] == COIN)
				init->coins += 1;
			j++;
		}
		j = 0;
	}
}
