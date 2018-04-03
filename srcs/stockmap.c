/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:41:37 by ggaudin-          #+#    #+#             */
/*   Updated: 2018/04/03 22:25:10 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	stockymap(char *line, int *tab)
{
	int i;
	int j;
	int coor;

	j = 0;
	i = 0;
	while (line[j] != '\0')
	{
		coor = ft_atoi(&line[j]);
		tab[i] = (coor);
		i++;
		while (line[j] != ' ' && line[j] != '\0')
			j++;
		while (line[j] == ' ' && line[j] != '\0')
			j++;
	}
}

int		ft_stockmap(char **map, t_env *e)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	line = NULL;
	i = 0;
	j = 0;
	fd = open(*map, O_RDONLY);
	e->tabmap = (int**)malloc(sizeof(int*) * e->hmap);
	while (j < e->hmap)
	{
		get_next_line(fd, &line);
		e->tabmap[i] = (int*)malloc(sizeof(int) * e->lmap);
		stockymap(line, e->tabmap[i]);
		free(line);
		j++;
		i++;
	}
	close(fd);
	return (TRUE);
}
