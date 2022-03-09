/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:22:53 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/07 22:50:21 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <mlx.h>
#include "../get_next_line/get_next_line.h"
#define sz 20;

typedef struct  s_player
{
	void *player_img;
	int x;
	int y;
}t_player;

typedef struct  s_exit
{
	void *exit_img;
	int x;
	int y;
}t_exit;

typedef struct  s_collectible
{
	void *collectible_img;
	int x;
	int y;
}t_collectible;

typedef struct s_data
{
	int len_lines;
	int w;
	int h;
	void *mlx;
	void *img;
	void *win;
	char **map;
	int rows;
	t_player player;
	t_exit e;
	t_collectible c;
}t_data;

int     func(int key, t_data *obj);
char	**ft_split(char	const *s, char c);
void	check_element(char **map);
void    get_errors (char **map);
int     lines(char **ptr);
int		check_line(char *ln);
void	if_map (char **mp);
int		count_c (char **map , char c);
int		set_map (t_data *data, int x);

#endif