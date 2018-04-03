/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:47:35 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/03 22:37:17 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		redraw(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img);
	build(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 3)
		ft_chcolor(e, keycode);
	if (keycode == 47 || keycode == 43)
		ft_zoom(e, keycode, e->flagiso);
	if (keycode == 36)
		ft_reset(e);
	if (keycode == 53)
		exit(0);
	if (keycode == 12 || keycode == 13)
		ft_alt(e, keycode);
	if (keycode == 126 || keycode == 125)
		posy(e, keycode);
	if (keycode == 124 || keycode == 123)
		posx(e, keycode);
	if (keycode == 34)
		ft_filliso(e);
	if (keycode == 35)
		fill(e);
	redraw(e);
	return (0);
}
