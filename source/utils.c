/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:06:06 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/04 13:06:31 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_sprite_init(t_init *tmp)
{
	tmp->ghost = NULL;
	tmp->ground = NULL;
	tmp->ghostr = NULL;
	tmp->wall = NULL;
	tmp->coin = NULL;
	tmp->coin2 = NULL;
	tmp->exit = NULL;
	tmp->exitul = NULL;
	tmp->won = NULL;
	tmp->dead1 = NULL;
	tmp->dead2 = NULL;
	tmp->dead3 = NULL;
	tmp->trap = NULL;
}

t_init	*ft_newinit(void *mlx)
{
	t_init	*tmp;

	tmp = malloc(sizeof(t_init));
	if (tmp)
	{
		ft_init_sprite_init(tmp);
		tmp->mlx = mlx;
		tmp->win = NULL;
		tmp->win_height = 0;
		tmp->win_width = 0;
		tmp->x = 0;
		tmp->y = 0;
		tmp->exit_x = 0;
		tmp->exit_y = 0;
		tmp->collected_coins = 0;
		tmp->coins = 0;
		tmp->map = NULL;
		tmp->map_copy = NULL;
		tmp->error = 0;
		tmp->end = 0;
		tmp->movements = 0;
		tmp->frame = 0;
	}
	return (tmp);
}

// t_init	*ft_newinit(void *mlx)
// {
// 	t_init	*tmp;

// 	tmp = malloc(sizeof(t_init));
// 	if (tmp)
// 	{
// 		ft_bzero(tmp, sizeof(tmp));
// 	}
// 	return (tmp);
// }
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

// void	ft_free_map(char **map)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = ft_check_row_lengths(map);
// 	while (i <= len)
// 		free(map[i++]);
// 	free(map[i]);
// 	free(map);
// }
void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map[i]);
	free(map);
}

t_init	*ft_close_programm(t_init *init)
{
	if (init != NULL)
	{
		if (init->map != NULL)
		{
			ft_free_map(init->map);
			ft_free_map(init->map_copy);
		}
		if (init->ghost != NULL && init->mlx != NULL)
		{
			printf("i will destroy you images!\n");
			ft_destroy_all_images(init);
		}
		ft_free_all_images(init);
		printf("i will destroy you windows!\n");
		mlx_destroy_display(init->mlx);
		//mlx_destroy_window(init->mlx, init->win);
		free(init->mlx);
	}
	free(init);
	return (NULL);
}
