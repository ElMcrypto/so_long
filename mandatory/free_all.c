/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:46:54 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/22 23:34:28 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_window(t_data *data)
{
	if (data->mlx)
	{
		if (data->c.collectible_img)
			mlx_destroy_image(data->mlx, data->c.collectible_img);
		if (data->player.player_img)
			mlx_destroy_image(data->mlx, data->player.player_img);
		if (data->e.exit_img)
			mlx_destroy_image(data->mlx, data->e.exit_img);
		if (data->img)
			mlx_destroy_image(data->mlx, data->img);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
	}
}

void	game_over(char *msg, t_data *data)
{
	write (2, msg, ft_strlen(msg));
	free_window(data);
	free_map(data->map);
	exit(1);
}

void	error(char *hold_map)
{
	write (2, "error\nwrrong map\n", 17);
	free (hold_map);
	exit (1);
}

void	if_error_map_new_line(char *hold_map)
{
	int	i;

	i = 0;
	if (hold_map[0] == '\n')
		error(hold_map);
	while (hold_map[i])
	{
		if (hold_map[i] == '\n' && hold_map[i + 1] == '\n')
			error(hold_map);
		i++;
	}
	if (hold_map[i] == '\0' && hold_map[i - 1] == '\n')
		error(hold_map);
}
