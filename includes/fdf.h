/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:43:06 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/03 22:38:05 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# define FALSE 0
# define TRUE 1
# define XWIN 1280
# define YWIN 800

typedef struct	s_calc
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		k;
	int		xinc;
	int		yinc;
	int		cumul;
}				t_calc;

typedef struct	s_env
{
	int				flagiso;
	char			*baninfo;
	char			*info;
	int				**tabmap;
	void			*mlx;
	void			*win;
	char				*data;
	int				bpp;
	int				flag;
	unsigned long	img_color;
	int				szline;
	int				endian;
	void			*img;
	int				alt;
	int				xstart;
	int				ystart;
	int				para;
	int				lmap;
	int				hmap;
	int				**coorx;
	int				**coory;
	int				xspace;
	int				yspace;
	int				color;
}				t_env;

void			ft_dispinfo(t_env *e, int keycode);
int				*stockisx(int x, int *tab, t_env *e);
int				*stockisy(int k, int *tab, int z, t_env *e);
void			ft_filliso(t_env *e);
void			ft_info(t_env *e);
void			ft_info(t_env *e);
void			ft_zoom(t_env *e, int keycode, int flag);
void			ft_para(t_env *e, int keycode, int i, int j);
void			ft_alt(t_env *e, int keycode);
void			ft_reset(t_env *e);
int				redraw(t_env *e);
void			ft_chcolor(t_env *e, int keycode);
void			pixel_put_to_image(t_env *e, int x, int y);
void			ft_initcalcy(t_calc *pts, t_env *e, int i, int j);
void			ft_initcalcx(t_calc *pts, t_env *e, int i, int j);
void			restockydown(t_env *e);
void			restockyup(t_env *e);
void			stockymap(char *line, int *tab);
int				ft_stockmap(char **map, t_env *e);
void			alt(t_env *e, int keycode);
void			posx(t_env *e, int keycode);
void			posy(t_env *e, int keycode);
float			spacelenx(t_env *e);
float			spaceleny(t_env *e);
int				key_hook(int keycode, t_env *e);
void			draw(t_env *e);
void			fill(t_env *e);
int				ft_fdf(char **map);
int				ft_parse(char **map, t_env *e);
char			**createmap(char **str);
void 			build(t_env *e);
void 			ft_usage(int mess);

#endif
