/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:49:32 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/12 12:35:46 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(size * count);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

static char	*ft_strrev(char *str)
{
	int		i;
	char	temp;
	int		j;

	j = ft_strlen(str) - 1;
	i = 0;
	temp = 0;
	while (i <= j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j--;
		i++;
	}
	return (str);
}

static	unsigned	int	ft_abs(int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	return (nb);
}

char	*ft_itoa(int n)
{
	unsigned int	x;
	char			*ptr;
	int				i;

	i = 0;
	x = ft_abs(n);
	if (n == 0)
		return (ft_strdup("0"));
	ptr = ft_calloc(sizeof(char), lennbr(x) + 1 + (n < 0));
	if (ptr == 0)
		return (NULL);
	while (x)
	{
		ptr[i++] = x % 10 + '0';
		x = x / 10;
	}
	if (n < 0)
		ptr[i] = '-';
	ft_strrev(ptr);
	return (ptr);
}
