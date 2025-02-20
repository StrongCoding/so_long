/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:43:01 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/04 13:12:55 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WALL		49
# define GROUND		48
# define COIN		67
# define GHOST		80
# define GHOSTR		82
# define EXIT		69
# define EXITU		85
# define TRAP		84

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
}				t_sprite;

typedef struct s_init {	
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	int			x;
	int			y;
	int			exit_x;
	int			exit_y;
	t_sprite	*ghost;
	t_sprite	*ghostr;
	t_sprite	*ground;
	t_sprite	*wall;
	t_sprite	*coin;
	t_sprite	*exit;
	t_sprite	*exitul;
	t_sprite	*coin2;
	t_sprite	*won;
	t_sprite	*dead1;
	t_sprite	*dead2;
	t_sprite	*dead3;
	t_sprite	*trap;
	int			collected_coins;
	int			coins;
	char		**map;
	char		**map_copy;
	int			error;
	int			movements;
	int			frame;
	int			end;
}				t_init;

void		ft_parse_map(char *file, int rows, t_init *init);
int			ft_strlen_s(const char *s);
int			ft_get_rows(char *file);
void		ft_render_map(char **map, t_init *init);
void		ft_init_player_coord(char **map, t_init *init);
int			ft_move_right(t_init *init);
int			ft_move_left(t_init *init);
int			ft_move_up(t_init *init);
int			ft_move_down(t_init *init);
int			ft_check_movement(char **map, t_init *init, int x, int y);
int			ft_check_argv(char **argv);
int			ft_check_row_lengths(char **map);
int			ft_check_map_border(char **map);
t_init		*ft_newinit(void *mlx);
t_init		*ft_init(char *argv);
t_init		*ft_newinit(void *mlx);
t_sprite	*ft_newsprite(char *content);
int			ft_check_path(t_init *init);
int			create_trgb(int t, int r, int g, int b);
int			ft_frame(t_init *init);
void		ft_print_movements(t_init *init);
void		ft_render_unlocked_exit(t_init *init);
int			ft_good_end(t_init *init);
int			ft_init_img_one(t_init *init);
int			ft_init_img_two(t_init *init);
int			ft_init_img_three(t_init *init);
char		**ft_copy_map(int rows, char **map);
int			ft_check_flooded_map(char **map);
int			ft_check_map_size(t_init *init);
t_init		*ft_close_programm(t_init *init);
void		ft_free_all_images(t_init *init);
void		ft_destroy_all_images(t_init *init);
int			ft_free_map(char **map);

#endif