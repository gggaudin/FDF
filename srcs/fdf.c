/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:33:09 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/03 22:25:59 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void init_val(t_env *e)
{
	e->hmap = 0;
	e->lmap = 1;
	e->xstart = 300;
	e->ystart = 300;
	e->alt = 0;
	e->flag = 0;
	e->color = (int)0x0042F3DB;
}

static void init_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, XWIN, YWIN, "fdf");
}

void build(t_env *e)
{
	draw(e);
	mlx_hook(e->win, 2, 2, (int (*)())key_hook, e);
	mlx_loop(e->mlx);
}

int	ft_fdf(char **map)
{
	t_env	e;

	init_val(&e);
	if (ft_parse(map, &e) == FALSE)
		return (FALSE);
	if (ft_stockmap(map, &e) == FALSE)
		return (FALSE);
	init_env(&e);
	fill(&e);
	ft_usage(2);
	build(&e);
	return (TRUE);
}
