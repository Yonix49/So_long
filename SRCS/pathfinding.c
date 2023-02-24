/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:11:28 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/23 19:18:10 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

struct cord	cord_all(char **map, struct cord pos)
{
	pos = cord_start(map, pos);
	pos = cord_exit(map, pos);
	pos = get_map_ligne(map, pos);
	pos = get_map_col(map, pos);
	return (pos);
}

int	is_valid_path(char **map, struct cord pos)
{
	if (map[pos.start_x][pos.start_y] == '1')
		return (0);
	if (pos.start_x == pos.end_x && pos.start_y == pos.end_y)
		return (1);

	map[pos.start_x][pos.start_y] = '1';
	if (pos.start_x + 1 < pos.lig && is_valid_path(map,
			(struct cord){pos.start_x + 1, pos.start_y, pos.end_x, pos.end_y,
			pos.lig, pos.col}))
		return (1);
	if (pos.start_x - 1 >= 0 && is_valid_path(map, (struct cord){pos.start_x
			- 1, pos.start_y, pos.end_x, pos.end_y, pos.lig, pos.col}))
		return (1);
	if (pos.start_y + 1 < pos.col && is_valid_path(map,
			(struct cord){pos.start_x, pos.start_y + 1, pos.end_x, pos.end_y,
			pos.lig, pos.col}))
		return (1);
	if (pos.start_y - 1 >= 0 && is_valid_path(map, (struct cord){pos.start_x,
			pos.start_y - 1, pos.end_x, pos.end_y, pos.lig, pos.col}))
		return (1);

	return (0);
}

