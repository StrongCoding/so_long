/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:37:03 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/03 17:11:33 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_good_end(t_init *init)
{
	mlx_put_image_to_window(init->mlx, init->win, init->won->img,
		(init->win_width / 2) - 72, (init->win_height / 2) - 48);
	init->end = 1;
	return (0);
}

int	ft_init_img_one(t_init *init)
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
	if (init->coin->img != NULL && init->ghostr->img != NULL && 
		init->wall->img != NULL && init->ground->img != NULL && 
		init->ghost->img != NULL && init->coin2->img != NULL)
		return (1);
	return (-1);
}

int	ft_init_img_two(t_init *init)
{
	init->exit->img = mlx_xpm_file_to_image(init->mlx,
			init->exit->relative_path, &init->exit->width,
			&init->exit->height);
	init->exitul->img = mlx_xpm_file_to_image(init->mlx,
			init->exitul->relative_path, &init->exitul->width,
			&init->exitul->height);
	init->won->img = mlx_xpm_file_to_image(init->mlx,
			init->won->relative_path, &init->won->width,
			&init->won->height);
	init->trap->img = mlx_xpm_file_to_image(init->mlx,
			init->trap->relative_path, &init->trap->width,
			&init->trap->height);
	init->dead1->img = mlx_xpm_file_to_image(init->mlx,
			init->dead1->relative_path, &init->dead1->width,
			&init->dead1->height);
	init->dead2->img = mlx_xpm_file_to_image(init->mlx,
			init->dead2->relative_path, &init->dead2->width,
			&init->dead2->height);
	if (init->exit->img != NULL && init->exitul->img != NULL && 
		init->won->img != NULL && init->trap->img != NULL && 
		init->dead1->img != NULL && init->dead2->img != NULL)
		return (1);
	return (-1);
}

int	ft_init_img_three(t_init *init)
{
	init->dead3->img = mlx_xpm_file_to_image(init->mlx,
			init->dead3->relative_path, &init->dead3->width,
			&init->dead3->height);
	if (init->dead3->img != NULL)
		return (1);
	return (-1);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
