/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/27 14:59:04 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "so_long.h"
#include "string.h"


t_data	move_image(int key_code, t_data img)
{
	img.y = 0;
	img.x = 0;
	if (key_code == KEY_W)
		img.y -= 32;            // Déplacer l'image vers le haut
	else if (key_code == KEY_A) // Touche A
			img.x -= 32;
	else if (key_code == KEY_S)
		img.y += 32;            // Déplacer l'image vers le bas
	else if (key_code == KEY_D) // Touche D
		img.x += 32; // Déplacer l'image vers la droite
}
int	key_hook(int key_code, t_data img, char **map)
{
	img = move_image(key_code, img);
	
	printf("%d\n", key_code);
	printf("")
	// img = get_cord_player(img, map);                                         
	// 	// Déplacer l'image en fonction de la touche enfoncée
	// mlx_put_image_to_window(img.mlx, img.win_ptr, img.img_perso, img.x * 32,
			// img.y * 32); // Afficher l'image à sa nouvelle position
	return (0);
}

t_data	get_cord_player(t_data img, char **map)
{
	int	x;
	int	y;
	(void)(img);
	x = 0;
	while (map[x])
	{
		y = 0; 
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				img.t_player.player_x = x;
				img.t_player.player_x = y;
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
	char **map;
	t_data img;

	tmp = NULL;
	map = NULL;

	if (verif_open(av) == 0 || verif_namearg(ac, av) == 0)
		return (0);
	map = get_map(map, av);
	if (map == NULL)
		return (0);
	tmp = copy_map(map, img);
	if (verifall(tmp) == 0)
	{
		ft_free_double(map, tmp);
		return (0);
	}


	display_window(img, map);
	ft_free_double(map, tmp);
	return (0);
}