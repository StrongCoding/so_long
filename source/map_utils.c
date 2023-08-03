/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:34:10 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/03 10:03:17 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//inits player and exit coord and coint coint 
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
			if (map[i][j] == EXIT)
			{
				init->exit_y = i * 48;
				init->exit_x = j * 48;
			}
		}
		j = 0;
	}
}

//checks if map is sourrounded by walls
int	ft_check_map_border(char **map)
{
	int	i;
	int	j;
	int	len;

	len = ft_check_row_lengths(map);
	i = -1;
	j = 0;
	while (map[++i])
	{
		while (map[i] != NULL && map[i][j] != '\n' && map[i][j] != '\0')
		{
			if ((!(map[i][j] == WALL) && (i == 0 || map[i + 1] == NULL)))
			{
				return (-1);
			}
			if (!(map[i][0] == WALL && map[i][len - 1] == WALL))
			{
				return (-1);
			}
			j++;
		}
		j = 0;
	}
	return (1);
}

//check row lengths, if not all same return -1 else return the length for window
int	ft_check_row_lengths(char **map)
{
	int	i;
	int	len;

	i = 0;
	if (!map)
		return (-1);
	len = ft_strlen_s(map[i++]);
	while (map[i])
	{
		if (!(len == ft_strlen_s(map[i++])))
			return (-1);
	}
	return (len);
}

//check path
int	ft_check_path(char **map)
{
	return (1);
}
