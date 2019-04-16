/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:58:55 by zamazzal          #+#    #+#             */
/*   Updated: 2018/10/11 13:31:53 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(dest, s1);
	return (dest);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*f;

	i = 0;
	f = (char*)b;
	while (i < len)
		f[i++] = ((char)c);
	b = (void*)f;
	return (b);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while ((src[i] != '\0') && (i < len))
	{
		dst[i] = (unsigned char)src[i];
		i++;
	}
	ft_bzero(&dst[i], len - i);
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*z;

	i = 0;
	z = (char*)s;
	while (i < n)
		z[i++] = 0;
	s = (void*)z;
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
