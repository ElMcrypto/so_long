/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:54:19 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/20 23:59:09 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *str)
{
	t_read_map	rd;

	rd.fd = open(str, O_RDONLY);
	if (rd.fd == -1)
		print_error("error\nmap not found.\n");
	rd.hold_map = ft_strdup("");
	rd.line = get_next_line(rd.fd);
	if (!rd.line)
		print_error("error\nWRONG MAP.\n");
	if (rd.line[0] == '\n')
		print_error("error\nWRONG MAP.\n");
	while (rd.line)
	{
		if (rd.line[0] == '\n')
			break ;
		rd.temp = rd.hold_map;
		rd.hold_map = ft_strjoin(rd.hold_map, rd.line);
		free(rd.line);
		free(rd.temp);
		rd.line = get_next_line(rd.fd);
	}
	if_error_map_new_line(rd.hold_map);
	rd.map = ft_split(rd.hold_map, '\n');
	free (rd.hold_map);
	return (rd.map);
}

void	generat_map(t_data *data, int row, int i)
{
	if (data->map[row][i] == 'P')
	{
		mlx_put_image_to_window (data->mlx, data->win, data->player.player_img,
			i * 20, row * 20);
		data->player.x = i;
		data->player.y = row ;
	}
	else if (data->map[row][i] == 'C')
	{
		mlx_put_image_to_window (data->mlx, data->win, data->c.collectible_img,
			i * 20, row * 20);
		data->c.x = i;
		data->c.y = row;
	}
	else if (data->map[row][i] == 'E')
	{
		mlx_put_image_to_window (data->mlx, data->win, data->e.exit_img,
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
				data->map[row][i] == 'E')
				generat_map(data, row, i);
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
	if (!data->mlx)
		game_over("error\n mlx error", data);
	data->win = mlx_new_window(data->mlx, data->w, data->h, "eelmoham");
	if (!data->win)
		game_over("error\nwindow error", data);
	data->img = mlx_xpm_file_to_image(data->mlx, "x/w.xpm", &i[0], &i[1]);
	data->e.exit_img = mlx_xpm_file_to_image(data->mlx, "x/e.xpm",
			&i[0], &i[1]);
	data->player.player_img = mlx_xpm_file_to_image(data->mlx, "x/p.xpm",
			&i[0], &i[1]);
	data->c.collectible_img = mlx_xpm_file_to_image (data->mlx, "x/f.xpm",
			&i[0], &i[1]);
	data->rows = set_map(data);
}

int	main(int ar, char **av)
{
	t_data	data;

	if (ar != 2)
	{
		write(2, "error\nWrong argument\n", 21);
		exit(1);
	}
	if (ft_strncmp(av[1], ".ber", ft_strlen(av[1]) - 4, ft_strlen(av[1])) != 0)
	{
		write(2, "error\npath map file should be like : \n\t\t\t\texemple.ber\n", 54);
		exit(1);
	}
	data.map = read_map(av[1]);
	if (!data.map)
		game_over("error\nno map\n", &data);
	check_element(&data);
	get_errors(&data);
	get_data(&data);
	if_map(&data);
	if (data.rows == data.len_lines)
		game_over("error\nuse rectongle map", &data);
	mlx_hook(data.win, 2, (1L << 0), func, &data);
	mlx_hook(data.win, 17, 0, close_game, &data);
	mlx_loop(data.mlx);
}
