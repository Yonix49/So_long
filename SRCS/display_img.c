/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:12:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/24 18:01:45 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "so_long.h"

t_data	init_image(t_data img, char **map)
{
	img.img_mur = mlx_xpm_file_to_image(img.mlx, "Items/Snow32x32.xpm",
			&img.width, &img.height);
	img.img_exit = mlx_xpm_file_to_image(img.mlx, "Items/Exit_Fontaine.xpm",
			&img.width, &img.height);
	img.img_conso = mlx_xpm_file_to_image(img.mlx, "Items/conso.xpm",
			&img.width, &img.height);
	img.img_perso = mlx_xpm_file_to_image(img.mlx, "Items/perso.xpm",
			&img.width, &img.height);
	img.img_back = mlx_xpm_file_to_image(img.mlx, "Items/background.xpm",
			&img.width, &img.height);
	img.cord = cord_all(map, img.cord);
	img.x = 0;
	return (img);
}

void	set_display(t_data img, char **map)
{
	while (map[img.x])
	{
		img.y = 0;
		while (map[img.x][img.y])
		{
			mlx_put_image_to_window(img.mlx, img.win_ptr, img.img_mur, img.y
					* 32, img.x * 32);
			if (map[img.x][img.y] == '0')
				mlx_put_image_to_window(img.mlx, img.win_ptr, img.img_mur, img.y
						* 32, img.x * 32);
			if (map[img.x][img.y] == 'E')
				mlx_put_image_to_window(img.mlx, img.win_ptr, img.img_exit,
						img.y * 32, img.x * 32);
			if (map[img.x][img.y] == 'C')
				mlx_put_image_to_window(img.mlx, img.win_ptr, img.img_conso,
						img.y * 32, img.x * 32);
			if (map[img.x][img.y] == 'P')
			{
				mlx_put_image_to_window(img.mlx, img.win_ptr, img.img_perso,
						img.y * 32, img.x * 32);
			}
			if (map[img.x][img.y] == '1')
				mlx_put_image_to_window(img.mlx, img.win_ptr, img.img_back,
						img.y * 32, img.x * 32);
			img.y++;
		}
		img.x++;
	}
}

void	display_window(t_data img, char **map)
{
	img.mlx = mlx_init();
	img = init_image(img, map);
	img.win_ptr = mlx_new_window(img.mlx, (img.cord.col) * 32, (img.cord.lig)
			* 32, "so_long!");
	set_display(img, map);
	mlx_key_hook(img.win_ptr, key_hook, map);
	mlx_loop(img.mlx);
}