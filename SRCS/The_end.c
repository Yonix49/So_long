/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   The_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:45:32 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/28 18:02:06 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "so_long.h"

void free_images(t_data *img) 
{
    mlx_destroy_image(img->mlx, img->img_mur);
    mlx_destroy_image(img->mlx, img->img_exit);
    mlx_destroy_image(img->mlx, img->img_conso);
    mlx_destroy_image(img->mlx, img->img_perso);
    mlx_destroy_image(img->mlx, img->img_back);
}
