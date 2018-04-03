/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 13:38:20 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/03 15:41:00 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check(char *line)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if ((line[i] < '0' || line[i] > '9') && (line[i] != '-'
					&& line[i] != ' '))
			return (FALSE);
		if (line[i] == '-' && (line[i + 1] < '0' || line[i + 1] > '9'
					|| line[i + 1] == '\0'))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		nbcoor(char *line)
{
	size_t	i;
	int		nb;

	i = 0;
	nb = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ' && line[i] != '\0')
			i++;
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'
				|| line[i] == '+')
			nb++;
		while (line[i] != ' ' && line[i] != '\0')
			i++;
	}
	if (nb < 2)
		return (FALSE);
	return (nb);
}

int		ft_parse(char **map, t_env *e)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(*map, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (check(line) == FALSE)
			return (FALSE);
		if (e->lmap == 1)
			e->lmap = nbcoor(line);
		if (nbcoor(line) != e->lmap)
			return (FALSE);
		e->hmap++;
		free(line);
	}
	if (e->lmap < 2 && e->hmap < 2)
		return (FALSE);
	close(fd);
	e->xspace = 20;
	e->yspace = 20;
	return (TRUE);
}
