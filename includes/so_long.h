/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:44:10 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 19:38:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <mlx_int.h>

# define BUFFER_SIZE 4096

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	*window_img;
	t_img	*floor_img;
	t_img	*wall_img;
	t_img	*character_img;
	t_img	*coll_img;
	t_img	*exit_img;
}		t_data;

typedef struct s_recup
{
	char	depart;
	t_coord	coord_depart;
	char	coll;
	int		nbr_coll;
	t_coord	*coord_coll;
	char	exit;
	int		nbr_exit;
	t_coord	*coord_exit;
	char	wrong_charac;
	int		line_len;
	int		empty_line;
	int		nblines;
	int		sizeline;
	char	**map;
	int		up;
	int		down;
	int		right;
	int		left;
	int		coll_catched;
	int		nbr_move;
	t_data	data;
}		t_recup;

int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	ft_error(t_recup *recup, char *str);
void	ft_parsing_errors(t_recup *recup);
void	ft_parsing_errors2(t_recup *recup);
void	ft_initialisation(t_recup *recup);
int		get_next_line(int fd, char **line);
void	ft_map(t_recup *recup, char *str);
void	ft_copy_map(t_recup *recup, char *str);
void	ft_malloc(t_recup *recup);
int		ft_exit(t_recup *recup, char c, int i, int j);
int		ft_collectible(t_recup *recup, char c, int i, int j);
int		ft_surround(t_recup *recup);
int		ft_first_last_carac(t_recup *recup);
int		ft_rectangular(t_recup *recup);
int		ft_emptyline(t_recup *recup);
void	ft_mlx(t_recup *recup);
void	ft_mlx_init(t_recup *recup);
int		ft_draw(t_recup *recup);
void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
int		mlx_rgb_to_int(int r, int g, int b);
int		mlx_get_pixel(t_img *img, int x, int y);
int		key_press(int keycode, t_recup *recup);
int		key_release(int keycode, t_recup *recup);
int		destroy_hook(t_recup *recup);
void	actualization(t_recup *recup);
void	ft_free(t_recup *recup);
void	ft_free2(t_recup *recup);
void	shift_up(t_recup *recup, int x, int y);
void	shift_down(t_recup *recup, int x, int y);
void	shift_left(t_recup *recup, int x, int y);
void	shift_right(t_recup *recup, int x, int y);

#endif
