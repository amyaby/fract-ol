/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:14:47 by iabasala          #+#    #+#             */
/*   Updated: 2025/03/14 00:01:00 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	parse_fractional_part(char *str, int *index)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		fraction = fraction * 10.0 + (str[*index] - '0');
		divisor *= 10.0;
		(*index)++;
	}
	return (fraction / divisor);
}

double	atodbl(char *str)
{
	double (result), (fraction);
	int (sign), (i);
	result = 0.0;
	fraction = 0.0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (EXIT_FAILURE);
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		fraction = parse_fractional_part(str, &i);
	}
	result += fraction;
	return (result * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
