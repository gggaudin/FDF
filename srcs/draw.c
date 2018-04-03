/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 10:49:20 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/03 22:25:44 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_dxdy(t_calc *pts, t_env *e)
{
	int cumul;
	int k;

	cumul = pts->dx / 2;
	k = 1;
	while (k <= pts->dx)
	{
		pts->x += pts->xinc;
		cumul += pts->dy;
		if (cumul >= pts->dx)
		{
			cumul -= pts->dx;
			pts->y = pts->y + pts->yinc;
		}
		pixel_put_to_image(e, pts->x, pts->y);
		k++;
	}
}

void	ft_dydx(t_calc *pts, t_env *e)
{
	int cumul;
	int k;

	cumul = pts->dy / 2;
	k = 1;
	while (k <= pts->dy)
	{
		pts->y += pts->yinc;
		cumul += pts->dx;
		if (cumul >= pts->dy)
		{
			cumul -= pts->dy;
			pts->x = pts->x + pts->xinc;
		}
		pixel_put_to_image(e, pts->x, pts->y);
		k++;
	}
}

void	yegment(t_env *e, int i, int j)
{
	t_calc pts;

	if (i == (e->hmap - 1))
		return ;
	ft_initcalcy(&pts, e, i, j);
	pixel_put_to_image(e, pts.x, pts.y);
	if (pts.dx > pts.dy)
		ft_dxdy(&pts, e);
	else
		ft_dydx(&pts, e);
}

void	xegment(t_env *e, int i, int j)
{
	t_calc pts;

	ft_initcalcx(&pts, e, i, j);
	if (j == (e->lmap - 1))
	{
		pixel_put_to_image(e, pts.x, pts.y);
		return ;
	}
	pixel_put_to_image(e, pts.x, pts.y);
	if (pts.dx > pts.dy)
		ft_dxdy(&pts, e);
	else
		ft_dydx(&pts, e);
}

void	draw(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	e->img = mlx_new_image(e->mlx, XWIN, YWIN);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->szline,
		&e->endian);
	while (i < e->hmap)
	{
		while (j < (e->lmap))
		{
			xegment(e, i, j);
			yegment(e, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
