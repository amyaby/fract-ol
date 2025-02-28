/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:14:47 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/28 20:40:28 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractal.h"

int is_digit(int c)
{
    return (c >= '0' && c <= '9');
}

double parse_sign_and_int(char *str, int *i)
{
    double result = 0.0;
    int sign = 1;

    while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
        (*i)++;

    if (str[*i] == '-' || str[*i] == '+')
    {
        if (str[*i] == '-')
            sign = -1;
        (*i)++;
    }

    while (is_digit(str[*i]))
    {
        result = result * 10 + (str[*i] - '0');
        (*i)++;
    }

    return sign * result;
}

double parse_fract_part(char *str, int *i)
{
    double result = 0.0;
    double decimal_place = 1.0;

    if (str[*i] == '.')
    {
        (*i)++;

        // Check for multiple decimal points
        if (str[*i] == '.')
        {
            return 0.0; // Return 0.0 for invalid input
        }

        while (is_digit(str[*i]))
        {
            decimal_place /= 10;
            result += (str[*i] - '0') * decimal_place;
            (*i)++;
        }
    }

    return result;
}

double atodbl(char *str)
{
    double result = 0.0;
    int i = 0;

    result = parse_sign_and_int(str, &i);

    result += parse_fract_part(str, &i);

    while (str[i])
    {
        if (!is_digit(str[i]) && str[i] != '.' && str[i] != '+' && str[i] != '-')
        {
            return 0.0;
        }
        i++;
    }

    return result;
}
int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

