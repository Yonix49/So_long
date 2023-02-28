/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/28 15:03:21 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "so_long.h"
#include "string.h"
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
void display_map(char **map)
{
    int i, j;

    for (i = 0; map[i]; i++)
    {
        for (j = 0; map[i][j]; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
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
int	compte_co(t_data *img)
{
	int	i;
	int	y;
	img->conso = 0;
	i = 0;
	while (img->map[i])
	{
		y = 0;
		while (img->map[i][y])
		{
			if (img->map[i][y] == 'C')
				img->conso++;
			y++;
		}
		i++;
	}
	return(img->conso);
}
void	move_image(int key_code, t_data *img)
{
	if (key_code == KEY_W)
	{
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_x -= 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		display_map(img->map);
		set_display(img);
			// display_window(img);

	}
	if (key_code == KEY_S)
	{
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_x += 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P'; 
		display_map(img->map);
		set_display(img);
			// display_window(img);

	}
	if (key_code == KEY_A)
	{
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_y -= 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P';
		display_map(img->map);
		set_display(img);
			// display_window(img);

	}
	if (key_code == KEY_D)
	{
		img->map[img->t_player.player_x][img->t_player.player_y] = '0';
		img->t_player.player_y += 1;
		img->map[img->t_player.player_x][img->t_player.player_y] = 'P'; // Déplacer l'image vers le bas
		display_map(img->map);
		set_display(img); 
			// display_window(img);
    
	}
}
int	key_hook(int key_code, t_data *img)
{
	img  = get_cord_player(img);
	if (key_code == KEY_W
			&& (img->map[img->t_player.player_x - 1][img->t_player.player_y] != '1'))
	{
		move_image(key_code, img);
	}
	else if (key_code == KEY_S
			&& (img->map[img->t_player.player_x + 1][img->t_player.player_y] != '1'))
	{
		move_image(key_code, img);                 
	}
	else if (key_code == KEY_A && (img->map[img->t_player.player_x][img->t_player.player_y - 1] != '1'))
	{
				move_image(key_code, img);                

	} // Touche A
	else if (key_code == KEY_D && (img->map[img->t_player.player_x
				][img->t_player.player_y + 1] != '1'))
	{
		 		move_image(key_code, img);                 
	}
	return (0);
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
	compte_co(img);
	display_window(img);
	ft_free_double(img->map, tmp);
	return (0);
}