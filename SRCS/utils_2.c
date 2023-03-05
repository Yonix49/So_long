/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:07:18 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/05 13:59:13 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit_esc(t_data *img)
{
	ft_game_over(img);
	exit(0);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	print_mouvement(t_data *img)
{
	write(1, "nb mouvement == ", 16);
	ft_putnbr_fd(img->nb_mouvement, 1);
	write(1, "\n", 1);
}
