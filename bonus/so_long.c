/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:54:19 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/07 23:11:16 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "so_long.h"

char	**read_map(char *str)
{
	int		fd;
	char	*line;
	char	*hold_map;
	char	**map;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\nDon't find the map file", 29);
		exit (0);
	}
	hold_map = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			break ;
		hold_map = ft_strjoin(hold_map, line);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(hold_map, '\n');
	free(hold_map);
	return (map);
}

void generat_map(t_data *data, int row, int i, int x)
{
	if (data->map[row][i] == 'P')
	{
		mlx_put_image_to_window (data->mlx, data->win, data->player.player_img, i * 20, row * 20);
		data->player.x = i;
		data->player.y = row ;
	}
	else if (data->map[row][i] == 'C')
	{
		mlx_put_image_to_window (data->mlx, data->win, data->c.collectible_img, i * 20, row * 20);
		data->c.x = i;
		data->c.y = row;
	}
	else if (data->map[row][i] == 'E' && x == 1)
	{
		mlx_put_image_to_window (data->mlx, data->win,data->e.exit_img, i * 20, row * 20);
		data->e.x = i;
		data->e.y = row;
	}
}

int set_map (t_data *data, int x)
{
	int row;
	int i;

	row = 0;
	i = 0;
	while (data->map[row])
	{
		i = 0;
		while (data->map[row][i])
		{
			if (data->map[row][i] == '1')
				mlx_put_image_to_window (data->mlx, data->win, data->img, i*20, row*20);
			else if (data->map[row][i] == 'P' || data->map[row][i] == 'C' || data->map[row][i] == 'E')
				generat_map(data, row, i, x);
			i++;
		}
		row++;
	}
	return (row);
}

void get_data(t_data *data)
{
	int info[2];
	data->len_lines = ft_strlen(data->map[0]);
	data->w = data->len_lines * sz;
	data->h = lines(data->map) * sz;
	data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->w, data->h, "so_long by eelmoham");
	data->img = mlx_xpm_file_to_image(data->mlx, "./xpm/scull_w_20.xpm", &info[0], &info[1]);
	data->e.exit_img = mlx_xpm_file_to_image(data->mlx, "./xpm/exit_20.xpm", &info[0], &info[1]);
	data->player.player_img = mlx_xpm_file_to_image(data->mlx, "./xpm/crap_20.xpm", &info[0], &info[1]);
	data->c.collectible_img = mlx_xpm_file_to_image (data->mlx, "./xpm/fish_20.xpm", &info[0], &info[1]);
	data->rows = set_map(data, 0);
}

int	main(void)
{
	t_data data;
	
	data.map = read_map("./map/map.ber");
	//check_element(data.map);
	get_errors(data.map);
	if_map(data.map);
	get_data(&data);
	//mlx_key_hook(data.win, func, &data);
	mlx_hook(data.win, 2, 3, func, &data);
    mlx_loop(data.mlx);
}