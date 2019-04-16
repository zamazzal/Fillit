/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:40:52 by zamazzal          #+#    #+#             */
/*   Updated: 2018/11/02 03:04:36 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

static int		c_w_d(char const *s, char c)
{
	int i;
	int nw;

	i = 0;
	nw = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		nw++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nw);
}

static void		fill_lowt(char const *s, int *t, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		t[j] = 0;
		while (s[i] != c && s[i])
		{
			t[j]++;
			i++;
		}
		j++;
	}
}

static void		fill_res(char **res, char const *s, int nw, char c)
{
	int i;
	int j;
	int k;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		k = 0;
		while (s[i] && s[i] != c)
		{
			res[j][k] = s[i];
			k++;
			i++;
		}
		res[j][k] = 0;
		j++;
	}
	res[nw] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	int		nw;
	int		*lowt;
	char	**res;
	int		i;

	nw = c_w_d(s, c);
	if (!(lowt = (int*)malloc(nw * sizeof(int))))
		return (NULL);
	fill_lowt(s, lowt, c);
	if (!(res = (char**)malloc((nw + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (i < nw)
	{
		res[i] = (char*)malloc((lowt[i] + 1) * sizeof(char));
		i++;
	}
	fill_res(res, s, nw, c);
	return (res);
}
