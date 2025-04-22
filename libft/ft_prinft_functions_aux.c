/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft_functions_aux.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:32:12 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/07 18:19:03 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	aux_putbs(long num, char *bs, int tt)
{
	size_t	i;
	char	c;

	i = ft_strlen(bs);
	if ((num / i) > 0)
	{
		tt = aux_putbs(num / i, bs, tt);
		tt = aux_putbs(num % i, bs, tt);
	}
	else
	{
		c = bs[num];
		tt += write(1, &c, 1);
	}
	return (tt);
}

int	aux_putpt(unsigned long int num, char *bs, int tt)
{
	int		i;
	char	c;

	i = ft_strlen(bs);
	if ((num / i) > 0)
	{
		tt = aux_putpt(num / i, bs, tt);
		tt = aux_putpt(num % i, bs, tt);
	}
	else
	{
		c = bs[num];
		tt += write(1, &c, 1);
	}
	return (tt);
}

int	aux_putnbr(int num, int tt)
{
	char	c;

	if (num == -2147483648)
		tt += write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			num *= -1;
			tt += write(1, "-", 1);
		}
		if ((num / 10) > 0)
		{
			tt = aux_putnbr(num / 10, tt);
			tt = aux_putnbr(num % 10, tt);
		}
		else
		{
			c = num + '0';
			tt += write(1, &c, 1);
		}
	}
	return (tt);
}

int	aux_putunbr(unsigned int num, int tt)
{
	char	c;

	if ((num / 10) > 0)
	{
		tt = aux_putunbr(num / 10, tt);
		tt = aux_putunbr(num % 10, tt);
	}
	else
	{
		c = num + '0';
		tt += write(1, &c, 1);
	}
	return (tt);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
