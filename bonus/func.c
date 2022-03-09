/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:33:08 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/07 23:23:53 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_exit(t_data *data)
{
	int count_co;

	count_co = count_c(data->map, 'C');
	if (count_co == 0)
		return (1);
	else
		return (0);
}

int func(int key, t_data *obj)
{
	int x;
	int y;
	int c_is_zero;

	x = obj->player.x;
	y = obj->player.y;
	c_is_zero = 0;
	if (key == 53)
	{
		free(obj->map);
		exit(1);
	}
	if (key == 13 || key == 2 || key == 0 || key == 1)
	{
		mlx_clear_window(obj->mlx, obj->win);
		obj->map[y][x] = '0';
		if (key == 13) //w
			obj->player.y -= 1;
		if (key == 2) //D
			obj->player.x += 1;
		if (key == 0) // a
			obj->player.x -= 1;
		if (key == 1) //s
			obj->player.y += 1;
	}
	if (obj->map[obj->player.y][obj->player.x] == '1')
		obj->map[y][x] = 'P';
	else
		obj->map[obj->player.y][obj->player.x] = 'P';
	c_is_zero = is_exit(obj);
	if (c_is_zero == 1 && obj->player.x == obj->e.x && obj->player.y == obj->e.y)
		exit(1);
	set_map(obj, c_is_zero);
	return (0);
}

void check_element(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'E' 
				|| map[i][j] == 'P' || map[i][j] == 'C')
				i++;
			else
			{
				write (2, "youre map should contine just 0 & 1 & P & C & E\n", 48);
				exit(1);
			}
			j++;
        }
        i++;
    }
}