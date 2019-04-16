/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 20:05:23 by zamazzal          #+#    #+#             */
/*   Updated: 2018/11/08 01:59:00 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		ft_in_end(char *t)
{
	int w;

	w = ft_sqrt(ft_strlen(t));
	if (t[w * w - 1] != '.')
		return (1);
	else if ((t[(w * w) - w - 1] != '.' || t[w * w - 2 * w - 1] != '.')
			&& (t[w * w - 2] != '.' || t[w * w - 3] != '.')
			&& ft_is_tetrimino(t))
		return (1);
	return (0);
}

int		ft_n(char *s)
{
	int r;
	int i;

	r = 0;
	i = 0;
	while (s[i])
		if (s[i++] != '.')
			r++;
	return (r);
}

int		ft_strtablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_longest_dim(char *tetrimino)
{
	char	*mline;
	char	*mcol;
	char	*h;
	int		j;
	int		i;

	mline = ft_strdup("....");
	mcol = ft_strdup("....");
	i = -1;
	while (++i < 4)
	{
		h = ft_strsub(tetrimino, i * 4, 4);
		j = -1;
		while (h[++j])
			if (mline[j] == '.')
				mline[j] = h[j];
	}
	i = -1;
	while (++i < 4)
	{
		h = ft_strsub(tetrimino, i * 4, 4);
		if (ft_n(h) != 0 && mcol[i] == '.')
			mcol[i] = ft_li(tetrimino) + 65;
	}
	return (ft_n(mcol) > ft_n(mline) ? ft_n(mcol) : ft_n(mline));
}

int		ft_fit_in(char *result, char *tetrimino)
{
	if (ft_longest_dim(tetrimino) > ft_sqrt(ft_strlen(result)))
		return (0);
	return (1);
}
