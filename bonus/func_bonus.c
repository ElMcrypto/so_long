/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:33:08 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/22 22:00:10 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fix_25(t_data *obj)
{
	if (count_c(obj->map, 'C') == 0)
		obj->c_is_zero = 1;
	if (obj->player.x == obj->x.x && obj->player.y == obj->x.y)
		game_over("oops!, YOU LOSE\n", obj);
	if (count_c(obj->map, 'C') == 0)
		obj->c_is_zero = 1;
	if (obj->c_is_zero == 1 && (obj->map[obj->player.y][obj->player.x] == 'E'))
		game_over("game over, You Win\n", obj);
	set_map(obj);
}

void	move(int x, int y, t_data *obj)
{
	static int	count;
	char		*score;

	obj->c_is_zero = 0;
	if (obj->map[obj->player.y][obj->player.x] == '1'
		|| obj->map[obj->player.y][obj->player.x] == 'E')
		obj->map[y][x] = 'P';
	else if (obj->map[obj->player.y][obj->player.x] == 'X')
		game_over("you lose!\n", obj);
	else
	{
		if (obj->true == 1)
			count++;
		obj->map[obj->player.y][obj->player.x] = 'P';
		obj->true = 0;
	}
	fix_25(obj);
	mlx_string_put(obj->mlx, obj->win, 0, 0, 0x000, "score : ");
	score = ft_itoa(count);
	mlx_string_put(obj->mlx, obj->win, 70, 0, 0x000, score);
	free (score);
}

int	func(int key, t_data *obj)
{
	int			x;
	int			y;

	x = obj->player.x;
	y = obj->player.y;
	obj->true = 0;
	if (key == 53)
		game_over("Game Over\n", obj);
	if (key == 13 || key == 2 || key == 0 || key == 1)
	{
		mlx_put_image_to_window (obj->mlx, obj->win, obj->dark, x * 20, y * 20);
		obj->map[y][x] = '0';
		if (key == 13)
			obj->player.y -= 1;
		if (key == 2)
			obj->player.x += 1;
		if (key == 0)
			obj->player.x -= 1;
		if (key == 1)
			obj->player.y += 1;
		obj->true = 1;
	}
	move(x, y, obj);
	return (0);
}

void	check_element(char **map, t_data *obj)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != '1') && (map[i][j] != '0') && (map[i][j] != 'E')
					&& (map[i][j] != 'P')
					&& (map[i][j] != 'C') && (map[i][j] != 'X'))
				game_over("error\nwrong map\n", obj);
			j++;
		}
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, int from, size_t n)
{
	size_t	i;
	size_t	j;

	i = from;
	j = 0;
	while ((i < n) && (s1[i] != '\0' || s2[j] != '\0'))
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
	}
	return (0);
}
