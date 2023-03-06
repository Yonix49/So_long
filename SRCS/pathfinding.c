/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:11:28 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/06 19:42:07 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_cord	cord_all(char **map, t_cord pos)
{
	pos = cord_start(map, pos);
	pos = cord_exit(map, pos);
	pos = get_map_ligne(map, pos);
	pos = get_map_col(map, pos);
	return (pos);
}

int	flood_fill_2(int x, int y, char **map)
{
	if (map[x - 1][y] == 'F')
		return (0);
	if (map[x + 1][y] == 'F')
		return (0);
	if (map[x][y - 1] == 'F')
		return (0);
	if (map[x][y + 1] == 'F')
		return (0);
	return (1);
}

void	flood_fill(int x, int y, t_cord pos, char **map)
{
	if (x < 0 || y < 0 || x >= pos.lig || y >= pos.col)
	{
		return ;
	}
	if (map[x][y] == '1' || map[x][y] == 'E' || map[x][y] == 'F')
		return ;
	map[x][y] = 'F';
	flood_fill(x + 1, y, pos, map);
	flood_fill(x - 1, y, pos, map);
	flood_fill(x, y + 1, pos, map);
	flood_fill(x, y - 1, pos, map);
}
