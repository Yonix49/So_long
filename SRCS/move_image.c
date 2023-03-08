/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:57:25 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/08 08:21:28 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key_code, t_data *img)
{
	if (key_code == KEY_W && (img->map[img->t_player.player_x
				- 1][img->t_player.player_y] != '1'))
		move_image_w(img);
	else if (key_code == KEY_S && (img->map[img->t_player.player_x
				+ 1][img->t_player.player_y] != '1'))
		move_image_s(img);
	else if (key_code == KEY_A
		&& (img->map[img->t_player.player_x][img->t_player.player_y
			- 1] != '1'))
		move_image_a(img);
	else if (key_code == KEY_D
		&& (img->map[img->t_player.player_x][img->t_player.player_y
			+ 1] != '1'))
		move_image_d(img);
	else if (key_code == KEY_ESC)
		quit_esc(img);
	return (0);
}

void	move_image_w(t_data *img)
{
	if (img->map[img->t_player.player_x - 1][img->t_player.player_y] == 'E'
		&& compte_co(img) == 0)
	{
		write(1, "Good job well played you finish this map with ", 46);
		img->nb_mouvement++;
		print_mouvement(img);
		write(1, "Wanna retry ?", 13);
		ft_game_over(img);
		exit(0);
	}
	else if (img->map[img->t_player.player_x - 1][img->t_player.player_y] == 'E'
			&& compte_co(img) != 0)
		return ;
	img->map[img->t_player.player_x][img->t_player.player_y] = '0';
	img->t_player.player_x -= 1;
	img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
	img->nb_mouvement++;
	print_mouvement(img);
	set_display(img);
}

void	move_image_s(t_data *img)
{
	if (img->map[img->t_player.player_x + 1][img->t_player.player_y] == 'E'
		&& compte_co(img) == 0)
	{
		write(1, "Good job well played you finish this map with ", 46);
		img->nb_mouvement++;
		print_mouvement(img);
		write(1, "Wanna retry ?", 13);
		ft_game_over(img);
		exit(0);
	}
	else if (img->map[img->t_player.player_x + 1][img->t_player.player_y] == 'E'
			&& compte_co(img) != 0)
		return ;
	img->map[img->t_player.player_x][img->t_player.player_y] = '0';
	img->t_player.player_x += 1;
	img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
	img->nb_mouvement++;
	print_mouvement(img);
	set_display(img);
}

void	move_image_a(t_data *img)
{
	if (img->map[img->t_player.player_x][img->t_player.player_y - 1] == 'E'
		&& compte_co(img) == 0)
	{
		write(1, "Good job well played you finish this map with ", 46);
		img->nb_mouvement++;
		print_mouvement(img);
		write(1, "Wanna retry ?", 13);
		ft_game_over(img);
		exit(0);
	}
	else if (img->map[img->t_player.player_x][img->t_player.player_y - 1] == 'E'
			&& compte_co(img) != 0)
		return ;
	img->map[img->t_player.player_x][img->t_player.player_y] = '0';
	img->t_player.player_y -= 1;
	img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
	img->nb_mouvement++;
	print_mouvement(img);
	set_display(img);
}

void	move_image_d(t_data *img)
{
	if (img->map[img->t_player.player_x][img->t_player.player_y + 1] == 'E'
		&& compte_co(img) == 0)
	{
		write(1, "Good job well played you finish this map with ", 46);
		img->nb_mouvement++;
		print_mouvement(img);
		write(1, "Wanna retry ?", 13);
		ft_game_over(img);
		exit(0);
	}
	else if (img->map[img->t_player.player_x][img->t_player.player_y + 1] == 'E'
			&& compte_co(img) != 0)
		return ;
	img->map[img->t_player.player_x][img->t_player.player_y] = '0';
	img->t_player.player_y += 1;
	img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
	img->nb_mouvement++;
	print_mouvement(img);
	set_display(img);
}
