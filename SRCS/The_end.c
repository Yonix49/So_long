/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   The_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:45:32 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/01 12:49:28 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "so_long.h"

void	free_images(t_data *img)
{
	if (img->img_mur)
		mlx_destroy_image(img->mlx, img->img_mur);
	if (img->img_exit)
		mlx_destroy_image(img->mlx, img->img_exit);
	if (img->img_conso)
		mlx_destroy_image(img->mlx, img->img_conso);
	if (img->img_perso)
		mlx_destroy_image(img->mlx, img->img_perso);
	if (img->img_back)
		mlx_destroy_image(img->mlx, img->img_back);
	if (img->win_ptr)
	{
		mlx_clear_window(img->mlx, img->win_ptr);
		mlx_destroy_window(img->mlx, img->win_ptr);
	}
	if (img->mlx)
	{
		mlx_destroy_display(img->mlx);
		free(img->mlx);
	}
}

void	ft_game_over(t_data *img)
{
	free_images(img);
	ft_free_all(img);
}
