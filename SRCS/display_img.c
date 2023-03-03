/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:12:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/03 13:42:57 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_image(t_data *img)
{
	img->img_mur = mlx_xpm_file_to_image(img->mlx, "Items/Snow32x32.xpm",
			&img->width, &img->height);
	img->img_exit = mlx_xpm_file_to_image(img->mlx, "Items/diamond.xpm",
			&img->width, &img->height);
	img->img_conso = mlx_xpm_file_to_image(img->mlx, "Items/piece.xpm",
			&img->width, &img->height);
	img->img_perso = mlx_xpm_file_to_image(img->mlx, "Items/perso777.xpm",
			&img->width, &img->height);
	img->img_back = mlx_xpm_file_to_image(img->mlx, "Items/background.xpm",
			&img->width, &img->height);
	if (!img->img_mur || !img->img_exit || !img->img_conso || !img->img_perso
		|| !img->img_back)
		return (0);
	return (1);
}

void	set_display(t_data *img)
{
	img = get_cord_player(img);
	img->x = 0;
	while (img->map[img->x])
	{
		img->y = 0;
		while (img->map[img->x][img->y])
		{
			put_image(img);
			img->y++;
		}
		img->x++;
	}
}

void	put_image(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->win_ptr, img->img_mur, img->y * 32,
		img->x * 32);
	if (img->map[img->x][img->y] == '0')
		mlx_put_image_to_window(img->mlx, img->win_ptr, img->img_mur, img->y
			* 32, img->x * 32);
	if (img->map[img->x][img->y] == 'E')
		mlx_put_image_to_window(img->mlx, img->win_ptr, img->img_exit, img->y
			* 32, img->x * 32);
	if (img->map[img->x][img->y] == 'C')
		mlx_put_image_to_window(img->mlx, img->win_ptr, img->img_conso, img->y
			* 32, img->x * 32);
	if (img->map[img->x][img->y] == 'P')
	{
		mlx_put_image_to_window(img->mlx, img->win_ptr, img->img_perso,
			img->t_player.player_y * 32, img->t_player.player_x * 32);
	}
	if (img->map[img->x][img->y] == '1')
		mlx_put_image_to_window(img->mlx, img->win_ptr, img->img_back, img->y
			* 32, img->x * 32);
}

int	display_window(t_data *img)
{
	img->nb_mouvement = 0;
	img->mlx = mlx_init();
	if (init_image(img) == 0)
	{
		write(2, "Loading files error\n", 21);
		return (-1);
	}
	img->cord = cord_all(img->map, img->cord);
	img = get_cord_player(img);
	img->win_ptr = mlx_new_window(img->mlx, (img->cord.col) * 32,
			(img->cord.lig) * 32, "so_long!");
	set_display(img);
	mlx_key_hook(img->win_ptr, key_hook, img);
	mlx_hook(img->win_ptr, 17, 0, mlx_loop_end, img->mlx);
	mlx_loop(img->mlx);
	ft_game_over(img);
	return (1);
}
