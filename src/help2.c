/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:23:39 by zamazzal          #+#    #+#             */
/*   Updated: 2018/11/10 03:55:07 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		x;
	char		f;

	x = 0;
	f = (char)c;
	while (s[x])
	{
		if (s[x] == f)
			return ((char*)s + x);
		x++;
	}
	if (s[x] == f)
		return ((char*)s + x);
	return (NULL);
}

char	*ft_strcat(char *s1, const char *s2)
{
	size_t x;
	size_t y;

	x = ft_strlen(s1);
	y = 0;
	while (s2[y] != '\0')
		s1[x++] = s2[y++];
	s1[x] = '\0';
	return (s1);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		rzlt;

	rzlt = 0;
	i = 0;
	while (rzlt == 0)
	{
		if (s1[i] != s2[i])
			rzlt = (unsigned char)s1[i] - (unsigned char)s2[i];
		else if ((s1[i] == '\0') && (s2[i] == '\0'))
			return (0);
		i++;
	}
	return (rzlt);
}

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = (char*)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strcat(ptr, s2);
	return (ptr);
}
