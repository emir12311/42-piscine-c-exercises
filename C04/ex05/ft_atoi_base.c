/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir12311 <emir12311.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 23:49:02 by emir12311         #+#    #+#             */
/*   Updated: 2026/07/03 01:18:32 by emir12311        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	len;

	len = 0;
	j = 0;
	while (base[len] != '\0')
		len++;
	if (len < 2)
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

int	ft_atoi_helper(char *str, char *base, int *num_start, int b_len)
{
	int	j;
	int	total;

	total = 0;
	while (str[*num_start] != '\0')
	{
		j = 0;
		while (base[j] != '\0' && base[j] != str[*num_start])
		{
			j++;
		}
		if (base[j] == '\0')
			break ;
		total = (total * b_len) + j;
		(*num_start)++;
	}
	return (total);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	num;
	int	sign;
	int	len;

	i = 0;
	sign = 1;
	len = 0;
	if (ft_validate_base(base) == 0)
		return (0);
	while (base[len] != '\0')
		len++;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	ft_calcsign(str, &sign, &i);
	num = ft_atoi_helper(str, base, &i, len);
	if (sign == 0)
		num = -num;
	return (num);
}
