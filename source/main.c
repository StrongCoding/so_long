/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:45:21 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/26 18:23:48 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_sprite	*ft_lstimgnew(char *content)
{
	t_sprite	*tmp;

	tmp = malloc(sizeof(t_sprite));
	if (tmp)
	{
		tmp->relative_path = content;
		tmp->img = NULL;
		tmp->width = 0;
		tmp->height = 0;
	}
	return (tmp);
}

t_init	*ft_lstinitnew(void *mlx)
{
	t_init	*tmp;

	tmp = malloc(sizeof(t_init));
	if (tmp)
	{
		tmp->mlx = mlx;
		tmp->win = NULL;
		tmp->win_height = 0;
		tmp->win_width = 0;
		tmp->ghost = NULL;
		tmp->ground = NULL;
		tmp->wall = NULL;
		tmp->coin = NULL;
		tmp->exit = NULL;
		tmp->x = 0;
		tmp->y = 0;
		tmp->collected_coins = 0;
		tmp->coins = 0;
		tmp->map = NULL;
	}
	return (tmp);
}

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
		mlx_destroy_window(init->mlx, init->win);
		exit(0);
	}
	else
		printf("keycode: %i collected coins: %i\n", keycode, init->collected_coins);
	return (0);
}

int	key_hook_destroy(t_init *init)
{
	mlx_destroy_window(init->mlx, init->win);
	exit(0);
}

int	expose_hook(t_init *init)
{
	printf("exposed!\n");
	ft_render_map(init->map, init);
}

int	main(int argc, char **argv)
{
	void		*mlx;
	t_init		*init;
	char		**map;

	if (argc != 2)
		return (1);
	printf("check argv: %i\n", ft_check_argv(argv));
	if (ft_check_argv(argv) < 1)
		return (1);
	mlx = mlx_init();
	if (!mlx)
	{
		ft_printf("mlx creation error!\n");
		return (0);
	}
	init = ft_lstinitnew(mlx);
	// map = ft_parse_map("./maps/bigmap.ber", ft_get_rows("./maps/bigmap.ber"), init);
	map = ft_parse_map(argv[1], ft_get_rows(argv[1]), init);
	if (!map)
	{
		printf("Map error!\n");
		return (0);
	}
	init->ghost = ft_lstimgnew("./sprites/ghost.xpm");
	init->ground = ft_lstimgnew("./sprites/ground.xpm");
	init->wall = ft_lstimgnew("./sprites/wall.xpm");
	init->coin = ft_lstimgnew("./sprites/coin.xpm");
	init->exit = ft_lstimgnew("./sprites/exit.xpm");
	init->win = mlx_new_window(mlx, init->win_width, init->win_height, "so_long");
	printf("width: %i height: %i\n", init->win_width, init->win_height);
	if (!init->win)
	{
		ft_printf("win creation error!\n");
		return (0);
	}
	printf("now comes the xpm to file\n");
	init->ghost->img = mlx_xpm_file_to_image(init->mlx, init->ghost->relative_path, &init->ghost->width, &init->ghost->height);
	init->ground->img = mlx_xpm_file_to_image( init->mlx,  init->ground->relative_path, &init->ground->width, &init->ground->height);
	init->wall->img = mlx_xpm_file_to_image( init->mlx,  init->wall->relative_path, &init->wall->width, &init->wall->height);
	init->coin->img = mlx_xpm_file_to_image( init->mlx,  init->coin->relative_path, &init->coin->width, &init->coin->height);
	init->exit->img = mlx_xpm_file_to_image( init->mlx,  init->exit->relative_path, &init->exit->width, &init->exit->height);
	if (!init->ghost->img)
	{
		ft_printf("sprite ghost creation error!\n");
		return (0);
	}
	if (!init->ground->img)
	{
		ft_printf("sprite ground creation error!\n");
		return (0);
	}
	printf("now comes the render map\n");
	init->map = map;
	ft_init_player_coord(map, init);
	ft_render_map(map, init);
	printf("now comes the hook\n");
	mlx_hook(init->win, KeyPress, KeyPressMask, key_hook, init);
	mlx_hook(init->win, DestroyNotify, NoEventMask, key_hook_destroy, init);
	mlx_hook(init->win, Expose, ExposureMask, expose_hook, init);
	mlx_loop(init->mlx);
	return (0);
}
