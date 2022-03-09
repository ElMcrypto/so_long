/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:03:13 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/07 20:38:26 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_c (char **map , char c)
{
	int i;
	int j;
	int count;

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

void get_errors (char **map)
{
	int c;

	c = 1;
	if (count_c(map, 'P') != 1)
	{
		c = 0;
		write(2, "more or less then 1 player\n", 27);
	}
	if (count_c(map, 'E') != 1)
	{
		c = 0;
		write(2, "more or less then 1 map exit\n", 29);
	}
	if (count_c(map, 'C') < 1)
	{
		c = 0;
		write(2, "No collectible in youre map\n", 28);
	}
	if (c == 0)
		exit(1);
}


int lines(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

int check_line(char *ln)
{
    int i;

    i = 0;
    while (ln[i])
    {
        if (ln[i] != '1')
            return (1);
        i++;
    }
    return (0);
}

void if_map (char **mp)
{
    int i;
    int j;
    int error;

    i = 0;
    error = 0;
    j = lines(mp);
    while (mp[i] && (i + 1) < j)
    {
        if (ft_strlen(mp[i])- 1 != ft_strlen(mp[i + 1]) - 1)
            error  = 1;
        i++;
    }
    i = 0;
    while (mp[i])
    {
        if (mp[i][0] != '1' || mp[i][ft_strlen(mp[i]) - 1] != '1')
            error = 1;
        i++;
    }
    if  (check_line(mp[0]) == 1 || check_line(mp[j - 1]) == 1)
        error = 1;
    if (error == 1)
    {
        write (2, "found error on map\n", 19);
        exit(1);
    }
}