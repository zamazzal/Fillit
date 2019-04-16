/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 04:41:37 by zamazzal          #+#    #+#             */
/*   Updated: 2018/11/06 03:10:12 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void	ft_set(char ***tab)
{
	size_t i;
	size_t j;

	i = 0;
	while ((*tab)[i] != NULL)
	{
		j = 0;
		while ((*tab)[i][j])
		{
			if ((*tab)[i][j] == '#')
				(*tab)[i][j] = (char)(65 + i);
			j++;
		}
		i++;
	}
}

char	**ft_split_squares(char *name)
{
	char	*line;
	char	*file;
	char	**tab;
	int		fd;

	fd = open(name, O_RDONLY);
	file = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		if (*line == '\0')
			file = ft_strjoin(file, ":");
		else
			file = ft_strjoin(file, line);
		free(line);
	}
	tab = ft_strsplit(file, ':');
	close(fd);
	ft_set(&tab);
	return (tab);
}

int		ft_ttimes(char *t, int w)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	while (t[i])
	{
		if (t[i] != '.' && t[i] != '\n')
		{
			if (t[i] == t[i + 1])
				c++;
			if (t[i] == t[i - 1])
				c++;
			if (i < (w * w) - 1 && t[i] == t[i + w + 1])
				c++;
			if (i > w && t[i] == t[i - w - 1])
				c++;
		}
		i++;
	}
	return (c);
}

int		ft_is_tetrimino(char *t)
{
	int		w;
	char	*h;
	int		c;

	w = ft_sqrt(ft_strlen(t));
	h = ft_old(t);
	t = ft_strjoin("\n", h);
	free(h);
	c = ft_ttimes(t, w);
	return (c == 6 || c == 8);
}

int		ft_are_all_tetriminos(char *name)
{
	char	**tab;
	int		j;

	tab = ft_split_squares(name);
	j = 0;
	while (tab[j])
	{
		if (!ft_is_tetrimino(tab[j]))
			return (0);
		j++;
	}
	return (1);
}
