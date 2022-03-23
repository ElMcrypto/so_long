/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:22:53 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/22 21:59:02 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include "../get_next_line/get_next_line.h"
# define SZ 20;

typedef struct s_player
{
	void	*player_img;
	int		x;
	int		y;
}	t_player;

typedef struct s_exit
{
	void	*exit_img;
	int		x;
	int		y;
}	t_exit;

typedef struct s_collectible
{
	void	*collectible_img;
	int		x;
	int		y;
}	t_collectible;

typedef struct s_data
{
	int				len_lines;
	int				w;
	int				h;
	int				true;
	int				c_is_zero;
	void			*mlx;
	void			*img;
	void			*win;
	char			**map;
	int				rows;
	t_player		player;
	t_exit			e;
	t_collectible	c;
}	t_data;

typedef struct s_read_map
{
	int		fd;
	char	*line;
	char	*hold_map;
	char	**map;
	char	*temp;
}	t_read_map;

int		func(int key, t_data *obj);
char	**ft_split(char	const *s, char c);
void	check_element(t_data *data);
void	get_errors(t_data *data);
int		lines(char **ptr);
int		check_line(char *ln);
void	if_map(t_data *data);
int		count_c(char **map, char c);
int		set_map(t_data *data);
void	game_over(char *msg, t_data *data);
int		ft_strncmp(const char *s1, const char *s2, int from, size_t n);
void	ft_putnbr(int n);
int		close_game(int key, t_data *obj);
void	move(int x, int y, t_data *obj);
void	if_error_map_new_line(char *hold_map);
void	read_map2(int fd, char *str, char *line);
void	print_error(char *msg);
#endif
