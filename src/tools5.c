/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 22:16:42 by aaguert           #+#    #+#             */
/*   Updated: 2018/11/07 03:07:58 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		ft_li(char *t)
{
	int i;

	i = 0;
	while (t[i] != '\0')
	{
		if (t[i] >= 65 && t[i] <= 90)
			return ((int)t[i] - 65);
		i++;
	}
	return (-1);
}

void	ft_clear(t_s *ss)
{
	char	l;
	int		i;

	l = ft_li(ss->t) + 65;
	i = 0;
	while ((ss->r)[i])
	{
		if ((ss->r)[i] == l)
			(ss->r)[i] = '.';
		i++;
	}
}

int		ft_optim(t_s **ss)
{
	ft_clear(*ss);
	return (ft_sqrt(ft_strlen((*ss)->r)));
}

t_s		*ft_push(t_s *ss, char **stab)
{
	int w;

	ss = ss->prev;
	w = ft_optim(&ss);
	if (!ft_in_end(ss->t))
		ft_t(&ss->t, 1);
	else
	{
		if (ss->prev == NULL)
			return (NULL);
		ft_topleft(&(ss->t));
		ft_clear(ss->prev);
		ft_t(&((ss->prev)->t), 1);
		return (ss->prev);
	}
	while (ft_cross(ss->r, ss->t) || !ft_is_tetrimino(ss->t))
	{
		if (ft_in_end(ss->t))
			break ;
		ft_t(&ss->t, 1);
	}
	if (w == 3)
		while (!ft_tetcmp(stab[ft_li(ss->t)], ss->t))
			ft_t(&ss->t, 1);
	return (ss);
}
