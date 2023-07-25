/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:45:21 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/25 21:13:22 by dnebatz          ###   ########.fr       */
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
	}
	return (tmp);
}

int	ft_move_right(t_init *init, t_sprite *ghost, int *posx, int *posy)
{
	*posx += 48;
	mlx_put_image_to_window(init->mlx, init->win, ghost->img, *posx, *posy);
	return (0);
}

int	key_hook(int keycode, t_init *init)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		printf("walk up!\n");
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		printf("walk down!\n");
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		printf("walk left!\n");
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		printf("walk right!\n");
		//ft_move_right(init, init->sprite, &init->sprite->posx, &init->sprite->posy);
	else if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		mlx_destroy_window(init->mlx, init->win);
		exit(0);
	}
	else
		printf("pressed any key\n");
	return (0);
}
int	main(void)
{
	void		*mlx;
	t_init		*init;
	char		**map;

	mlx = mlx_init();
	if (!mlx)
	{
		ft_printf("mlx creation error!\n");
		return (0);
	}
	init = ft_lstinitnew(mlx);
	map = ft_parse_map("./maps/map2.ber", ft_get_rows("./maps/map2.ber"), init);
	// map = ft_parse_map("./maps/map2.ber", ft_get_rows("./maps/map2.ber"), init);
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
	init->ghost->img = mlx_xpm_file_to_image(init->mlx, init->ghost->relative_path, & init->ghost->width, & init->ghost->height);
	init->ground->img = mlx_xpm_file_to_image( init->mlx,  init->ground->relative_path, & init->ground->width, & init->ground->height);
	init->wall->img = mlx_xpm_file_to_image( init->mlx,  init->wall->relative_path, & init->wall->width, & init->wall->height);
	init->coin->img = mlx_xpm_file_to_image( init->mlx,  init->coin->relative_path, & init->coin->width, & init->coin->height);
	init->exit->img = mlx_xpm_file_to_image( init->mlx,  init->exit->relative_path, & init->exit->width, & init->exit->height);
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
	if (!map)
		return (0);
	printf("now comes the hook\n");
	mlx_hook(init->win, 2, 1L << 00, key_hook, init);
	mlx_loop(init->mlx);
	return (0);
}
