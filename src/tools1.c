/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:54:27 by zamazzal          #+#    #+#             */
/*   Updated: 2018/11/06 03:11:55 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		ft_cross(char *result, char *tetrimino)
{
	int i;

	i = 0;
	while (result[i] != '\0' && tetrimino[i] != '\0')
	{
		if (result[i] != '.' && tetrimino[i] != '.')
			return (1);
		i++;
	}
	return (0);
}

int		ft_place(char **result, char *tetrimino)
{
	while (ft_cross(*result, tetrimino) || !ft_is_tetrimino(tetrimino))
	{
		if (ft_in_end(tetrimino))
		{
			if (!ft_cross(*result, tetrimino) && ft_is_tetrimino(tetrimino))
				return (1);
			else
				return (0);
		}
		ft_t(&tetrimino, 1);
	}
	ft_merge(result, tetrimino);
	return (1);
}

void	ft_t(char **tetrimino, int t)
{
	int		l;
	int		i;
	int		j;
	char	h;

	l = ft_strlen(*tetrimino);
	while (t)
	{
		i = 0;
		j = l - 1;
		if (t < 0)
			j = 1;
		while (i++ < l - 1)
		{
			h = (*tetrimino)[j - 1];
			(*tetrimino)[j - 1] = (*tetrimino)[j];
			(*tetrimino)[j] = h;
			t > 0 ? j-- : j++;
		}
		t > 0 ? t-- : t++;
	}
}

void	ft_merge(char **result, char *tetrimino)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tetrimino[j])
	{
		if (i >= 4)
			break ;
		if (tetrimino[j] != '.')
		{
			(*result)[j] = tetrimino[j];
			i++;
		}
		j++;
	}
}

char	*ft_topleft(char **tetrimino)
{
	int		i;
	int		w;

	w = ft_sqrt(ft_strlen(*tetrimino));
	i = 0;
	while (i < w * w)
	{
		if ((*tetrimino)[0] != '.')
			return (*tetrimino);
		else if (((*tetrimino)[w] != '.' || (*tetrimino)[2 * w] != '.')
				&& ((*tetrimino)[1] != '.' || (*tetrimino)[2] != '.')
				&& ft_is_tetrimino(*tetrimino))
			return (*tetrimino);
		else
			ft_t(tetrimino, -1);
		i++;
	}
	return (0);
}
