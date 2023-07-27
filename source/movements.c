/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:48:53 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/27 11:34:48 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_move_right(t_init *init)
{
	if (!(ft_check_movement(init->map, init, (init->x + 48), init->y)))
		return (0);
	mlx_put_image_to_window(init->mlx, init->win,
		init->ground->img, init->x, init->y);
	init->map[init->y / 48][init->x / 48] = GROUND;
	init->x += 48;
	init->map[init->y / 48][init->x / 48] = GHOST;
	mlx_put_image_to_window(init->mlx, init->win,
		init->ghost->img, init->x, init->y);
	return (0);
}

int	ft_move_left(t_init *init)
{
	if (!(ft_check_movement(init->map, init, (init->x - 48), init->y)))
		return (0);
	mlx_put_image_to_window(init->mlx, init->win,
		init->ground->img, init->x, init->y);
	init->map[init->y / 48][init->x / 48] = GROUND;
	init->x -= 48;
	init->map[init->y / 48][init->x / 48] = GHOST;
	mlx_put_image_to_window(init->mlx, init->win,
		init->ghost->img, init->x, init->y);
	return (0);
}

int	ft_move_up(t_init *init)
{
	if (!(ft_check_movement(init->map, init, init->x, (init->y - 48))))
		return (0);
	mlx_put_image_to_window(init->mlx, init->win,
		init->ground->img, init->x, init->y);
	init->map[init->y / 48][init->x / 48] = GROUND;
	init->y -= 48;
	init->map[init->y / 48][init->x / 48] = GHOST;
	mlx_put_image_to_window(init->mlx, init->win,
		init->ghost->img, init->x, init->y);
	return (0);
}

int	ft_move_down(t_init *init)
{
	if (!(ft_check_movement(init->map, init, init->x, (init->y + 48))))
		return (0);
	mlx_put_image_to_window(init->mlx, init->win,
		init->ground->img, init->x, init->y);
	init->map[init->y / 48][init->x / 48] = GROUND;
	init->y += 48;
	init->map[init->y / 48][init->x / 48] = GHOST;
	mlx_put_image_to_window(init->mlx, init->win,
		init->ghost->img, init->x, init->y);
	return (0);
}

//if next move is okay return 1
int	ft_check_movement(char **map, t_init *init, int x, int y)
{
	if (map[(y / 48)][x / 48] == GROUND)
		return (1);
	if (map[(y / 48)][x / 48] == COIN)
	{
		init->collected_coins += 1;
		map[(y / 48)][x / 48] = GROUND;
		return (1);
	}
	if (map[(y / 48)][x / 48] == EXIT && init->collected_coins == init->coins)
	{
		printf("you won!\n");
		return (1);
	}
	else
		return (0);
}
