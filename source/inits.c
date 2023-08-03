/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:35:42 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/03 09:49:10 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_img(t_init *init)
{
	init->ghost->img = mlx_xpm_file_to_image(init->mlx,
			init->ghost->relative_path, &init->ghost->width,
			&init->ghost->height);
	init->ghostr->img = mlx_xpm_file_to_image(init->mlx,
			init->ghostr->relative_path, &init->ghostr->width,
			&init->ghostr->height);
	init->coin2->img = mlx_xpm_file_to_image(init->mlx,
			init->coin2->relative_path, &init->coin2->width,
			&init->coin2->height);
	init->ground->img = mlx_xpm_file_to_image(init->mlx,
			init->ground->relative_path, &init->ground->width,
			&init->ground->height);
	init->wall->img = mlx_xpm_file_to_image(init->mlx,
			init->wall->relative_path, &init->wall->width,
			&init->wall->height);
	init->coin->img = mlx_xpm_file_to_image(init->mlx,
			init->coin->relative_path, &init->coin->width,
			&init->coin->height);
	init->exit->img = mlx_xpm_file_to_image(init->mlx,
			init->exit->relative_path, &init->exit->width,
			&init->exit->height);
	init->exitul->img = mlx_xpm_file_to_image(init->mlx,
			init->exitul->relative_path, &init->exitul->width,
			&init->exitul->height);
	init->won->img = mlx_xpm_file_to_image(init->mlx,
			init->won->relative_path, &init->won->width,
			&init->won->height);
	if (init->exit->img != NULL && init->coin->img != NULL && 
		init->wall->img != NULL && init->ground->img != NULL && 
		init->ghost->img != NULL && init->coin2->img != NULL && 
		init->won->img != NULL)
		return (1);
	return (-1);
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
	if (init->exit != NULL && init->coin != NULL && init->wall != NULL && 
		init->ground != NULL && init->ghost != NULL && init->coin2 != NULL)
		if (ft_init_img(init) > 0)
			return (1);
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
	ft_init_player_coord(init->map, init);
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
		return (NULL);
	if (ft_init_sprites(init) < 0)
		return (NULL);
	ft_parse_map(argv, ft_get_rows(argv), init);
	if (init->map == NULL)
		return (NULL);
	if (!ft_init_mlx_win(init))
		return (NULL);
	return (init);
}
