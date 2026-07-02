/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir12311 <emir12311.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 01:22:23 by emir12311         #+#    #+#             */
/*   Updated: 2026/07/03 00:09:11 by emir12311        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_contain_sign(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	ft_validate_base(char *base)
{
	int	i;
	int	j;

	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	if (ft_is_contain_sign(base) == 0)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_recur(long nbr, char *base, int b_len)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= b_len)
	{
		ft_putnbr_recur(nbr / b_len, base, b_len);
	}
	write(1, &base[nbr % b_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	b_len;

	if (ft_validate_base(base) == 0)
		return ;
	b_len = ft_strlen(base);
	ft_putnbr_recur((long)nbr, base, b_len);
}
