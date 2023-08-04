/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:53:23 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/04 12:10:24 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_copy_map(int rows, char **map)
{
	int		i;
	char	**map_copy;

	i = -1;
	map_copy = malloc((rows + 1) * sizeof(char *));
	while (++i < rows)
	{
		map_copy[i] = malloc(sizeof(char) * (ft_strlen_s(map[i]) + 1));
		ft_strlcpy(map_copy[i], map[i], ft_strlen_s(map[i]) + 1);
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	ft_check_flooded_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		while (map[i] != NULL && map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == COIN)
				return (-1);
			if (map[i][j] == EXIT)
			{
				if (map[i + 1][j] != 'X' && map[i - 1][j] != 'X' && 
					map[i][j + 1] != 'X' && map[i][j - 1] != 'X')
					return (-1);
			}
			j++;
		}
		j = 0;
	}
	return (1);
}

int	ft_check_map_size(t_init *init)
{
	if (init->win_height > 1440 || init->win_width > 2560)
	{
		ft_printf("Error\nMap too big\n");
		return (-1);
	}
	return (1);
}
