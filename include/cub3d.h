/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:36:14 by gsaiago           #+#    #+#             */
/*   Updated: 2023/11/11 04:12:21 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./libft/libft.h"
# include "../include/mlx.h"

# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <stdbool.h>

/* __________Defines__________ */

# define WINDOW_WIDTH 854
# define WINDOW_HEIGHT 480
# define PLAYER_COLOR 0x0000ff
# define RAY_COLOR 0xff0000
# define MOVE_SPEED 0.01
# define ROTATION_SPEED 0.01

#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define L_ARROW 65361
#  define R_ARROW 65363

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_texture
{
	char	*path;
	void	*img_ptr;
	int		*addr;
	int		bpp;
	int		height;
	int		width;
	int		size_len;
	int		endian;
}	t_texture;

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bpp;
	int		size_len;
	int		endian;
}	t_image;

typedef struct s_data
{
	t_texture		no_texture;
	t_texture		so_texture;
	t_texture		we_texture;
	t_texture		ea_texture;
	int				f_color;
	int				c_color;
	int				fok;
	int				cok;
	char			**map;
	int				map_width;
	int				map_height;
	char			spawn_direction;
	double			player_x;
	double			player_y;
	char			walk_direction;
	char			turn_direction;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	char			ray_hit_direction;
	double			wall_x;
	int				texture_x;
	t_image			image;
	double			dist_buffer[WINDOW_WIDTH];
	void			*mlx;
	void			*window;
}	t_data;

typedef struct s_raycast
{
	int			x;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			side;
	t_texture	*image_to_paint;
}	t_raycast;

typedef struct s_paint_image_aux
{
	int		texture_y;
	double	step;
	double	texture_pos;
	int		color;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		y;

}	t_paint_image_aux;

typedef struct s_update_player
{
	float	rot_angle;
	float	old_dir_x;
	float	old_plane_x;
	float	move_step;
	float	next_x;
	float	next_y;

}	t_update_player;

typedef struct s_map_interior_validation_aux
{
	int		line_numb;
	char	*line;
	int		above;
	int		below;
	int		i;
}	t_map_interior_validation_aux;

/* info validation / loading */
int		load_params(t_list **lst, t_data *data);
int		load_no(t_list *head, t_data *data);
int		load_so(t_list *head, t_data *data);
int		load_we(t_list *head, t_data *data);
int		load_ea(t_list *head, t_data *data);
int		load_f(t_list *head, t_data *data);
int		load_c(t_list *head, t_data *data);
int		mat_to_rgb(char **mat);
int		load_map(t_list *head, t_data *data);
bool	init_mlx_image(t_texture *texture, void *mlx);
bool	init_mlx_instances(t_data *data);
/* map validation */
int		validate_map(t_data *data);
int		validate_top_bottom(t_data *data);
int		validate_sides(t_data *data);
int		validate_interior(t_data *data);
void	get_above_below(t_data *data, int line_numb, int *above, int *below);
int		get_map_height(t_list *head);
/* deletion */
void	free_texture(t_data *data, t_texture *texture);

/* I gave up from now on */
int			get_map_width(t_list *head);
void		image_init(t_data *data);
void		raycast(t_data *data);
void		paint_image(t_data *data, int x, t_texture *image_to_paint);
void		put_pixel(t_image *image, int x, int y, unsigned int color);
t_texture	*select_image_to_paint(t_data *data);
void		paint_image_aux(t_data *dt, int x,
				t_texture *img, t_paint_image_aux *a);
void		set_ray_direction(t_data *data, t_raycast *aux);
void		perform_dda(t_data *data, t_raycast *aux);
void		raycast_aux(t_data *data, t_raycast *aux);
void		raycast_aux_refresh_values(t_data *data, t_raycast *aux);
t_texture	*select_image_to_paint(t_data *data);
void		paint_image(t_data *data, int x, t_texture *image_to_paint);
void		update_player(t_data *data);
int			validate_coordinate_size(char **mat, int size);
int			validate_cf_numbers(char **mat);
void		initialize_data(t_data *data);
int			key_pressed(int keycode, t_data *data);
int			key_released(int keycode, t_data *data);
int			close_window(t_data *data);
void		image_init(t_data *data);
int			hook(t_data *data);
int			player_p(t_data *data, const char c, int width, int height);
void		set_player_direction(t_data *data);
void		set_player_plane(t_data *data);
int			validate_args(int argc, char **argv);
void		hooks_init(t_data *data);
#endif
