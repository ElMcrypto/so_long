/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_bonus_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:45:31 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/22 22:00:34 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	lennbr(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	set_new_map(t_data *data)
{
	int	row;
	int	i;

	row = 0;
	while (data->map[row])
	{
		i = 0;
		while (data->map[row][i])
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
			i++;
		}
		row++;
	}
}

int	close_game(int key, t_data *obj)
{
	(void) key;
	(void) obj;
	write(2, "Game closed successfully\n", 25);
	exit(1);
	return (0);
}

int	animation(t_data *data)
{
	static int	i;
	int			s[2];

	i++;
	if (i <= 20)
		data->c.collectible_img = mlx_xpm_file_to_image(data->mlx, "./x/1.xpm",
				&s[0], &s[1]);
	else if (i <= 40)
		data->c.collectible_img = mlx_xpm_file_to_image(data->mlx, "./x/2.xpm",
				&s[0], &s[1]);
	else if (i <= 60)
		data->c.collectible_img = mlx_xpm_file_to_image(data->mlx, "./x/3.xpm",
				&s[0], &s[1]);
	if (i == 60)
		i = 0;
	set_new_map(data);
	patrole(data);
	return (0);
}
