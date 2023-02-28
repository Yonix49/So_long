/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:57:25 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/28 16:54:14 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "so_long.h"

int	key_hook(int key_code, t_data *img)
{
	if (key_code == KEY_W && (img->map[img->t_player.player_x
			- 1][img->t_player.player_y] != '1'))
		move_image_W(key_code, img);
	else if (key_code == KEY_S && (img->map[img->t_player.player_x
				+ 1][img->t_player.player_y] != '1'))
		move_image_S(key_code, img);
	else if (key_code == KEY_A
			&& (img->map[img->t_player.player_x][img->t_player.player_y
				- 1] != '1'))
		move_image_A(key_code, img);
	else if (key_code == KEY_D
			&& (img->map[img->t_player.player_x][img->t_player.player_y
				+ 1] != '1'))
		move_image_D(key_code, img);
	else if (key_code == KEY_ESC)
		quit_esc(img);	
	return (0);
}
void 	quit_esc(t_data *img)
{
		mlx_destroy_window(img->mlx, img->win_ptr);
		exit(0);
}
void	move_image_W(int key_code, t_data *img)
{
	if (key_code == KEY_W)
	{
		if (img->map[img->t_player.player_x - 1][img->t_player.player_y] == 'E'
			&& compte_co(img) == 0)
		{
			mlx_destroy_window(img->mlx, img->win_ptr);
			exit(0);
		}
		else if (img->map[img->t_player.player_x
				- 1][img->t_player.player_y] == 'E' && compte_co(img) != 0)
			return ;
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_x -= 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		img->nb_mouvement++;
		write(1, "nb mouvement ==", 15);
		ft_putnbr_fd(img->nb_mouvement, 1);
		write(1, "\n", 1);
		set_display(img);
	}
}
void	move_image_S(int key_code, t_data *img)
{
	if (key_code == KEY_S)
	{
		if (img->map[img->t_player.player_x + 1][img->t_player.player_y] == 'E'
			&& compte_co(img) == 0)
		{
			mlx_destroy_window(img->mlx, img->win_ptr);
			exit(0);
		}
		else if (img->map[img->t_player.player_x
				+ 1][img->t_player.player_y] == 'E' && compte_co(img) != 0)
			return ;
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_x += 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		img->nb_mouvement++;
		write(1, "nb mouvement ==", 15);
		ft_putnbr_fd(img->nb_mouvement, 1);
		write(1, "\n", 1);
		set_display(img);
	}
}
void	move_image_A(int key_code, t_data *img)
{
	if (key_code == KEY_A)
	{
		if (img->map[img->t_player.player_x][img->t_player.player_y - 1] == 'E'
			&& compte_co(img) == 0)
		{
			mlx_destroy_window(img->mlx, img->win_ptr);
			exit(0);
		}
		else if (img->map[img->t_player.player_x][img->t_player.player_y
				- 1] == 'E' && compte_co(img) != 0)
			return ;
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_y -= 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		img->nb_mouvement++;
		write(1, "nb mouvement ==", 15);
		ft_putnbr_fd(img->nb_mouvement, 1);
		write(1, "\n", 1);
		set_display(img);
	}
}
void	move_image_D(int key_code, t_data *img)
{
	if (key_code == KEY_D)
	{
		if (img->map[img->t_player.player_x][img->t_player.player_y + 1] == 'E'
			&& compte_co(img) == 0)
		{
			mlx_destroy_window(img->mlx, img->win_ptr);
			exit(0);
		}
		else if (img->map[img->t_player.player_x][img->t_player.player_y
				+ 1] == 'E' && compte_co(img) != 0)
			return ;
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_y += 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		// Déplacer l'image vers le bas
		img->nb_mouvement++;
		write(1, "nb mouvement ==", 15);
		ft_putnbr_fd(img->nb_mouvement, 1);
		write(1, "\n", 1);
		set_display(img);
	}
}