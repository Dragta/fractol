/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsusanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:24:05 by fsusanna          #+#    #+#             */
/*   Updated: 2023/02/11 17:36:14 by fsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>


# define ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define LEFT_CTRL 256
# define LEFT_CAPS 257
# define RIGHT_CAPS 258
# define PR_LCAPS	0b0000000001000000
# define OTHER_IMG	0b0000000010000000
# define DRAG_IMG	0b0000000100000000
# define MAX_ITER 50
# define WIN_WIDTH 400
# define WIN_HEIGHT 240
# define MAX_POINTS 230987
# define ZOOM_FACTOR 2
# define Q0 (t_quaternion){0, 0, 0, 0}


typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct	s_quaternion
{
	double	r;
	double	i;
	double	j;
	double	k;
}				t_quaternion;

typedef struct	s_2dhypersection
{
	unsigned int	*addr;
	t_quaternion	center;
	t_quaternion	x_vector;
	t_quaternion	y_vector;
	t_quaternion	z_vector;
	int				max_i;
	double			zoom;

}				t_2dhypersection;

typedef struct	s_user_state
{
	unsigned int	buttons;
	int				x;
	int				y;
}				t_user_state;

typedef struct	s_cloud
{
	int				points;
	t_quaternion	rot;
	t_quaternion	center;
	t_quaternion	voxels[232000];
}				t_cloud;

typedef struct	s_sack
{
	void				*mlx;
	void				*mlx_win;
	t_data				img;
	char				type;
	t_2dhypersection	params2d;
	t_user_state		user;
	t_cloud				*cloud;
	void				*other;
	void				*other3d;
}				t_sack;

t_quaternion		q_add(t_quaternion q1, t_quaternion q2);
t_quaternion		q_by(t_quaternion q1, t_quaternion q2);
t_quaternion		q_star(t_quaternion q);
t_quaternion		q_by_scalar(t_quaternion q1, double s);
double				dot_product(t_quaternion q1, t_quaternion q2);
void				q_unit(t_quaternion *q);
double				norm2(t_quaternion z);
void				iter(t_quaternion *zc);
void				pixel_axis(t_2dhypersection sect,
						t_quaternion *x_axis, t_quaternion *y_axis);
t_quaternion		pixel_to_quat(int x, int y, t_sack s);
void				chg_iter(t_sack *s, int key);
void				chg_view(t_sack *s, int key);
void				px_to_cloud(int	x, int y, t_sack s);
void				find_border(int x, int y, t_sack s);
void				clear_img(t_data img);
unsigned int		color(int scheme, t_quaternion point, t_sack s);
int					project2d(t_sack s, int colors);
void				center_cloud(t_sack s);
void				pile3d(t_sack s);
void				switch_wins(t_sack *s);
void				zoom_at(int x, int y, double zf, t_sack *s);
int 				key_press(int keycode, t_sack *s);
int 				key_release(int keycode, t_sack *s);
int 				mouse_press(int button, int x, int y, t_sack *s);
int 				mouse_release(int button, int x, int y, t_sack *s);
int 				mouse_move(int x, int y, t_sack *s);
void				show_image(t_sack *s);
double				ft_strtof(char *str);
void				showhelp();
t_2dhypersection	initialise_2D(unsigned int *addr, double zoom);
void				initialise_s(t_sack *s, char *win_name);
void				plot(t_sack s, int paint);
t_quaternion		rotate(t_quaternion p, t_quaternion rot);
int 				vkey_press(int keycode, t_sack *s);
int					vmouse_press(int button, int x, int y, t_sack *s);
int					vmouse_release(int button, int x, int y, t_sack *s);
int					vmouse_move(int x, int y, t_sack *s);
void				open_cloud(t_sack *s);
void				open_all(char type, double re, double im);
int					main(int nargs, char **args);

#endif
