/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:47:02 by aaguert           #+#    #+#             */
/*   Updated: 2018/11/08 01:54:04 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

char	*ft_expand(char *square)
{
	char	*res;
	char	*bottom;
	char	*line;
	int		w;
	int		i;

	line = NULL;
	w = ft_sqrt(ft_strlen(square));
	res = ft_strnew(0);
	i = 0;
	while (i < w)
	{
		line ? free(line) : line;
		line = ft_strjoin(ft_strsub(square, i * w, w), ".");
		res = ft_strjoin(res, line);
		i++;
	}
	bottom = ft_strnew(w);
	ft_memset(bottom, '.', w + 1);
	res = ft_strjoin(res, bottom);
	free(bottom);
	return (res);
}

char	*ft_size_to(char *tetrimino, int os, int size)
{
	char	*res;
	char	**tab;
	int		slen;
	int		i;

	slen = ft_sqrt(size);
	if (slen >= ft_sqrt(os))
	{
		i = ft_sqrt(os);
		res = tetrimino;
		while (i++ < slen)
			res = ft_expand(res);
		return (res);
	}
	res = ft_old(tetrimino);
	tab = ft_strsplit(res, '\n');
	i = -1;
	while (++i < slen)
		tab[i] = ft_strsub(tab[i], 0, slen);
	tab[i] = 0;
	return (ft_join(tab, ""));
}

int		ft_os_co(int os, char ***sstab, char *h)
{
	int i;

	i = -1;
	while ((*sstab)[++i])
		if (!ft_fit_in(h, (*sstab)[i]))
			os = ft_longest_dim((*sstab)[i]) * ft_longest_dim((*sstab)[i]);
	return (os);
}

int		ft_expand_tab(char ***sstab, int m, int os)
{
	char	*h;
	int		i;
	int		n;

	n = 4 * 4;
	i = -1;
	while ((*sstab)[++i])
		(*sstab)[i] = ft_topleft((*sstab + i));
	h = ft_size_to("....", 2 * 2, os);
	i = -1;
	os = ft_os_co(os, sstab, h);
	if (m == 1)
	{
		n = ft_strlen((*sstab)[0]);
		os = n + 2 * ft_sqrt(n) + 1;
	}
	i = -1;
	while ((*sstab)[++i])
		(*sstab)[i] = ft_size_to((*sstab)[i], n, os);
	return (os);
}
