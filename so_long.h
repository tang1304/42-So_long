/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:16:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/31 17:39:58 by tgellon          ###   ########lyon.fr   */
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
# include "mlx/mlx_MAC/mlx.h"
# include "mlx/mlx_linux/mlx.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define RED_CROSS 33

# define WALL "./sprites/wall.xpm"
# define OBSTACLE "./sprites/obstacle.xpm"
# define PLAYER "./sprites/player.xpm"
# define COLLECTIBLE "./sprites/collectible.xpm"
# define FLOOR "./sprites/floor.xpm"
# define EXIT "./sprites/exit.xpm"

# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_map
{
	int		p_x;
	int		p_y;
	char	**map;
	int		width;
	int		height;
	int		p;
	int		e;
	int		c;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
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
void	put_square(t_data *data);
void	put_object(t_data *data);
void	put_background(t_data *data);
int		put_map(t_data *data);

/*	colors.c	*/
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/*	key_hook.c	*/
int		keyhook(int keycode, t_data *data);

/*	utils.c	*/
char	*ft_strjoin_sl(char *s1, char *s2);
void	ft_free_map(char **str);
void	ft_free_maps(t_data *data);

#endif
