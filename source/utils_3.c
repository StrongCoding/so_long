/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:29:33 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/04 12:06:59 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_destroy_all_images(t_init *init)
{
	mlx_destroy_image(init->mlx, init->ghost->img);
	mlx_destroy_image(init->mlx, init->ghostr->img);
	mlx_destroy_image(init->mlx, init->ground->img);
	mlx_destroy_image(init->mlx, init->wall->img);
	mlx_destroy_image(init->mlx, init->coin->img);
	mlx_destroy_image(init->mlx, init->exit->img);
	mlx_destroy_image(init->mlx, init->exitul->img);
	mlx_destroy_image(init->mlx, init->coin2->img);
	mlx_destroy_image(init->mlx, init->won->img);
	mlx_destroy_image(init->mlx, init->dead1->img);
	mlx_destroy_image(init->mlx, init->dead2->img);
	mlx_destroy_image(init->mlx, init->dead3->img);
	mlx_destroy_image(init->mlx, init->trap->img);
}

void	ft_free_all_images(t_init *init)
{
	free(init->ghost);
	free(init->ghostr);
	free(init->ground);
	free(init->wall);
	free(init->coin);
	free(init->exit);
	free(init->exitul);
	free(init->coin2);
	free(init->won);
	free(init->dead1);
	free(init->dead2);
	free(init->dead3);
	free(init->trap);
}