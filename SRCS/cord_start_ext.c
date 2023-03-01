/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord_start_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:42:28 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/01 15:09:24 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_cord	cord_start(char **map, t_cord cord)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		p = 0;
		while (map[i][p])
		{
			if (map[i][p] == 'P')
			{
				cord.start_x = i;
				cord.start_y = p;
			}
			p++;
		}
		i++;
	}
	return (cord);
}

t_cord	cord_exit(char **map, t_cord cord)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		p = 0;
		while (map[i][p])
		{
			if (map[i][p] == 'E')
			{
				cord.end_x = i;
				cord.end_y = p;
			}
			p++;
		}
		i++;
	}
	return (cord);
}

t_cord	get_map_col(char **map, t_cord cord)
{
	int	i;

	i = ft_strlen(map[0]);
	cord.col = i;
	return (cord);
}

t_cord	get_map_ligne(char **map, t_cord cord)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	cord.lig = i;
	return (cord);
}
