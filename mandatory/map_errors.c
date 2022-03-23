/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:03:13 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/20 23:36:45 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_c(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count ++;
			j++;
		}
		i++;
	}
	return (count);
}

void	get_errors(t_data *data)
{
	if (count_c(data->map, 'P') != 1)
		game_over("error\nmore or less then 1 player\n", data);
	if (count_c(data->map, 'E') < 1)
		game_over("error\nyoure map should be have at least 1map exit\n", data);
	if (count_c(data->map, 'C') < 1)
		game_over("error\nNo collectible in youre map\n", data);
}

int	lines(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

int	check_line(char *ln)
{
	int	i;

	i = 0;
	while (ln[i])
	{
		if (ln[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	if_map(t_data *data)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	error = 0;
	j = lines(data->map);
	while (data->map[i] && (i + 1) < j)
	{
		if (ft_strlen(data->map[i]) - 1 != ft_strlen(data->map[i + 1]) - 1)
			error = 1;
		i++;
	}
	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' ||
			data->map[i][ft_strlen(data->map[i]) - 1] != '1')
			error = 1;
		i++;
	}
	if (check_line(data->map[0]) == 1 || check_line(data->map[j - 1]) == 1)
		error = 1;
	if (error == 1)
		game_over("error\nfound error on map\n", data);
}
