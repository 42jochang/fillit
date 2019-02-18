/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:27:38 by jochang           #+#    #+#             */
/*   Updated: 2018/05/18 23:58:39 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *g_colors[6] = {
	"\033[41m",
	"\033[42m",
	"\033[43m",
	"\033[44m",
	"\033[45m",
	"\033[46m"
};

void	display_board(char *b)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (b[i])
	{
		ft_putstr(b[i] == '.' ? "\033[40m" : g_colors[b[i] % 6]);
		if (b[i] == '\n')
			write(1, "\n", 1);
		else
			write(1, "  ", 2);
		//write(1, &b[i], 1);
		i++;
	}
}

void	display_error(void)
{
	write(1, "error\n", 6);
}

void	display_usage(void)
{
	write(1, "./fillit source_file\n", 21);
}
