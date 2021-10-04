/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:13:31 by user42            #+#    #+#             */
/*   Updated: 2021/10/01 16:37:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsing_map(t_recup *recup, char *fichier)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		ft_error(recup, "Error\nInvalid file\n");
	ft_malloc(recup);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		if (ret != 0)
			ft_copy_map(recup, str);
		if (str)
		{
			free(str);
			str = NULL;
		}
	}
	close(fd);
	ft_mlx(recup);
}

int	ft_fd(t_recup *recup, char *fichier)
{
	int	fd;

	fd = open(fichier, O_DIRECTORY);
	if (fd != -1)
		ft_error(recup, "Error\nFile is a directory\n");
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		ft_error(recup, "Error\nInvalid file\n");
	return (fd);
}

void	parsing(t_recup *recup, char *fichier)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = ft_fd(recup, fichier);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		ft_map(recup, str);
		free(str);
	}
	close(fd);
	if (recup->sizeline == 0 || recup->nblines == 0)
		ft_error(recup, "Error\nNo Map\n");
	ft_parsing_map(recup, fichier);
}

void	check_av(t_recup *recup, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
			ft_error(recup, "Error\nBad file name\n");
	}
	if (str[i + 1] == 'b' && str[i + 2] == 'e'\
	&& str[i + 3] == 'r' && str[i + 4] == '\0')
		parsing(recup, str);
	else
		ft_error(recup, "Error\nBad file name\n");
}

int	main(int ac, char **av)
{
	t_recup	recup;

	ft_initialisation(&recup);
	if (ac != 2)
		ft_error(&recup, "Error\nBad numbers of args\n");
	else
		check_av(&recup, av[1]);
	return (0);
}
