/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:00:34 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/22 20:12:36 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

unsigned int	get_color_pixel(t_data_engine *engine, void *img, int y, int x)
{
	char	*src;
	int		color;

	engine->tmp->addr = mlx_get_data_addr(img, &engine->tmp->bpp,
			&engine->tmp->line_l, &engine->tmp->endian);
	src = engine->tmp->addr + (y * engine->tmp->line_l + x
			* (engine->tmp->bpp / 8));
	color = *(unsigned int *)src;
	return (color);
}

void	my_mlx_pixel_put(t_data_engine *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_l + x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel(t_data_engine *engine, void *img, int y, int x)
{
	int	i;
	int	j;

	i = -1;
	while (++i < TEXTURE_HEIGHT)
	{
		j = -1;
		while (++j < TEXTURE_WIDTH)
		{
			engine->element->color = get_color_pixel(engine, img, i, j);
			if (!(engine->element->color == (0xFF << 24)))
				my_mlx_pixel_put(engine, (x * TEXTURE_WIDTH) + j,
					(y * TEXTURE_WIDTH) + i, engine->element->color);
		}
	}
}

void	set_element_on_display(t_data_engine	*engine)
{
	int	y;
	int	x;

	y = -1;
	while (++y < engine->map->line)
	{
		x = -1;
		while (++x < engine->map->column)
		{
			put_pixel(engine, engine->element->ground, y, x);
			if (engine->map->map[y][x] == '1')
				put_pixel(engine, engine->element->wall, y, x);
			if (engine->map->map[y][x] == 'P')
				put_pixel(engine, engine->element->player, y, x);
			if (engine->map->map[y][x] == 'C')
				put_pixel(engine, engine->element->coin, y, x);
			if (engine->map->map[y][x] == 'E')
				put_pixel(engine, engine->element->close_door, y, x);
		}
	}
}

void	display_map(t_data_engine	*engine)
{
	engine->init->mlx = mlx_init();
	engine->img->img = mlx_new_image(engine->init->mlx, (TEXTURE_WIDTH
				* engine->map->column), (TEXTURE_HEIGHT * engine->map->line));
	engine->img->addr = mlx_get_data_addr(engine->img->img, &engine->img->bpp,
			&engine->img->line_l, &engine->img->endian);
	engine->init->window = mlx_new_window(engine->init->mlx, (TEXTURE_WIDTH
				* engine->map->column), (TEXTURE_HEIGHT * engine->map->line),
			"so_long");
	insert_sprite(engine);
	set_element_on_display(engine);
}