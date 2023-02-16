/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:39:18 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/15 16:44:06 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG__BONUS_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx_linux/mlx.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define RED_CROSS 33

# define ANIMATION 25000
# define SLEEP 300000

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
# define C_RL "./sprites/c_rl.xpm"
# define C_LR "./sprites/c_lr.xpm"
# define C_UD "./sprites/c_ud.xpm"
# define C_DU "./sprites/c_du.xpm"
# define FLOOR "./sprites/floor.xpm"
# define P_FRONT_STILL "./sprites/player_front_still.xpm"
# define P_BACK_STILL "./sprites/player_back_still.xpm"
# define P_LEFT_STILL "./sprites/player_left_still.xpm"
# define P_RIGHT_STILL "./sprites/player_right_still.xpm"
# define P_RL_OUT "./sprites/p_rl_out.xpm"
# define P_RL_IN "./sprites/p_rl_in.xpm"
# define P_LR_OUT "./sprites/p_lr_out.xpm"
# define P_LR_IN "./sprites/p_lr_in.xpm"
# define P_UD_OUT "./sprites/p_ud_out.xpm"
# define P_UD_IN "./sprites/p_ud_in.xpm"
# define P_DU_OUT "./sprites/p_du_out.xpm"
# define P_DU_IN "./sprites/p_du_in.xpm"
# define EXIT_OFF "./sprites/exit_off.xpm"
# define EXIT_ON "./sprites/exit_on.xpm"
# define D_STILL "./sprites/ennemy_still.xpm"
# define D_LEFT "./sprites/ennemy_left.xpm"
# define D_RIGHT "./sprites/ennemy_right.xpm"

# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

typedef struct s_img
{
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
	int		d_nbr;
	int		moves;
	int		frames;
	int		p_frames;
	char	*tmp;
	char	**mapcpy;
	t_img	img;
	t_map	map;
}	t_data;

/*	so_long_bonus.c	*/
int		ft_close(t_data *data);

/*	map_bonus.c	*/
int		map_init(t_data *data, int argc, char **argv);
void	get_p_position(t_data *data);

/*	map2_bonus.c	*/
int		map_parsing(t_data *data);
int		x_wall_check(t_data *data);
int		y_wall_check(t_data *data);

/*	image_bonus.c	*/
int		put_img(t_data *data, char *path, int x, int y);
int		put_map(t_data *data);
int		put_background(t_data *data);
int		choose_img(t_data *data, char c, int x, int y);

/*	key_hook_bonus.c	*/
int		keyhook(int keycode, t_data *data);

/*	move_bonus.c	*/
int		move(t_data *data, int y, int x, int keycode);

/*	anim_enemy_bonus.c	*/
int		frame_rendering(t_data *data);

/*	anim_player_bonus.c	*/
int		anim_player(t_data *data, int keycode, int x, int y);

/*	utils_bonus.c	*/
char	*ft_strjoin_sl(char *s1, char *s2);
void	ft_free_map(char **str);
void	ft_free_maps(t_data *data);
void	data_init(t_data *data);
int		map_empty_line_check(t_data *data);

#endif
