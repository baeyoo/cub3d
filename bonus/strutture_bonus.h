/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutture_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:55:27 by mobrycki          #+#    #+#             */
/*   Updated: 2021/04/30 18:55:29 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUTTURE_BONUS_H
# define STRUTTURE_BONUS_H

# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13

# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123

# define TRUE 1
# define FALSE 0

# define PI 3.14159
# define P2 1.570795
# define P3 4.712385
# define DR 0.0174533 //un grado in radianti
# define MAPS 64.000

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_faces{
	int		startx;
	int		starty;
	double	stepx;
	double	stepy;
	double	sizex;
	double	sizey;
}				t_faces;

typedef struct s_nsew{
	int		nord;
	int		sud;
	int		ovest;
	int		est;
	int		sprite;
	int		res;
}				t_nsew;

typedef struct s_hit{
	double		xo;
	double		yo;
	int			dof;
}				t_hit;

typedef struct s_map{
	double		width;
	double		height;
	double		size;
	double		*distanze;
	int			mapX;
	int			mapY;
	int			*mappa;
	int			newline;
	int			rigalunga;
}				t_map;

typedef struct s_stato{
	double		posx;
	double		posy;
	double		dex;
	double		dey;
	double		angle;
	int			init;
}				t_stato;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_rays {
	int			mx;
	int			my;
	int			mp;
	double		rx;
	double		ry;
	double		ra;
	double		wallX;
	int			blockOffSet;
}				t_rays;

typedef struct s_sprite{
	double		x;
	double		y;
	double		distanza;
	double		angolo;
	double		diffang;
	int			visibile;
	double		center;
	double		pixdim;
	int			obj;
	int			text;
}				t_sprite;

typedef struct s_movement{
	int			up;
	int			down;
	int			left;
	int			right;
	int			cam_right;
	int			cam_left;
}				t_movement;

typedef struct s_distance{
	double		hit;
	double		distH;
	double		vx;
	double		vy;
	double		distV;
}				t_distance;

typedef struct s_texture{
	int			wi;
	int			he;
	char		*path;
	t_data		img;
}				t_texture;

typedef struct s_sfondo{
	int			t;
	int			r;
	int			g;
	int			b;
	int			color;
}				t_sfondo;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			ns;
	int			snacks;
	int			screen;
	int			face;
	int			gnam;
	t_stato		stato;
	t_data		img;
	t_rays		rays;
	t_distance	distance;
	t_map		mappa;
	t_movement	movement;
	t_texture	texture[16];
	t_sfondo	sfondo[2];
	t_sprite	*sprite;
	t_nsew		nsew;
	t_faces		faces;
}				t_vars;

int				mlx_get_screen_size(t_vars *vars, int *W, int *H);
//vediamo
int				init_texture(t_vars *vars);
int				ft_strcmp(char *s1, char *s2);
int				render(t_vars *vars);
int				mlx_and_move(t_vars vars);
int				main(int argc, char **argv);
//errori
int				fermagioco(int i);
int				ft_finish(t_vars *vars);
//check
void			check_res(t_vars *vars);
int				ft_check_xpm(char *file);
int				ft_check_file(char *file);
void			check_input(t_vars *vars);
//utils
char			*ft_strdup(char *str);
int				ft_strcomp(char c, char *str);
int				ft_strisdigit(char *str);
int				ft_paraculo(char **line);
int				ft_paraparaculo(char **line);
//engine support
int				check_diagonalw(t_vars *vars, char c, int mp);
int				check_diagonals(t_vars *vars, char c, int mp);
int				check_diagonala(t_vars *vars, char c, int mp);
int				check_diagonald(t_vars *vars, char c, int mp);
//engine
int				onPress(int keycode, t_vars *vars);
int				onRelease(int keycode, t_vars *vars);
void			left_right(t_vars *vars, int mex, int mey, int mp);
void			up_down(t_vars *vars, int mex, int mey, int mp);
int				setting(t_vars *vars);
//sprite utils
void			readtwo(t_vars *vars);
double			setang(double ang1, double ang2);
void			ics(t_vars *vars, int i, int x, int a);
void			ft_calc(t_vars *vars, int j);
void			sprite__(t_vars *vars);
//sprites
void			ft_swap(t_vars *vars, int j);
void			ft_bubble(t_vars *vars);
void			dibuja(t_vars *vars, int i, int x, int a);
void			draw_sprites(t_vars *vars);
void			main_sprite(t_vars *vars);
//mappa utils
void			init_nsew(t_vars *vars);
void			findplayer(t_vars *vars);
void			find_nsew(t_vars *vars, int i, int j);
void			checkresult2(int *str, int i, int k);
int				checkresult(int *str, t_vars *vars, int j);
//mappa
char			*fillmalloc2(char *str, int ck);
int				num(const char *str, t_vars *vars);
int				*fillmalloc(char *str, int *s, t_vars *vars);
int				*malloc_next_line(int fd, t_vars *vars);
void			main_texture(t_vars *vars);
//texture
int				init_texture_1(t_vars *vars);
int				init_texture_2(t_vars *vars);
int				init_texture_3(t_vars *vars);
int				init_texture_4(t_vars *vars);
int				init_sprite_1(t_vars *vars);
//math
double			FixAng(double a);
double			DegToRad(double a);
double			calculate_distance(t_vars *vars);
//raycasting
void			check_distanza(t_vars *vars);
void			vertical_hit(t_vars *vars, t_hit *hit);
void			vertical(t_vars *vars, t_hit *hit);
void			horizontal_hit(t_vars *vars, t_hit *hit);
void			horizontal(t_vars *vars, t_hit *hit);
//screenshot
int				leggipix_1(t_data *data, int x, int y);
void			bitmap_data(t_vars *vars, int fd);
void			bitmap_image(t_vars *vars, int fd);
void			bitmap_file(t_vars *vars, int fd);
void			screenshot(t_vars *vars);
//gnl
int				ft_strlen(char *str);
char			*ft_strjoin(char *str1, char *str2);
int				ft_strchr(char c, char *str);
char			*ft_support_get_n_line(char *total, char string[2]);
int				get_next_line(char **line, int fd);
//background
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				leggipix(t_texture tex, int x, int y);
void			draw_walls(t_vars *vars, int r, int i, int j);
void			walls(t_vars *vars, int r);
void			groundsky(t_vars *vars, int r);
//parsing
int				ft_res(t_vars *vars, char *line);
int				ft_parsing(t_vars *vars, int fd);
char			*ft_path(char *line, int i, t_vars *vars);
int				ft_support_support_parsing(int i, t_vars *vars, char *line);
int				ft_support_parsing(int i, t_vars *vars, char *line);
//color
void			init_backcolor(t_vars *vars);
void			init_color(t_vars *vars, char *line, int i);
int				ft_color(t_vars *vars, char *line, int i);
void			ft_numcolor(t_vars *vars);
int				create_trgb(int t, int r, int g, int b);
//macchine
int				init_macchine(t_vars *vars);
void			draw_macchine(t_vars *vars, int i, int x, int a);
//snacks
void			check_sound(t_vars *vars);
int				init_snacks(t_vars *vars);
void			draw_snacks(t_vars *vars, int i, int x, int a);
void			set_snacks(t_vars *vars);
void			check_snacks_macchine(t_vars *vars);
//faccia
int				init_face(t_vars *vars);
int				init_face_2(t_vars *vars);
void			draw_face(t_vars *vars);
//monster
void			assing_text_2(t_vars *vars, int i, int j);
void			assing_text(t_vars *vars);
int				init_tar(t_vars *vars);
int				init_volt(t_vars *vars);
int				init_headless(t_vars *vars);
int				init_knight(t_vars *vars);
int				init_ghost(t_vars *vars);
int				init_clown(t_vars *vars);
int				init_sub(t_vars *vars);
#endif
