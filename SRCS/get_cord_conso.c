/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cord_conso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:48:42 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/01 12:04:30 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "string.h"

t_data	*get_cord_player(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	while (img->map[x])
	{
		y = 0;
		while (img->map[x][y])
		{
			if (img->map[x][y] == 'P')
			{
				img->t_player.player_x = x;
				img->t_player.player_y = y;
				return (img);
			}
			y++;
		}
		x++;
	}
	return (img);
}

int	compte_co(t_data *img)
{
	int	i;
	int	y;

	img->conso = 0;
	i = 0;
	while (img->map[i])
	{
		y = 0;
		while (img->map[i][y])
		{
			if (img->map[i][y] == 'C')
				img->conso++;
			y++;
		}
		i++;
	}
	return (img->conso);
}
