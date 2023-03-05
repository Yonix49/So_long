/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/05 13:58:37 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "string.h"

int	main(int ac, char **av)
{
	char	**tmp;
	t_data	*img;

	if (verif_namearg(ac, av) == 0 || verif_open(av) == 0)
		return (0);
	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		return (0);
	img->map = get_map(img, av);
	if (img->map == NULL)
	{
		free(img);
		return (0);
	}
	tmp = copy_map(img);
	if (verifall(tmp) == 0)
	{
		ft_free_all(img);
		ft_free(tmp);
		return (0);
	}
	ft_free(tmp);
	if (display_window(img) == -1)
		return (ft_game_over(img), -1);
	return (0);
}
