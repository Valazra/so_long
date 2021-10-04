/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 12:05:13 by user42            #+#    #+#             */
/*   Updated: 2021/10/03 17:15:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_press2(int keycode, t_recup *recup)
{
	if (keycode == 97)
	{
		recup->left = 1;
		actualization(recup);
	}
	if (keycode == 100)
	{
		recup->right = 1;
		actualization(recup);
	}
}

int	key_press(int keycode, t_recup *recup)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(recup->data.mlx_ptr, recup->data.mlx_win);
		recup->data.mlx_win = NULL;
	}	
	if (keycode == 119)
	{
		recup->up = 1;
		actualization(recup);
	}
	if (keycode == 115)
	{
		recup->down = 1;
		actualization(recup);
	}
	key_press2(keycode, recup);
	return (0);
}

int	key_release(int keycode, t_recup *recup)
{
	if (keycode == 119)
		recup->up = 0;
	if (keycode == 115)
		recup->down = 0;
	if (keycode == 97)
		recup->left = 0;
	if (keycode == 100)
		recup->right = 0;
	actualization(recup);
	return (0);
}

int	destroy_hook(t_recup *recup)
{
	mlx_destroy_window(recup->data.mlx_ptr, recup->data.mlx_win);
	recup->data.mlx_win = NULL;
	return (0);
}
