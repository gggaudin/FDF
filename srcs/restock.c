/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:26:37 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/03 22:24:15 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	posy(t_env *e, int keycode)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < e->hmap)
	{
		while (j < e->lmap)
		{
			if (keycode == 126)
				e->coory[i][j] -= 20;
			else
				e->coory[i][j] += 20;
			j++;
		}
		j = 0;
		i++;
	}
	e->xstart = e->coorx[0][0];
	e->ystart = e->coory[0][0];
}

void	posx(t_env *e, int keycode)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < e->hmap)
	{
		while (j < e->lmap)
		{
			if (keycode == 124)
				e->coorx[i][j] += 20;
			else
				e->coorx[i][j] -= 20;
			j++;
		}
		j = 0;
		i++;
	}
	e->xstart = e->coorx[0][0];
	e->ystart = e->coory[0][0];
}

void	ft_zoom(t_env *e, int keycode, int flag)
{
	if (flag == 1)
		return ;
	if (keycode == 47)
	{
		if (e->xspace >= 0)
		{
			e->xspace += 2;
			e->yspace += 2;
		}
	}
	else
	{
		if (e->xspace >= 2)
		{
			e->xspace -= 2;
			e->yspace -= 2;
		}
	}
	if (e->xspace > 0)
		fill(e);
	else
		return ;
}

void	ft_chcolor(t_env *e, int keycode)
{
	if (keycode == 0)
		e->color = (int)0x00F34242;
	else if (keycode == 1)
		e->color = (int)0x00FEFEFE;
	else if (keycode == 2)
		e->color = (int)0x0032E844;
	else
	{
		e->color += 1000;
		return ;
	}
}
