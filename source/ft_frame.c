/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:24:43 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/01 15:28:49 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_render_coin_row(char *row, t_init *init, int y, int c)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (row[i] && !(row[i] == '\0'))
	{
		if (row[i] == COIN && c == 1)
			mlx_put_image_to_window(init->mlx, init->win,
				init->coin->img, x, y);
		if (row[i] == COIN && c == 2)
			mlx_put_image_to_window(init->mlx, init->win,
				init->coin2->img, x, y);
		i++;
		x += 48;
	}
}

void	ft_render_coin(t_init *init, int c)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (y < init->win_height)
	{
		ft_render_coin_row(init->map[i++], init, y, c);
		y += 48;
	}
}

int	ft_frame(t_init *init)
{
	init->frame += 1;
	if (init->frame == 20000)
	{
		ft_render_coin(init, 1);
	}
	if (init->frame == 40000)
	{
		ft_render_coin(init, 2);
		init->frame = 0;
	}
	return (1);
}
