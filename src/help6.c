/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 21:52:47 by zamazzal          #+#    #+#             */
/*   Updated: 2018/11/07 23:06:45 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		get_next_line(const int fd, char **line)
{
	static char	*ptr[256];
	int			rd;
	char		bfr[BUFF_SIZE + 1];

	if (!line || fd < 0 || fd > 265 || BUFF_SIZE < 1 || read(fd, bfr, 0) < 0)
		return (-1);
	ptr[fd] = (!ptr[fd]) ? "" : ptr[fd];
	while ((rd = read(fd, bfr, BUFF_SIZE)))
	{
		if (rd < 0)
			return (-1);
		bfr[rd] = '\0';
		ptr[fd] = ft_strjoin(ptr[fd], bfr);
		if (ft_strchr(ptr[fd], '\n'))
			break ;
	}
	rd = 0;
	if (ptr[fd][0] == '\0')
		return (0);
	while (ptr[fd][rd] && ptr[fd][rd] != '\n')
		rd++;
	if (!(*line = ft_strsub(ptr[fd], 0, rd))
	|| !(ptr[fd] = (ft_strchr(ptr[fd], ptr[fd][rd]) + 1)))
		return (-1);
	return (1);
}
