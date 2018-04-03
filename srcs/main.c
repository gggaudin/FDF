/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:44:04 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/03 22:36:05 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_usage(int mess)
{
	if (mess == 1)
		ft_putendl_fd("usage: ./fdf [map]", 2);
	if (mess == 2)
	{
		ft_putendl_fd("CHANGE COLOR:A,S or D", 2);
		ft_putendl_fd("RANDOM COLOR: F", 2);
		ft_putendl_fd("ZOOM: < or >", 2);
		ft_putendl_fd("POSITION: use Arrows", 2);
		ft_putendl_fd("HEIGHT: Q or W", 2);
		ft_putendl_fd("RESET: enter", 2);
		ft_putendl_fd("ISOMETRIC: I", 2);
		ft_putendl_fd("PARALLEL: P", 2);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_fdf(&av[1]) == FALSE)
			ft_usage(1);
	}
	else
		ft_usage(1);
	return (0);
}
