/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filliso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 23:10:53 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/03 22:26:03 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*stockisx(int x, int *tab, t_env *e)
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

int		*stockisy(int k, int *tab, int z, t_env *e)
{
	int j;

	j = 0;
	while (j < e->lmap)
	{
		tab[j] = (z - (e->tabmap[k][j]));
		z = z + e->yspace;
		j++;
	}
	return (tab);
}

void	ft_filliso(t_env *e)
{
	int i;
	int x;
	int z;

	i = 0;
	e->flagiso = 1;
	x = e->xstart;
	z = e->ystart;
	if (!e->xspace && !e->yspace)
	{
		e->xspace = 20;
		e->yspace = 20;
	}
	while (i < e->hmap)
	{
		e->coorx[i] = (int*)malloc(sizeof(int) * (e->lmap));
		e->coory[i] = (int*)malloc(sizeof(int) * (e->lmap));
		e->coorx[i] = stockisx(x, e->coorx[i], e);
		e->coory[i] = stockisy(i, e->coory[i], z, e);
		z = z + e->yspace;
		x = x - e->xspace;
		i++;
	}
}
