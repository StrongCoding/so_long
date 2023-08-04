/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:35:42 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/04 12:46:37 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_img(t_init *init)
{
	if (ft_init_img_one(init) < 1)
		return (-1);
	if (ft_init_img_two(init) < 1)
		return (-1);
	if (ft_init_img_three(init) < 1)
		return (-1);
	else
		return (1);
}

int	ft_init_sprites(t_init *init)
{
	init->ghost = ft_newsprite("./sprites/ghostgleft.xpm");
	init->ghostr = ft_newsprite("./sprites/ghostgright.xpm");
	init->ground = ft_newsprite("./sprites/ground.xpm");
	init->wall = ft_newsprite("./sprites/wall.xpm");
	init->coin = ft_newsprite("./sprites/coing.xpm");
	init->coin2 = ft_newsprite("./sprites/coin2g.xpm");
	init->exit = ft_newsprite("./sprites/exitglocked.xpm");
	init->exitul = ft_newsprite("./sprites/exitg.xpm");
	init->won = ft_newsprite("./sprites/won.xpm");
	init->trap = ft_newsprite("./sprites/trap.xpm");
	init->dead1 = ft_newsprite("./sprites/dead1.xpm");
	init->dead2 = ft_newsprite("./sprites/dead2.xpm");
	init->dead3 = ft_newsprite("./sprites/dead3.xpm");
	if (init->exit != NULL && init->coin != NULL && init->wall != NULL && 
		init->ground != NULL && init->ghost != NULL && init->coin2 != NULL
		&& init->ghostr != NULL && init->exitul != NULL && init->won != NULL
		&& init->trap != NULL && init->dead1 != NULL && init->dead2 != NULL
		&& init->dead3 != NULL)
		if (ft_init_img(init) > 0)
			return (1);
	ft_printf("Error\nSprite problem!\n");
	return (-1);
}

int	ft_init_mlx_win(t_init *init)
{
	init->win = mlx_new_window(init->mlx, init->win_width,
			init->win_height, "so_long");
	if (!init->win)
	{
		ft_printf("Error\nWindow creation failed!\n");
		return (0);
	}
	ft_render_map(init->map, init);
	return (1);
}

t_init	*ft_init(char *argv)
{
	t_init	*init;
	void	*mlx;

	init = NULL;
	mlx = mlx_init();
	if (!mlx)
	{
		ft_printf("Error\nmlx initialization error!\n");
		return (0);
	}
	init = ft_newinit(mlx);
	if (init == NULL)
		return (ft_close_programm(init));
	if (ft_init_sprites(init) < 0)
		return (ft_close_programm(init));
	ft_parse_map(argv, ft_get_rows(argv), init);
	if (ft_check_map_size(init) < 1)
		return (ft_close_programm(init));
	if (init->map == NULL)
	{
		printf("ich mag pommes mit map error\n");
		return (ft_close_programm(init));
	}
	if (!ft_init_mlx_win(init))
		return (ft_close_programm(init));
	return (init);
}
