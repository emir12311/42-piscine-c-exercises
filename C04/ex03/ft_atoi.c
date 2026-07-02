/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir12311 <emir12311.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:23:23 by emir12311         #+#    #+#             */
/*   Updated: 2026/07/03 00:41:22 by emir12311        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chr_is_numeric(char chr)
{
	if (!('0' <= chr && chr <= '9'))
		return (0);
	return (1);
}

void	ft_calcsign(char *str, int *sign, int *i)
{
	int	minus;

	minus = 0;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '+')
			(*i)++;
		else if (str[*i] == '-')
		{
			(*i)++;
			minus++;
		}
	}
	if (minus % 2 == 1)
		*sign = 0;
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	ft_calcsign(str, &sign, &i);
	while (ft_chr_is_numeric(str[i]) == 1)
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (sign == 0)
		nbr *= -1;
	return (nbr);
}
	