/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:12:39 by aaguert           #+#    #+#             */
/*   Updated: 2018/11/07 22:04:48 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void		ft_fill_rs(char *rs, int now, char **tab, char *d)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			rs[k] = tab[i][j];
			j++;
			k++;
		}
		j = 0;
		while (d[j] && i < (now - 1))
		{
			rs[k] = d[j];
			j++;
			k++;
		}
		i++;
	}
	rs[k] = '\0';
}

char		*ft_join(char **tab, char *d)
{
	int		sl;
	int		i;
	int		j;
	char	*rs;

	sl = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			sl++;
			j++;
		}
		i++;
	}
	if (*d != '\0')
	{
		sl += ft_strlen(d) * (i - 1);
	}
	if (!(rs = (char*)malloc((sl + 1) * sizeof(char))))
		return (NULL);
	ft_fill_rs(rs, i, tab, d);
	return (rs);
}
