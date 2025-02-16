/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:14:47 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/16 12:14:48 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strcmp(char *s1,char *s2)
{
    int i;
    i = 0;
    while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
}
int is_digit(int nbr)
{
    return(nbr>='0' && nbr<='9');
}
double atodbl(char *str)
{
    int i;
    i = 0;
    while((str[i]>='9' && str[i]<='13')|| (str[i] == ' '))
        i++;
    if(str[i] == '-'|| str[i] == '+')
    {
        if(str[i] == '-')
            i++;
    }
    while(*str)
    {
        if(!is_digit(*str) && *str != '.')
            write(1,"error: the number is not valid",31);
        str++;
    }
}