/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:43:01 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/25 21:25:01 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
//# include <X11/keysym.h>
//# include <X11/X.h>

# define WIN_X		624
# define WIN_Y		240

# define WALL		49
# define GROUND		48
# define COIN		67
# define GHOST		80
# define EXIT		69

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

typedef struct s_sprite {
	void	*img;
	int		width;
	int		height;
	char	*relative_path;
	// int		posx;
	// int		posy;
}				t_sprite;

typedef struct s_init {	
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	int			x;
	int			y;
	t_sprite	*ghost;
	t_sprite	*ground;
	t_sprite	*wall;
	t_sprite	*coin;
	t_sprite	*exit;
}				t_init;

char	**ft_parse_map(char *file, int rows, t_init *init);
size_t	ft_strlen_s(const char *s);
int		ft_get_rows(char *file);
void	ft_render_map(char **map, t_init *init);

#endif