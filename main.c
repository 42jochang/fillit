/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:25:51 by jochang           #+#    #+#             */
/*   Updated: 2018/05/20 21:36:31 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_tet	*ls;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ls = read_tet(fd);
		if (ls)
			fillit(ls);
		else
			display_error();
		if (close(fd) == -1)
			return (1);
	}
	else
		display_usage();
	return (0);
}
