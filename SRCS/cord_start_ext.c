/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord_start_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:42:28 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/24 16:19:22 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

struct cord	cord_start(char **map, struct cord cord)
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

struct cord	cord_exit(char **map, struct cord cord)
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
struct cord	get_map_col(char **map, struct cord cord)
{
	int	i;

	i = ft_strlen(map[0]);
		i--;
	cord.col = i;
	return (cord);
}
struct cord	get_map_ligne(char **map, struct cord cord)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	cord.lig = i;

	return (cord);
}
