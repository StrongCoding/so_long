/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_movements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:45:02 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/04 11:23:35 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_movements(t_init *init)
{
	char	*string;
	
	init->movements += 1;
	string = ft_itoa(init->movements);
	mlx_put_image_to_window(init->mlx, init->win,
		init->wall->img, 96, 0);
	mlx_string_put(init->mlx, init->win, 100, 15,
		create_trgb(0, 255, 200, 122), string);
	mlx_string_put(init->mlx, init->win, 30, 15,
		create_trgb(0, 255, 200, 122), "Movements:");
	free(string);
}
