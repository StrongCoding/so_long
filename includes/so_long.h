/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:43:01 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/24 15:27:40 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../ft_printf/ft_printf.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_sprite {
	void	*img;
	int		width;
	int		height;
	char	*relative_path;
}				t_sprite;

typedef struct s_init {	
	void	*mlx;
	void	*win;
}				t_init;

#define WIN_X 800
#define WIN_Y 600