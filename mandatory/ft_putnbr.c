/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:54:50 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/22 21:58:57 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int n)
{
	long int	x;

	x = n;
	if (x < 0)
	{
		x = -x;
		write(2, "-", 1);
	}
	if (x <= 9)
	{
		x = x + '0';
		write(2, &x, 1);
	}
	else
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
}

void	move(int x, int y, t_data *obj)
{
	static int	count;

	obj->c_is_zero = 0;
	if (obj->map[obj->player.y][obj->player.x] == '1'
		|| obj->map[obj->player.y][obj->player.x] == 'E')
		obj->map[y][x] = 'P';
	else
	{
		if (obj->true == 1)
		{
			write(2, "score : ", 8);
			ft_putnbr(++count);
			write(2, "\n", 1);
		}
		obj->map[obj->player.y][obj->player.x] = 'P';
	}
	if (count_c(obj->map, 'C') == 0)
		obj->c_is_zero = 1;
	if (obj->c_is_zero == 1 && (obj->map[obj->player.y][obj->player.x] == 'E'))
		game_over("game over, You Win\n", obj);
	set_map(obj);
}

int	close_game(int key, t_data *obj)
{
	(void) key;
	(void) obj;
	write(2, "Game closed successfully\n", 25);
	exit(1);
	return (0);
}

void	read_map2(int fd, char *str, char *line)
{
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(2, "error\n Don't find the map file\n", 31);
		exit(1);
	}
	line = get_next_line(fd);
}

void	print_error(char *msg)
{
	write (2, msg, ft_strlen(msg));
	exit(1);
}
