/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restockb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 16:22:21 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/03 22:37:56 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_reset(t_env *e)
{
	e->xstart = 300;
	e->ystart = 300;
	e->alt = 1;
	e->color = (int)0x0042F3DB;
	e->xspace = 20;
	e->yspace = 20;
	fill(e);
}

void	ft_alt(t_env *e, int keycode)
{
	if (keycode == 13)
		e->alt += 5;
	else
		e->alt -= 5;
}
