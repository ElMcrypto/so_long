/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:33:08 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/22 22:14:05 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_exit(t_data *data)
{
	int	count_co;

	count_co = count_c(data->map, 'C');
	if (count_co == 0)
		return (1);
	else
		return (0);
}

void	if_key(int key, t_data *obj)
{
	if (key == 13)
		obj->player.y -= 1;
	if (key == 2)
		obj->player.x += 1;
	if (key == 0)
		obj->player.x -= 1;
	if (key == 1)
		obj->player.y += 1;
}

int	func(int key, t_data *obj)
{
	int			x;
	int			y;

	x = obj->player.x;
	y = obj->player.y;
	if (key == 53)
		game_over("Game Over, You Lose\n", obj);
	if (key == 13 || key == 2 || key == 0 || key == 1)
	{
		mlx_clear_window(obj->mlx, obj->win);
		obj->map[y][x] = '0';
		if_key(key, obj);
		obj->true = 1;
	}
	else
		obj->true = 0;
	move(x, y, obj);
	return (0);
}

void	check_element(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if ((data->map[i][j] != '1') && (data->map[i][j] != '0')
				&& (data->map[i][j] != 'E')
				&& (data->map[i][j] != 'P') && (data->map[i][j] != 'C'))
				game_over("error\nwrong map\n", data);
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
