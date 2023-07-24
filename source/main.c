/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:45:21 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/24 21:10:47 by dnebatz          ###   ########.fr       */
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
	}
	return (tmp);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
		ft_move_right(init, init->sprite, &init->sprite->posx, &init->sprite->posy);
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
	void		*win;
	void		*img;
	t_sprite	*ghost;
	t_sprite	*ground;
	t_init		*init;

	ghost = ft_lstimgnew("./sprites/ghost.xpm");
	ground = ft_lstimgnew("./sprites/ground.xpm");
	ground->posx = 0;
	ground->posy = 0;
	ghost->posx = 48;
	ghost->posy = 48;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx = mlx_init();
	if (!mlx)
	{
		ft_printf("mlx creation error!\n");
		return (0);
	}
	init = ft_lstinitnew(mlx);
	init->win = mlx_new_window(mlx, WIN_X, WIN_Y, "so_long");
	//init->win = win;
	if (!init->win)
	{
		ft_printf("win creation error!\n");
		return (0);
	}
	ghost->img = mlx_xpm_file_to_image(mlx, ghost->relative_path, &ghost->width, &ghost->height);
	ground->img = mlx_xpm_file_to_image(mlx, ground->relative_path, &ground->width, &ground->height);
	if (!ghost->img)
	{
		ft_printf("sprite ghost creation error!\n");
		return (0);
	}
	if (!ground->img)
	{
		ft_printf("sprite ground creation error!\n");
		return (0);
	}
	init->sprite = ghost;
	while (i <= WIN_X - ground->width)
	{
		while (j <= WIN_Y - ground->height)
		{
			mlx_put_image_to_window(init->mlx, init->win, ground->img, i, j);
			j += 48;
		}
		j = 0;
		i += 48;
	}
	//mlx_put_image_to_window(init->mlx, init->win, ghost->img, 0, 0);
	//mlx_put_image_to_window(init->mlx, init->win, ghost->img, 100, 100);
	mlx_hook(init->win, 2, 1L << 00, key_hook, init);
	mlx_loop(init->mlx);
	return (0);
}
