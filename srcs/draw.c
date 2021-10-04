/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 4021/09/27 17:01:31 by user42            #+#    #+#             */
/*   Updated: 2021/10/03 17:12:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_square(t_recup *recup, t_img *img, int x, int y)
{
	int	color;
	int	i;
	int	j;

	j = 0;
	while (j < 64)
	{
		i = 0;
		while (i < 64)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(255, 255, 255))
				mlx_draw_pixel(recup->data.window_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_sprite(t_recup *recup, int i, int j)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (k < recup->nbr_coll)
	{	
		if (recup->coord_coll[k].x == j && recup->coord_coll[k].y == i)
			draw_square(recup, recup->data.coll_img, i * 64, j * 64);
		k++;
	}
	while (l < recup->nbr_exit)
	{
		if (recup->coord_exit[l].x == j && recup->coord_exit[l].y == i)
			draw_square(recup, recup->data.exit_img, i * 64, j * 64);
		l++;
	}
	if (recup->coord_depart.x == j && recup->coord_depart.y == i)
		draw_square(recup, recup->data.character_img, i * 64, j * 64);
}

void	draw_map(t_recup *recup)
{
	int	i;
	int	j;

	j = 0;
	while (j < recup->nblines)
	{
		i = 0;
		while (i < recup->sizeline)
		{
			if (recup->map[j][i] == '1')
				draw_square(recup, recup->data.wall_img, i * 64, j * 64);
			else
				draw_square(recup, recup->data.floor_img, i * 64, j * 64);
			draw_sprite(recup, i, j);
			i++;
		}
		j++;
	}
}

int	ft_draw(t_recup *recup)
{
	draw_map(recup);
	mlx_put_image_to_window(recup->data.mlx_ptr, \
	recup->data.mlx_win, recup->data.window_img, 0, 0);
	return (0);
}
