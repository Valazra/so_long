/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:13:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:25:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_texture_load(t_recup *recup, t_img **imgg, char *path)
{
	int	width;
	int	height;

	*imgg = mlx_xpm_file_to_image(recup->data.mlx_ptr, path, &width, &height);
	if (*imgg == 0)
		ft_error(recup, "Error\nProblem with mlx_xpm_file_to_image\n");
	(*imgg)->width = width;
	(*imgg)->height = height;
}

void	ft_texture_init(t_recup *recup)
{
	ft_texture_load(recup, &recup->data.floor_img, "./img/floor.xpm");
	ft_texture_load(recup, &recup->data.wall_img, "./img/wall.xpm");
	ft_texture_load(recup, &recup->data.character_img, "./img/character.xpm");
	ft_texture_load(recup, &recup->data.coll_img, "./img/donut.xpm");
	ft_texture_load(recup, &recup->data.exit_img, "./img/exit.xpm");
}

void	ft_mlx_init(t_recup *recup)
{
	int	x;
	int	y;

	x = (recup->sizeline * 64);
	y = (recup->nblines * 64);
	recup->data.mlx_ptr = mlx_init();
	if (recup->data.mlx_ptr == 0)
		ft_error(recup, "Error\nProblem with mlx_init\n");
	recup->data.mlx_win = mlx_new_window(recup->data.mlx_ptr, x, y, "so_long");
	if (recup->data.mlx_win == 0)
		ft_error(recup, "Error\nProblem with mlx_new_window\n");
	recup->data.window_img = mlx_new_image(recup->data.mlx_ptr, x, y);
	if (recup->data.window_img == 0)
		ft_error(recup, "Error\nProblem with mlx_new_image\n");
	ft_texture_init(recup);
}

void	ft_initialisation2(t_recup *recup)
{
	recup->data.mlx_ptr = NULL;
	recup->data.mlx_win = NULL;
	recup->data.window_img = NULL;
	recup->data.floor_img = NULL;
	recup->data.wall_img = NULL;
	recup->data.character_img = NULL;
	recup->data.coll_img = NULL;
	recup->data.exit_img = NULL;
}

void	ft_initialisation(t_recup *recup)
{
	recup->depart = 'x';
	recup->coll = 'x';
	recup->nbr_coll = 0;
	recup->coord_coll = 0;
	recup->exit = 'x';
	recup->nbr_exit = 0;
	recup->coord_exit = 0;
	recup->wrong_charac = 'x';
	recup->line_len = 0;
	recup->empty_line = 0;
	recup->nblines = 0;
	recup->sizeline = 0;
	recup->map = NULL;
	recup->up = 0;
	recup->down = 0;
	recup->right = 0;
	recup->left = 0;
	recup->coll_catched = 0;
	recup->nbr_move = 0;
	ft_initialisation2(recup);
}
