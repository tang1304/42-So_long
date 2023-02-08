/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:16:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/07 14:45:51 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>//TODO: a suppr
# include "libft/libft.h"
# include "mlx/mlx_linux/mlx.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define RED_CROSS 33

# define WALL_L "./sprites/wall_x0.xpm"
# define WALL_R "./sprites/wall_xmax.xpm"
# define WALL_U "./sprites/wall_y0.xpm"
# define WALL_D "./sprites/wall_ymax.xpm"
# define WALL_UL "./sprites/wall_x0_y0.xpm"
# define WALL_UR "./sprites/wall_xmax_y0.xpm"
# define WALL_DL "./sprites/wall_x0_ymax.xpm"
# define WALL_DR "./sprites/wall_xmax_ymax.xpm"
# define OBSTACLE "./sprites/obstacle.xpm"
# define COLLECTIBLE "./sprites/collectible.xpm"
# define FLOOR "./sprites/floor.xpm"
# define P_FRONT_STILL "./sprites/player_front_still.xpm"
# define P_BACK_STILL "./sprites/player_back_still.xpm"
# define P_LEFT_STILL "./sprites/player_left_still.xpm"
# define P_RIGHT_STILL "./sprites/player_right_still.xpm"
# define EXIT_OFF "./sprites/exit_off.xpm"
# define EXIT_ON "./sprites/exit_on.xpm"

# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

typedef struct s_img
{
	void	*collect;
	void	*img;
	int		height;
	int		width;
}	t_img;

typedef struct s_map
{
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	char	**map;
	int		width;
	int		height;
	int		p;
	int		e;
	int		c;
	int		c_count;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
	int		c_nbr;
	int		moves;
	int		frames;
	char	*tmp;
	char	**mapcpy;
	t_img	img;
	t_map	map;
}	t_data;

/*	so_long.c	*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_close(t_data *data);

/*	map.c	*/
int		map_init(t_data *data, int argc, char **argv);
void	ft_free(t_data *data);

/*	map2.c	*/
int		map_parsing(t_data *data);
int		x_wall_check(t_data *data);
int		y_wall_check(t_data *data);

/*	image.c	*/
int		put_img(t_data *data, char *path, int x, int y);
int		put_map(t_data *data);
int		put_background(t_data *data);
int		choose_img(t_data *data, char c, int x, int y);

/*	walls.c	*/
int		put_walls(t_data *data, int x, int y);

/*	colors.c	*/
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/*	key_hook.c	*/
int		keyhook(int keycode, t_data *data);

/*	move.c	*/
int		move(t_data *data, int y, int x, int keycode);

/*	animation.c	*/
int		frame_rendering(t_data *data);

/*	utils.c	*/
char	*ft_strjoin_sl(char *s1, char *s2);
void	ft_free_map(char **str);
void	ft_free_maps(t_data *data);

#endif
