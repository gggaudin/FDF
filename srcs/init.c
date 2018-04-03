/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 15:44:07 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/03 22:34:21 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put_to_image(t_env *e, int x, int y)
{
	int coor;

	coor = (x * (e->bpp / 8))  + (y * e->szline);
	if (((x < XWIN && x > 0) && (y < YWIN && y > 0)))
	{
		e->data[coor + 2] = (char)e->color;
		e->data[coor + 1] = (char)(e->color >> 8);
		e->data[coor] = (char)(e->color >> 16);
	}
}

void	ft_initcalcy(t_calc *pts, t_env *e, int i, int j)
{
	pts->x = e->coorx[i][j];
	if (e->tabmap[i][j] != 0)
	{
		if (e->tabmap[i][j] > 0)
			pts->y = e->coory[i][j] - e->alt;
		else if (e->tabmap[i][j] < 0)
			pts->y = e->coory[i][j] + e->alt;
	}
	else
		pts->y = e->coory[i][j];
	pts->dx = e->coorx[i + 1][j] - pts->x;
	if (e->tabmap[i + 1][j] != 0)
	{
		if (e->tabmap[i + 1][j] > 0)
			pts->dy = (e->coory[i + 1][j] - e->alt) - pts->y;
		else if (e->tabmap[i + 1][j] < 0)
			pts->dy = (e->coory[i + 1][j] + e->alt) - pts->y;
	}
	else
		pts->dy = e->coory[i + 1][j] - pts->y;
	pts->xinc = (pts->dx > 0) ? 1 : -1;
	pts->yinc = (pts->dy > 0) ? 1 : -1;
	pts->dx = abs(pts->dx);
	pts->dy = abs(pts->dy);
}

void	ft_initcalcx(t_calc *pts, t_env *e, int i, int j)
{
	pts->x = e->coorx[i][j];
	if (e->tabmap[i][j] != 0)
	{
		if (e->tabmap[i][j] > 0)
			pts->y = e->coory[i][j] - e->alt;
		else if (e->tabmap[i][j] < 0)
			pts->y = e->coory[i][j] + e->alt;
	}
	else
		pts->y = e->coory[i][j];
	pts->dx = e->coorx[i][j + 1] - pts->x;
	if (e->tabmap[i][j + 1] != 0)
	{
		if (e->tabmap[i][j + 1] > 0)
			pts->dy = (e->coory[i][j + 1] - e->alt) - pts->y;
		else if (e->tabmap[i][j + 1] < 0)
			pts->dy = (e->coory[i][j + 1] + e->alt) - pts->y;
	}
	else
		pts->dy = (e->coory[i][j + 1]) - pts->y;
	pts->xinc = (pts->dx > 0) ? 1 : -1;
	pts->yinc = (pts->dy > 0) ? 1 : -1;
	pts->dx = abs(pts->dx);
	pts->dy = abs(pts->dy);
}
