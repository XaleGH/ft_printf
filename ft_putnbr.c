/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:49:17 by asaux             #+#    #+#             */
/*   Updated: 2023/10/25 10:30:50 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}

void	ft_putstr(char *s, int *count)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)", count);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	long int	nb;

	nb = n;
	if (n < 0)
	{
		nb = nb * -1;
		ft_putchar('-', count);
	}
	if (nb > 9)
		ft_putnbr((nb / 10), count);
	ft_putchar(((nb % 10) + '0'), count);
}

void	ft_putnbr_ui(unsigned int nbr, char *base, int *count)
{
	unsigned int	lengh;

	lengh = ft_strlen(base);
	if (nbr >= lengh)
	{
		ft_putnbr_ui(nbr / lengh, base, count);
		ft_putchar(base[(nbr % lengh)], count);
	}
	else if (nbr < lengh)
		ft_putchar(base[nbr], count);
}

void	ft_putnbr_ul(unsigned long nbr, char *base, int *count)
{
	unsigned long	lengh;

	lengh = ft_strlen(base);
	if (nbr >= lengh)
	{
		ft_putnbr_ul(nbr / lengh, base, count);
		ft_putchar(base[(nbr % lengh)], count);
	}
	else if (nbr < lengh)
		ft_putchar(base[nbr], count);
}
