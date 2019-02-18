/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 09:47:06 by mmarcink          #+#    #+#             */
/*   Updated: 2018/05/25 09:47:06 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*ft_create_elem(int *data)
{
	t_tet *tet;

	tet = (t_tet*)ft_memalloc(sizeof(t_tet));
	if (tet)
	{
		tet->data = data;
		tet->next = NULL;
	}
	return (tet);
}

void	ft_list_push_back(t_tet **begin_tet, int *data)
{
	t_tet *ptr;

	ptr = *begin_tet;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = ft_create_elem(data);
	}
	else
		*begin_tet = ft_create_elem(data);
}

int		ft_list_size(t_tet *begin_tet)
{
	int		i;

	i = 0;
	while (begin_tet)
	{
		begin_tet = begin_tet->next;
		i++;
	}
	return (i);
}
