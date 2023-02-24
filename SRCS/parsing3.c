/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:37:55 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/23 19:01:22 by mhajji-b         ###   ########.fr       */
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
	struct cord pos;

	if (!(verif_bords(map) == 1))
	{
		write(2, "Mur Error\n", 11);
		return (0);
	}
	else if (!(verif_elem(map) == 1))
		return (0);
	else if (!(verif_map(map) == 1))
	{
		write(2, "La map n'est pas rectangulaire Error\n", 38);
		return (0);
	}
	else if (!(is_valid_path(map, cord_all(map, pos)) == 1))
	{
		write(2, "Chemin Error \n", 15);
		return (0);
	}
	return (1);
}