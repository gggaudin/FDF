/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:39:10 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/03 22:24:51 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*stockx(int x, int *tab, t_env *e)
{
	int i;

	i = 0;
	while (i < e->lmap)
	{
		tab[i] = x;
		x = x + e->xspace;
		i++;
	}
	return (tab);
}

int		*stocky(int k, int *tab, int z, t_env *e)
{
	int j;

	j = 0;
	while (j < e->lmap)
	{
		tab[j] = (z - (e->tabmap[k][j]));
		j++;
	}
	return (tab);
}

float	spacelenx(t_env *e)
{
	int xspace;

	xspace = ((XWIN - (2 * e->xstart)) / (e->lmap - 1));
	return (xspace);
}

float	spaceleny(t_env *e)
{
	int yspace;

	if (e->hmap < 2)
	{
		yspace = 0;
		e->ystart = YWIN / 2;
	}
	else
		yspace = (double)((YWIN - (2 * e->ystart)) / (e->hmap - 1));
	return (yspace);
}

void	fill(t_env *e)
{
	int i;
	int x;
	int z;

	i = 0;
	e->flagiso = 0;
	x = e->xstart;
	z = e->ystart;
	e->coorx = (int**)malloc(sizeof(int*) * (e->hmap));
	e->coory = (int**)malloc(sizeof(int*) * (e->hmap));
	while (i < e->hmap)
	{
		e->coorx[i] = (int*)malloc(sizeof(int) * (e->lmap));
		e->coory[i] = (int*)malloc(sizeof(int) * (e->lmap));
		e->coorx[i] = stockx(x, e->coorx[i], e);
		e->coory[i] = stocky(i, e->coory[i], z, e);
		z = z + e->yspace;
		x = x - (e->xspace / 2);
		i++;
	}
}
