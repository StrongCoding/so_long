/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:48:53 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/03 10:16:12 by dnebatz          ###   ########.fr       */
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
	ft_print_movements(init);
	init->map[init->y / 48][init->x / 48] = GHOSTR;
	mlx_put_image_to_window(init->mlx, init->win,
		init->ghostr->img, init->x, init->y);
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
	init->movements += 1;
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
	init->y -= 48;
	if (init->map[(init->y / 48) + 1][init->x / 48] == GHOST)
	{
		init->map[init->y / 48][init->x / 48] = GHOST;
		mlx_put_image_to_window(init->mlx, init->win,
			init->ghost->img, init->x, init->y);
	}
	if (init->map[(init->y / 48) + 1][init->x / 48] == GHOSTR)
	{
		init->map[init->y / 48][init->x / 48] = GHOSTR;
		mlx_put_image_to_window(init->mlx, init->win,
			init->ghostr->img, init->x, init->y);
	}
	init->map[(init->y / 48) + 1][init->x / 48] = GROUND;
	ft_print_movements(init);
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
	init->movements += 1;
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
		if (init->collected_coins == init->coins)
			ft_render_unlocked_exit(init);
		return (1);
	}
	if (map[(y / 48)][x / 48] == EXITU && init->collected_coins == init->coins)
	{
		mlx_put_image_to_window(init->mlx, init->win, init->won->img,
			(init->win_width / 2) - 72, (init->win_height / 2) - 48);
		return (0);
	}
	else
		return (0);
}
