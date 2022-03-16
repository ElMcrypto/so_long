/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:54:50 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/16 21:27:43 by eelmoham         ###   ########.fr       */
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
			count++;
		obj->map[obj->player.y][obj->player.x] = 'P';
		obj->true = 0;
	}
	if (count_c(obj->map, 'C') == 0)
		obj->c_is_zero = 1;
	if (obj->c_is_zero == 1 && obj->player.x == obj->e.x
		&& obj->player.y == obj->e.y)
		game_over("game over, You Win\n", obj->map);
	set_map(obj);
	write(2, "score : ", 8);
	ft_putnbr(count);
	write(2, "\n", 1);
}

int	close_game(int key, t_data *obj)
{
	(void) key;
	write(2, "Game closed successfully\n", 25);
	exit(1);
	return (0);
}
