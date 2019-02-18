/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:08:05 by jochang           #+#    #+#             */
/*   Updated: 2018/05/19 00:10:33 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft/inc/libft.h"

typedef struct		s_tet
{
	int				*data;
	struct s_tet	*next;
}					t_tet;

typedef struct		s_count
{
	int				pc;
	int				nc;
}					t_count;

t_tet				*read_tet(int fd);
void				fillit(t_tet *pieces);
int					place_pieces(t_tet *pieces, char *board, int row, int p);

/*
** Display
*/
void				display_board(char *b);
void				display_error(void);
void				display_usage(void);

/*
** List
*/
t_tet				*ft_create_elem(int *data);
void				ft_list_push_back(t_tet **begin_tet, int *data);
int					ft_list_size(t_tet *begin_tet);

#endif
