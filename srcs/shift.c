/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:03:41 by user42            #+#    #+#             */
/*   Updated: 2021/10/01 15:00:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shift_up(t_recup *recup, int x, int y)
{
	if (recup->map[x - 1][y] == '0')
		recup->coord_depart.x -= 1;
}

void	shift_down(t_recup *recup, int x, int y)
{
	if (recup->map[x + 1][y] == '0')
	{
		recup->coord_depart.x += 1;
	}
}

void	shift_right(t_recup *recup, int x, int y)
{
	if (recup->map[x][y + 1] == '0')
		recup->coord_depart.y += 1;
}

void	shift_left(t_recup *recup, int x, int y)
{
	if (recup->map[x][y - 1] == '0')
		recup->coord_depart.y -= 1;
}
