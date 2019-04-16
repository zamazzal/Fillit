/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtraking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 21:01:10 by aaguert           #+#    #+#             */
/*   Updated: 2018/11/06 23:49:50 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

char	*ft_comb_min(char **stab, t_s **ss, int *m)
{
	t_s		*h;
	int		j;

	h = ft_push(*ss, stab);
	if (h == NULL)
	{
		j = ft_expand_tab(&stab, 1, 1);
		free(*ss);
		*m = 0;
		return (ft_comb(stab, 0, *ss, ft_size_to("....", 2 * 2, j)));
	}
	else
	{
		*m = 1;
		return (ft_comb(stab, ft_li(h->t), h, h->r));
	}
}

char	*ft_comb(char **stab, int i, t_s *ss, char *r)
{
	static t_s	*prev;
	static int	m;

	if (m == 0)
	{
		if (!(ss = (t_s *)malloc(sizeof(t_s))))
			return (NULL);
		ss->r = ft_strdup(r);
		ss->t = ft_strdup(stab[i]);
		ss->next = NULL;
		ss->prev = (i == 0) ? NULL : prev;
	}
	if (ft_place(&(ss->r), ss->t))
	{
		if (i == ft_strtablen(stab) - 1)
			return (ss->r);
		else
		{
			prev = ss;
			m = 0;
			return (ft_comb(stab, i + 1, ss->next, ss->r));
		}
	}
	else
		return (ft_comb_min(stab, &ss, &m));
}

int		ft_tetcmp(char *tet1, char *tet2)
{
	char	*h1;
	char	*h2;

	h1 = ft_strdup(tet2);
	h2 = ft_strdup(tet1);
	h1 = ft_expand(h1);
	h2 = ft_expand(h2);
	ft_topleft(&h1);
	ft_topleft(&h2);
	if (ft_strequ(h1, h2))
	{
		free(h1);
		free(h2);
		return (1);
	}
	else
	{
		free(h1);
		free(h2);
		return (0);
	}
}
