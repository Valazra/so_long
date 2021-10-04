/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:50:51 by user42            #+#    #+#             */
/*   Updated: 2021/10/01 16:29:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_collectible(t_recup *recup, char c, int i, int j)
{
	static int	k = 0;

	if (c == 'C')
	{
		if (recup->coll == 'x')
			recup->coll = c;
		recup->coord_coll[k].x = i;
		recup->coord_coll[k].y = j;
		k++;
		return (1);
	}
	return (0);
}

int	ft_exit(t_recup *recup, char c, int i, int j)
{
	static int	k = 0;

	if (c == 'E')
	{
		if (recup->exit == 'x')
			recup->exit = c;
		recup->coord_exit[k].x = i;
		recup->coord_exit[k].y = j;
		k++;
		return (1);
	}
	return (0);
}

int	ft_first_last_carac(t_recup *recup)
{
	int	i;
	int	j;

	i = 0;
	while (i < recup->nblines - 1)
	{
		j = 0;
		if (recup->map[i][j] != '1')
			return (1);
		while (recup->map[i][j] != '\0')
			j++;
		j--;
		if (recup->map[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_rectangular(t_recup *recup)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	while (i < recup->nblines)
	{
		j = 0;
		size = 0;
		while (recup->map[i][j] != '\0')
		{
			size++;
			j++;
		}
		if (size != recup->sizeline)
			return (1);
		i++;
	}
	return (0);
}

int	ft_emptyline(t_recup *recup)
{
	int	i;

	i = 0;
	while (i < recup->nblines)
	{
		if (recup->map[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}
