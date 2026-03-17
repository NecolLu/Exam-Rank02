/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zloo <zloo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:54:56 by zloo              #+#    #+#             */
/*   Updated: 2026/03/17 17:24:40 by zloo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *str)
{
	int		i;
	char	c;
	int		repeat;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (str[i] >= 'A' && str[i] <= 'Z')
			repeat = c - 'A' + 1;
		else if (str[i] >= 'a' && str[i] <= 'z')
			repeat = c - 'a' + 1;
		else
			repeat = 1;
		while (repeat--)
			write(1, &c, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
}
