/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:06:06 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/27 15:37:51 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_init	*ft_newinit(void *mlx)
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
		tmp->error = 0;
	}
	return (tmp);
}

t_sprite	*ft_newsprite(char *content)
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

void	ft_free_map(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_check_row_lengths(map);
	while (i <= len)
		free(map[i++]);
	free(map);
}

void	ft_close_programm(t_init *init)
{
	if (init != NULL)
	{
		if (init->map != NULL)
		{
			ft_free_map(init->map);
		}
	}
	ft_printf("Error\n");
	exit(1);
}
