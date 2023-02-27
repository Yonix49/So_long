/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/27 17:48:32 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "so_long.h"
#include "string.h"

void	move_image(int key_code, t_data *img)
{
	if (key_code == KEY_W)
		img->t_player.player_y += 1; // Déplacer l'image vers le haut
	else if (key_code == KEY_A)     // Touche A
		img->t_player.player_x -= 1;
	else if (key_code == KEY_S)
		img->t_player.player_y -= 1; // Déplacer l'image vers le bas
	else if (key_code == KEY_D)     // Touche D
		img->t_player.player_x += 1; // Déplacer l'image vers la droite
}

int	key_hook(int key_code, t_data *img)
{
	move_image(key_code, img);
	// set_display(*img, map);
	// printf("%d\n", key_code);
	return (0);
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

int	main(int ac, char **av)
{
	char **tmp;
	t_data *img;

	tmp = NULL;
	img = (t_data*)malloc(sizeof(t_data));
	img->map = NULL;
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
	display_window(img);
	// ft_free_double(map, tmp);
	return (0);
}