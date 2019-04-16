/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 01:28:01 by zamazzal          #+#    #+#             */
/*   Updated: 2018/11/07 00:31:13 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		ft_sqrt(int n)
{
	int i;

	i = 1;
	while (i * i != n)
	{
		if (i * i > n)
			return (0);
		i++;
	}
	return (i);
}

int		ft_num_of_hashs(char *s)
{
	int r;
	int i;

	r = 0;
	i = 0;
	while (s[i])
		if (s[i++] == '#')
			r++;
	return (r);
}

int		ft_is_valid_line(char *s, int l)
{
	int i;

	i = 0;
	if (*s == '\0')
		return (1);
	if (*s == '\n')
		return (0);
	while (s[i])
	{
		if (s[i] != '.' && s[i] != '#')
			return (0);
		i++;
	}
	if (ft_strlen(s) != 4 || l > 131)
		return (0);
	else if (ft_strequ("#.#.", s) || ft_strequ(".#.#", s)
			|| ft_strequ("#..#", s))
		return (0);
	return (1);
}

int		ft_is_valid_file(char *name)
{
	char	*line;
	int		l;
	int		noh;
	char	*prev;
	int		fd;

	l = 0;
	noh = 0;
	fd = open(name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (l++ > 1)
			if (*prev == '\0' && *line == '\0')
				return (0);
		noh += ft_num_of_hashs(line);
		if (!ft_is_valid_line(line, l))
			return (0);
		if (l % 5 == 0 && *line != '\0')
			return (0);
		if (l % 5 == 4 && noh != 4)
			return (0);
		l % 5 == 4 ? noh = 0 : noh;
		prev = line;
	}
	return (l > 3 && close(fd) != -1 && *line != '\0');
}

char	*ft_old(char *tetrimino)
{
	char	*res;
	char	*line;
	char	*tet;
	int		i;
	int		p;

	p = ft_sqrt(ft_strlen(tetrimino));
	tet = ft_strnew(p * p);
	ft_strcpy(tet, tetrimino);
	res = ft_strnew(0);
	i = 0;
	while (i < p)
	{
		i > 1 ? free(line) : line;
		line = ft_strjoin(ft_strsub(tet, i * p, p), "\n");
		res = ft_strjoin(res, line);
		i++;
	}
	free(tet);
	return (res);
}
