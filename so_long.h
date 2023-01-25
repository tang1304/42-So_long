/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:16:52 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/25 15:38:01 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <limits.h>
# include <stdio.h>//TODO: a suppr
# include "libft/libft.h"
# include "mlx/mlx_MAC/mlx.h"
# include "mlx/mlx_linux/mlx.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

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

typedef struct s_data
{
	t_img	img;
	void	*mlx;
	void	*win;
	int		w;
	int		h;
}	t_data;

/*	so_long.c	*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_close(t_data *data);

/*	image.c	*/
void	put_square(t_data *data);
void	put_object(t_data *data);
void	put_background(t_data *data);

/*	colors.c	*/
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/*	key_hook.c	*/
int		ft_keyhook(int keycode, t_data *data);

#endif
