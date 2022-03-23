/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrole.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:27:34 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/20 00:10:13 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fix_25lines(int row, int i, t_data *data)
{
	if (data->map[row][i] == 'C')
	{
		mlx_put_image_to_window (data->mlx, data->win, data->dark,
			i * 20, row * 20);
		mlx_put_image_to_window (data->mlx, data->win,
			data->c.collectible_img, i * 20, row * 20);
		data->c.x = i;
		data->c.y = row;
	}
}

void	set_x(t_data *data)
{
	int	row;
	int	i;

	row = 0;
	while (data->map[row])
	{
		i = 0;
		while (data->map[row][i])
		{
			if (data->map[row][i] == 'X')
			{
				mlx_put_image_to_window (data->mlx, data->win,
					data->x.enemy_img, i * 20, row * 20);
				data->c.x = i;
				data->c.y = row;
			}
			if (data->map[row][i] == '0')
				mlx_put_image_to_window (data->mlx, data->win, data->dark,
					i * 20, row * 20);
			fix_25lines(row, i, data);
			i++;
		}
		row++;
	}
}

void	mv(int x, int y, t_data *data)
{
	if (data->map[y][x] == 'P')
		game_over("enemy killed you\n", data);
	else if (data->map[data->x.y][data->x.x] == 'E')
		return ;
	else
	{
		data->map[data->x.y][data->x.x] = '0';
		data->map[y][x] = 'X';
		data->x.x = x;
		data->x.y = y;
	}
}

int	patrole(t_data *data)
{
	static int	i;
	int			x;
	int			y;

	x = rand() % data->len_lines;
	y = rand() % data->rows;
	if (data->map[y][x] == 'E')
		return (0);
	if (i == 60 && (data->map[y][x] == '0'
		|| data->map[y][x] == 'P'))
		mv(x, y, data);
	if (i == 120 && (data->map[y][x] == '0'
		|| data->map[y][x] == 'P'))
		mv(x, y, data);
	if ((i == 200) && (data->map[y][x] == '0'
		|| data->map[y][x] == 'P'))
		mv(x, y, data);
	i++;
	if (i > 220)
		i = 0;
	set_x(data);
	return (0);
}

void	print_error(char *msg)
{
	write (2, msg, ft_strlen(msg));
	exit(1);
}
