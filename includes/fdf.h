/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:43:34 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/20 19:02:24 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

# define ERROR -1
# define ZOOM mlx->cst->zoom
# define CT1 mlx->cst->ct1
# define CT2 mlx->cst->ct2
# define AGGR_Y mlx->cst->aggr_y
# define AGGR_X mlx->cst->aggr_x
# define ADR mlx->infos_img->d_addr
# define SL mlx->infos_img->sizeline
# define MMM all->mlx
# define MMI all->mlx->infos_img
# define MMC MMM->cst
# define IMG_X MMM->cst->img_x
# define IMG_Y MMM->cst->img_y
# define MLX MMM->mlx
# define WIN MMM->win
# define IMG MMM->infos_img->img
# define DATAS all->datas
# define LINE DATAS->line
# define GET_COLOR(col) mlx_get_color_value(mlx->mlx, col);
# define MAX(a, b) ((a) < (b) ? (b) : (a))
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define ABS(a) ((a) < 0 ? (a * -1) : (a))
# define COS mlx->cst->ct3
# define SIN mlx->cst->ct4
# define X(a, b, c, d) ((a) * cos(c) - (b) * sin(d))
# define Y(a, b, c, d) ((a) * sin(d) - (b) * cos(c))

typedef struct		s_line
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
	struct s_line	*next;
}					t_line;

typedef struct		s_datas
{
	int				num_line;
	int				nb_words;
	t_line			*line;
	struct s_datas	*next;
}					t_datas;

typedef struct		s_image
{
	void			*img;
	char			*d_addr;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*color;
}					t_image;

typedef struct		s_cst
{
	int				win_x;
	int				win_y;
	int				img_x;
	int				img_y;
	float			zoom;
	int				aggr_x;
	int				aggr_y;
	float			ct1;
	float			ct2;
	float			ct3;
	float			ct4;
	float			prop_z;
}					t_cst;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_image			*infos_img;
	t_cst			*cst;
}					t_mlx;

typedef struct		s_pts
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_pts;

typedef struct		s_draw
{
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
	unsigned int	col_min;
	unsigned int	col_max;
}					t_draw;

typedef struct		s_all
{
	t_datas			*datas;
	t_mlx			*mlx;
	t_pts			pts;
	t_draw			draw;
}					t_all;

typedef struct		s_alt
{
	unsigned int	col_n;
	unsigned int	col_p;
	int				diff;
}					t_alt;

typedef struct		s_diff
{
	int				i;
	unsigned int	color;
	float			j;
	int				cpt;
}					t_diff;

/*
**errors
*/
int					fdf_usage(void);
int					fdf_error_open(char *filename);
int					fdf_no_data(void);
int					fdf_length(t_datas *datas);
int					test_in_window(int drawx, int drawy, t_cst *cst);

/*
**manip listes
*/
t_line				*new_line_list(int y, int x, char *nbr);
t_datas				*new_data_list(int count_words, int num_line, char **tab);
void				data_list_add(t_datas **begin_list, t_datas *new);
void				line_list_add(t_line **begin_list, t_line *new);
void				free_lists(t_datas **datas);
t_line				*find_next_y(t_datas **datas, int x, int y);
t_line				*find_next_y2(t_line **line, int x);
void				pre_free(t_all *all);

/*
** mlx
*/
t_mlx				*mlx_initialise(t_datas **datas);
void				print_pixel_per_line(t_datas *datas, t_mlx *mlx, \
		t_line **line);
t_image				*init_image(t_mlx *mlx);
void				fill_image(t_mlx *mlx, t_image **image);

/*
**affichage & couleur
*/
void				aff_coord(t_all **all);
unsigned int		find_color(char *couleur);
unsigned int		fill_color(int alt);
void				put_color_to_pixel(t_mlx *mlx, t_draw draw, \
		unsigned int color);
int					ft_x1(t_mlx *mlx, int x, int y);
int					ft_y1(t_mlx *mlx, int x, int y, int z);
int					ft_x2(t_mlx *mlx, int x, int z);
int					ft_y2(t_mlx *mlx, int y, int z);
void				line_1(t_mlx *mlx, t_draw draw, t_alt alt);
void				line_2(t_mlx *mlx, t_draw draw, t_alt alt);
void				mlx_draw_line(t_datas *datas, t_line **line, t_mlx *mlx, \
		int cpt);
void				draw_next_y(t_datas *datas, t_line *line, t_mlx *mlx);
void				mlx_draw_line_2(t_line *line_x, t_line *line_y, \
		t_mlx *mlx, t_alt alt);
char				*modify_colors(t_line *line, t_mlx *mlx);

/*
**hooks & redraws
*/
int					key_hook(int keycode, void *params);
int					mouse_hook(int keycode, void *params);
void				redraw_key(t_all *all, int keycode);
void				redraw_key_position(t_all *all, int keycode);
void				redraw_key_cst(t_all *all, int keycode);
void				redraw_mouse(t_all *all, int keycode);

/*
**other
*/
int					get_line_max(t_datas **begin_list);
void				tab_clr(char ***tab);
void				print_datas(t_all **ll);
t_cst				*fill_cst(t_datas **datas);
void				format_window(int *win_x, int *win_y, int x_max, \
		int y_max);
void				ft_tabdel(char ***tabl);

#endif
