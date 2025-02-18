/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:14:47 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/17 20:57:24 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractal.h"

int is_digit(int c)
{
    return (c >= '0' && c <= '9');
}

double parse_sign_and_int(char *str)
{
    double result = 0.0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    while (is_digit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

double parse_fract_part(char *str)
{
    double result = 0.0;
    double decimal_place = 1.0;
    int i = 0;

    if (str[i] == '.')
    {
        i++;

        while (str[i] == '.')
        {
            write(1, "error\n", 7);
            return 0;
        }
        while (is_digit(str[i]))
        {
            decimal_place /= 10;
            result += (str[i] - '0') * decimal_place;
            i++;
        }
    }

    return result;
}

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

double atodbl(char *str)
{
    double result = 0.0;
    
    result = parse_sign_and_int(str);

    result += parse_fract_part(str);

    int i = 0;
    while (str[i])
    {
        if (!is_digit(str[i]) && str[i] != '.' && str[i] != '+' && str[i] != '-')
        {
            write(1, "error\n", 7);
            return 0;
        }
        i++;
    }

    return result;
}



