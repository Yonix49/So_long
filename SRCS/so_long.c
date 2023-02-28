/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/28 19:04:10 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "so_long.h"
#include "string.h"

void	display_map(char **map)
{
	int i, j;
	for (i = 0; map[i]; i++)
	{
		for (j = 0; map[i][j]; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

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



int	main(int ac, char **av)
{
	char **tmp;
	t_data *img;

	tmp = NULL;
	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		return (0);
	if (verif_open(av) == 0 || verif_namearg(ac, av) == 0)
		return (0);
	img->map = get_map(img, av);
	if (img->map == NULL)
		return (0);
	tmp = copy_map(img);
	if (verifall(tmp) == 0)
	{
		ft_free_double(img->map, tmp);
		return (0);
	}

	ft_free_double(img->map, tmp);
	free(img);
	// display_window(img);
	
	return (0);
}