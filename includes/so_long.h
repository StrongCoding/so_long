/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:43:01 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/25 09:29:55 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
//# include <X11/keysym.h>
//# include <X11/X.h>

# define WIN_X		672
# define WIN_Y		480

# define WALL		'1'
# define FLOOR		'0'
# define COINS		'C'
# define PLAYER		'P'
# define MAP_EXIT	'E'

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

# define KEY_UP		65362
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

# define KEY_Q		113
# define KEY_ESC	65307

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
	int		posx;
	int		posy;
}				t_sprite;

typedef struct s_init {	
	void		*mlx;
	void		*win;
	t_sprite	*sprite;
}				t_init;



#endif