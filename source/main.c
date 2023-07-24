/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:45:21 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/24 13:42:33 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	*ft_lstimgnew(void *content)
{
	t_sprite	*tmp;

	tmp = malloc(sizeof(t_sprite));
	if (tmp)
	{
		tmp->relative_path = content;
		tmp->img = NULL;
	}
	return (tmp);
}

t_init	*ft_lstinitnew(void *content)
{
	t_init	*tmp;

	tmp = malloc(sizeof(t_init));
	if (tmp)
	{
		tmp->mlx = content;
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

int	color_map_1(void *mlx, void *win, int w, int h)
{
	int	x;
	int	y;
	int	color;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			//color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (( (y * 255) / h) << 8);
			if (x < 200 && y < 200)
				color = 12;
			else
				color = 122;
			mlx_pixel_put(mlx, win, x, y, color);
		}
	}
	return (0);
}

int	close(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	return (0);
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_sprite	*ghost;
	t_init		*init;
	char		spritepath[] = "./sprites/ghost.xpm";
	
	ghost = ft_lstimgnew(spritepath);
	mlx = mlx_init();
	//init = ft_lstinitnew(mlx);
	mlx_win = mlx_new_window(mlx, WIN_X, WIN_Y, "so_long");
	ghost->img = mlx_xpm_file_to_image(mlx, ghost->relative_path, &ghost->width, &ghost->height);
	mlx_put_image_to_window(mlx, mlx_win, ghost->img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, ghost->img, 100, 100);
	//mlx_key_hook(mlx_win, close, &init);
	mlx_loop(mlx);
	return (0);
}
