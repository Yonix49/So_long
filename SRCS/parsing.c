/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:27:22 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/01 12:36:17 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_bords(char **map)
{
	int	i;
	int	p;

	p = 0;
	i = 0;
	while (map[p])
		p++;
	p--;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' || map[p][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	verif_map(char **map)
{
	int	i;
	int	first_line_length;

	first_line_length = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != first_line_length)
			return (0);
		i++;
	}
	return (1);
}

int	verif_elem(char **map)
{
	int	item;
	int	exit;
	int	start;

	start = 0;
	exit = 0;
	item = 0;
	if (verif_elem_2(map, item, exit, start) == 1)
	{
		write(2, "Erreur Element\n", 16);
		return (1);
	}
	return (0);
}

int	verif_elem_2(char **map, int item, int exit, int start)
{
	int	p;
	int	i;

	i = 0;
	while (map[i])
	{
		p = 0;
		while (map[i][p])
		{
			if (map[i][p] == 'P')
				start++;
			if (map[i][p] == 'C')
				item++;
			if (map[i][p] == 'E')
				exit++;
			if (map[i][p] != 'P' && map[i][p] != 'C' && map[i][p] != 'E'
				&& map[i][p] != '0' && map[i][p] != '1')
				return (1);
			p++;
		}
		i++;
	}
	if (!(exit == 1) || !(item >= 1) || !(start == 1))
		return (1);
	return (0);
}
