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

# include "libft/libft.h"

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

int					valid_block(int *block);
int					second_h_block(int *block);
int					third_h_block(int *block);
int					second_v_block(int *block);
int					third_v_block(int *block);
t_tet				*read_tet(int fd);
int					*get_block(char *arr);
int					check_count(int *block, char *arr);
int					*trim_out(int *arr);
t_tet				*ft_create_elem(int *data);
void				ft_list_push_back(t_tet **begin_tet, int *data);
int					ft_list_size(t_tet *begin_tet);
void				fillit(t_tet *pieces);
int					find_starting_square(int np);
char				*malloc_board(size_t arr_size);
int					valid_spot(t_tet *pieces, char *board, int row_size,\
								int i);
int					place_pieces(t_tet *pieces, char *board, int row_size,\
								int piece_num);
char				get_piece(int piece_num);
void				add_piece(t_tet *pieces, char *board, int ints[3]);
void				remove_piece(t_tet *pieces, char *board, int i,\
								int row_size);
void				display_error(void);
void				display_usage(void);

#endif
