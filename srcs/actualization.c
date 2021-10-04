/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:54:45 by user42            #+#    #+#             */
/*   Updated: 2021/10/03 17:09:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	catch_coll(t_recup *recup)
{
	int	k;

	k = 0;
	while (k < recup->nbr_coll)
	{
		if (recup->coord_coll[k].x == recup->coord_depart.x \
	&& recup->coord_coll[k].y == recup->coord_depart.y)
		{
			recup->coord_coll[k].x = -1;
			recup->coord_coll[k].y = -1;
			recup->coll_catched++;
		}
		k++;
	}
}

void	nbr_moves(t_recup *recup, int x, int y)
{
	if (recup->coord_depart.x != x || recup->coord_depart.y != y)
	{
		recup->nbr_move++;
		printf("%d\n", recup->nbr_move);
	}
}

void	actualization2(t_recup *recup, int x, int y)
{
	if (recup->up != 0)
		shift_up(recup, x, y);
	else if (recup->down != 0)
		shift_down(recup, x, y);
	else if (recup->left != 0)
		shift_left(recup, x, y);
	else if (recup->right != 0)
		shift_right(recup, x, y);
}

void	actualization(t_recup *recup)
{
	int	x;
	int	y;
	int	k;

	x = recup->coord_depart.x;
	y = recup->coord_depart.y;
	k = 0;
	actualization2(recup, x, y);
	nbr_moves(recup, x, y);
	catch_coll(recup);
	ft_draw(recup);
	while (k < recup->nbr_exit)
	{
		if (recup->coord_exit[k].x == recup->coord_depart.x \
	&& recup->coord_exit[k].y == recup->coord_depart.y)
		{
			if (recup->nbr_coll == recup->coll_catched)
			{
				printf("You won with %d moves\n", recup->nbr_move);
				mlx_destroy_window(recup->data.mlx_ptr, recup->data.mlx_win);
			}
		}
		k++;
	}	
}
