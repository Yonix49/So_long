/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:37:55 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/01 12:41:03 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_char_sett(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			write(2, "Error Space\n", 13);
			return (0);
		}
		i++;
	}
	return (9999);
}

int	verifall(char **map)
{
	struct cord	pos;

	if (!(verif_bords(map) == 1))
	{
		write(2, "Mur Error\n", 11);
		return (0);
	}
	else if ((verif_elem(map) == 1))
		return (0);
	else if (!(verif_map(map) == 1))
	{
		write(2, "La map n'est pas rectangulaire Error\n", 38);
		return (0);
	}
	else if (!(is_valid_path_exit(map, cord_all(map, pos)) == 1))
	{
		write(2, "Exit Error \n", 13);
		return (0);
	}
	else if (verif_co(map) == 0)
	{
		write(2, "Collectible chemin Error\n", 26);
		return (0);
	}
	return (1);
}

int	verif_co(char **map)
{
	int	i;
	int	y;

	i = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			if (map[i][y] == 'C')
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}
