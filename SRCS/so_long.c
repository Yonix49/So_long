/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/27 20:25:02 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "so_long.h"
#include "string.h"

void	move_image(int key_code, t_data *img)
{
	printf("%i\n", img->map[img->t_player.player_x][img->t_player.player_y]);
	if (key_code == KEY_W
		&& (img->map[img->t_player.player_x][img->t_player.player_y
			+ 1] != '1'))
	{
		printf("Error");
		printf("%i\n",
				img->map[img->t_player.player_x][img->t_player.player_y]);
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_y += 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		set_display(img); // Déplacer l'image vers le haut
	}
	else if (key_code == KEY_A && (img->map[img->t_player.player_y
				- 1][img->t_player.player_x] != '1'))
	{
		printf("Error");
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_x -= 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		set_display(img);
	} // Touche A
	else if (key_code == KEY_S
			&& (img->map[img->t_player.player_x][img->t_player.player_y
				- 1] != '1'))
	{
		printf("Error");
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_y -= 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		set_display(img); // Déplacer l'image vers le bas
	}
	else if (key_code == KEY_D && (img->map[img->t_player.player_x
				+ 1][img->t_player.player_y] != '1'))
	{
		printf("Error");
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_x += 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		set_display(img); // Déplacer l'image vers le bas
	}                     // Touche D
}

int	key_hook(int key_code, t_data *img)
{
	// img = get_cord_player(img);
	(void)(img);
	if (key_code == KEY_W || key_code == KEY_A || key_code == KEY_S
		|| key_code == KEY_D)
	{
		move_image(key_code, img);
	}
	if (key_code == KEY_W
			&& (img->map[img->t_player.player_x][img->t_player.player_y
				+ 1] != '1'))
	{
		printf("Error");
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_y += 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		set_display(img); // Déplacer l'image vers le haut
	}
	else if (key_code == KEY_A && (img->map[img->t_player.player_y
				- 1][img->t_player.player_x] != '1'))
	{
		printf("Error");
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_x -= 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		set_display(img);
	} // Touche A
	else if (key_code == KEY_S
			&& (img->map[img->t_player.player_x][img->t_player.player_y
				- 1] != '1'))
	{
		printf("Error");
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_y -= 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		set_display(img); // Déplacer l'image vers le bas
	}
	else if (key_code == KEY_D && (img->map[img->t_player.player_x
				+ 1][img->t_player.player_y] != '1'))
	{
		printf("Error");
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_x += 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		set_display(img); // Déplacer l'image vers le bas
	}                     // Touche D
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
	img = (t_data *)malloc(sizeof(t_data));
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
	ft_free_double(img->map, tmp);
	return (0);
}