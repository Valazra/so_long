/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:50:32 by user42            #+#    #+#             */
/*   Updated: 2021/10/03 16:41:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free2(t_recup *recup)
{
	mlx_destroy_image(recup->data.mlx_ptr, recup->data.window_img);
	mlx_destroy_image(recup->data.mlx_ptr, recup->data.floor_img);
	mlx_destroy_image(recup->data.mlx_ptr, recup->data.wall_img);
	mlx_destroy_image(recup->data.mlx_ptr, recup->data.character_img);
	mlx_destroy_image(recup->data.mlx_ptr, recup->data.coll_img);
	mlx_destroy_image(recup->data.mlx_ptr, recup->data.exit_img);
	mlx_destroy_display(recup->data.mlx_ptr);
	free(recup->data.mlx_ptr);
}

void	ft_free(t_recup *recup)
{
	int	i;

	i = 0;
	if (recup->map != 0)
	{
		while (i < recup->nblines)
		{
			free(recup->map[i]);
			i++;
		}
		free(recup->map);
	}
	if (recup->coord_coll)
	{
		free(recup->coord_coll);
		recup->coord_coll = NULL;
	}
	if (recup->coord_exit)
	{
		free(recup->coord_exit);
		recup->coord_exit = NULL;
	}
	ft_free2(recup);
}
