/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:19:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/03 17:13:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(int *)(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *img, int x, int y, int color)
{
	char	*target;

	target = img->data + (x * img->bpp / 8 + y * img->size_line);
	*(int *)target = color;
}

int	mlx_rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	check_win(t_recup *recup)
{
	if (!recup->data.mlx_win)
		return (1);
	return (0);
}

void	ft_mlx(t_recup *recup)
{
	ft_parsing_errors(recup);
	ft_mlx_init(recup);
	ft_draw(recup);
	mlx_loop_hook(recup->data.mlx_ptr, check_win, recup);
	mlx_hook(recup->data.mlx_win, ClientMessage, \
	StructureNotifyMask, destroy_hook, recup);
	mlx_hook(recup->data.mlx_win, KeyPress, KeyPressMask, key_press, recup);
	mlx_hook(recup->data.mlx_win, KeyRelease, \
	KeyReleaseMask, key_release, recup);
	mlx_hook(recup->data.mlx_win, Expose, ExposureMask, ft_draw, recup);
	mlx_loop(recup->data.mlx_ptr);
	ft_free(recup);
}
