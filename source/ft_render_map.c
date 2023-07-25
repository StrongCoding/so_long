/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:07:23 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/25 21:29:39 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_render_row(char *row, t_init *init, int y)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (row[i] && !(row[i] == '\0'))
	{
		if (row[i] == WALL)
			mlx_put_image_to_window(init->mlx, init->win,
				init->wall->img, x, y);
		if (row[i] == GROUND)
			mlx_put_image_to_window(init->mlx, init->win,
				init->ground->img, x, y);
		if (row[i] == COIN)
			mlx_put_image_to_window(init->mlx, init->win,
				init->coin->img, x, y);
		if (row[i] == GHOST)
			mlx_put_image_to_window(init->mlx, init->win,
				init->ghost->img, x, y);
		if (row[i] == EXIT)
			mlx_put_image_to_window(init->mlx, init->win,
				init->exit->img, x, y);
		i++;
		x += 48;
	}
}

void	ft_render_map(char **map, t_init *init)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (y < init->win_height)
	{
		ft_render_row(map[i++], init, y);
		y += 48;
	}
}
