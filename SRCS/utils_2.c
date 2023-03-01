/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:07:18 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/03/01 12:54:29 by mhajji-b         ###   ########.fr       */
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
