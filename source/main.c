/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:45:21 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/04 11:51:57 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_init *init)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		ft_move_up(init);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_move_down(init);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_move_left(init);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_move_right(init);
	else if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		ft_close_programm(init);
		exit(0);
	}
	return (0);
}

int	key_hook_destroy(t_init *init)
{
	ft_close_programm(init);
	exit(0);
	return (1);
}

//triggering after minimizing, so screen is not black
int	expose_hook(t_init *init)
{
	ft_render_map(init->map, init);
	return (1);
}

int	main(int argc, char **argv)
{
	t_init		*init;

	if (argc != 2)
	{
		ft_printf("Error\nwrong parameter count\n");
		return (1);
	}
	if (ft_check_argv(argv) < 1)
		return (1);
	init = ft_init(argv[1]);
	if (init != NULL && !(init->error))
	{
		mlx_hook(init->win, KeyPress, KeyPressMask, key_hook, init);
		mlx_hook(init->win, DestroyNotify, NoEventMask, key_hook_destroy, init);
		mlx_hook(init->win, Expose, ExposureMask, expose_hook, init);
		mlx_loop_hook(init->mlx, ft_frame, init);
		mlx_loop(init->mlx);
	}
	ft_close_programm(init);
	return (0);
}
