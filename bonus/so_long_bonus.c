/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:54:19 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/16 21:03:22 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**read_map(char *str)
{
	char	*line;
	char	*hold_map;
	char	**map;
	char	*temp;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		game_over("Error : Don't find the map file", map);
	hold_map = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			break ;
		temp = hold_map;
		hold_map = ft_strjoin(hold_map, line);
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	map = ft_split(hold_map, '\n');
	free (hold_map);
	return (map);
}

void	generat_map(t_data *data, int row, int i, int x)
{
	if (data->map[row][i] == 'P')
	{
		mlx_put_image_to_window (data->mlx, data->win, data->player.player_img,
			i * 20, row * 20);
		data->player.x = i;
		data->player.y = row ;
	}
	else if (data->map[row][i] == 'X')
	{
		mlx_put_image_to_window (data->mlx, data->win, data->x.enemy_img,
			i * 20, row * 20);
		data->x.x = i;
		data->x.y = row;
	}
	else if (data->map[row][i] == 'E')
	{
		if (x == 1)
			mlx_put_image_to_window (data->mlx, data->win, data->e.exit_img,
				i * 20, row * 20);
		else
			mlx_put_image_to_window (data->mlx, data->win, data->img,
				i * 20, row * 20);
		data->e.x = i;
		data->e.y = row;
	}
}

int	set_map(t_data *data)
{
	int	row;
	int	i;

	row = 0;
	i = 0;
	while (data->map[row])
	{
		i = 0;
		while (data->map[row][i])
		{
			if (data->map[row][i] == '1')
				mlx_put_image_to_window (data->mlx, data->win, data->img,
					i * 20, row * 20);
			else if (data->map[row][i] == 'P' || data->map[row][i] == 'C' ||
				data->map[row][i] == 'E' || data->map[row][i] == 'X')
				generat_map(data, row, i, data->c_is_zero);
			i++;
		}
		row++;
	}
	return (row);
}

void	get_data(t_data *data)
{
	int	i[2];

	data->len_lines = ft_strlen(data->map[0]);
	data->w = data->len_lines * SZ;
	data->h = lines(data->map) * SZ;
	data->mlx = mlx_init();
	data->dark = mlx_xpm_file_to_image(data->mlx, "../x/DARK.xpm",
			&i[0], &i[1]);
	data->win = mlx_new_window(data->mlx, data->w, data->h, "eelmoham");
	data->img = mlx_xpm_file_to_image(data->mlx, "../x/w.xpm", &i[0], &i[1]);
	data->e.exit_img = mlx_xpm_file_to_image(data->mlx, "../x/e.xpm",
			&i[0], &i[1]);
	data->player.player_img = mlx_xpm_file_to_image(data->mlx, "../x/p.xpm",
			&i[0], &i[1]);
	data->c.collectible_img = mlx_xpm_file_to_image (data->mlx, "../x/1.xpm",
			&i[0], &i[1]);
	data->x.enemy_img = mlx_xpm_file_to_image(data->mlx, "../x/x.xpm",
			&i[0], &i[0]);
	data->rows = set_map(data);
}

int	main(int ar, char **av)
{
	t_data	data;

	if (ar != 2)
	{
		write(2, "Wrong argument\n", 15);
		exit(1);
	}
	if (ft_strncmp(av[1], ".ber", ft_strlen(av[1]) - 4, ft_strlen(av[1])) != 0)
	{
		write(2, "path map file should be like : \n\t\t\t\texemple.ber\n", 48);
		exit(1);
	}
	data.map = read_map(av[1]);
	if (!data.map)
		return (0);
	check_element(data.map);
	get_errors(data.map);
	if_map(data.map);
	get_data(&data);
	mlx_string_put(data.mlx, data.win, 0, 0, 0x000, "scoret :0");
	mlx_loop_hook(data.mlx, animation, &data);
	mlx_hook(data.win, 2, 3, func, &data);
	mlx_hook(data.win, 17, 0, close_game, &data);
	mlx_loop(data.mlx);
}
