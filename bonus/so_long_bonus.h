/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:22:53 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/16 21:04:34 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

typedef struct s_enemy
{
	void	*enemy_img;
	int		x;
	int		y;
}	t_x;

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
	void			*dark;
	char			**map;
	int				rows;
	t_player		player;
	t_exit			e;
	t_collectible	c;
	t_x				x;
}	t_data;

int		func(int key, t_data *obj);
char	**ft_split(char	const *s, char c);
void	check_element(char **map);
void	get_errors(char **map);
int		lines(char **ptr);
int		check_line(char *ln);
void	if_map(char **mp);
int		count_c(char **map, char c);
void	game_over(char *msg, char **map);
int		ft_strncmp(const char *s1, const char *s2, int from, size_t n);
int		lennbr(int n);
char	*ft_itoa(int n);
int		animation(t_data *data);
int		patrole(t_data *data);
int		set_map(t_data *data);
int		close_game(int key, t_data *obj);
#endif
