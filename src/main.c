/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:00:42 by aaguert           #+#    #+#             */
/*   Updated: 2018/11/08 02:11:31 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		ft_os(char **tab)
{
	int l;

	l = ft_strtablen(tab);
	l = l * 4;
	while (ft_sqrt(l) == 0)
		l++;
	return (l);
}

int		ft_valid(char *name)
{
	int		fd;
	int		h;
	char	buff[2];

	h = 1;
	fd = open(name, O_RDONLY);
	while (read(fd, buff, 1))
		h = 1;
	close(fd);
	if (*buff != '\n')
		return (0);
	return (h);
}

void	ft_putfillit(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++]);
}

int		main(int ac, char **av)
{
	char	**stab;
	char	*result;
	int		fs;
	t_s		*ss;

	ss = NULL;
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit [input_file]");
		return (1);
	}
	else if (!ft_is_valid_file(av[1])
	|| !ft_are_all_tetriminos(av[1]) || !ft_valid(av[1]))
	{
		ft_putendl("error");
		return (1);
	}
	else
	{
		stab = ft_split_squares(av[1]);
		fs = ft_expand_tab(&stab, 0, ft_os(stab));
		result = ft_old(ft_comb(stab, 0, ss, ft_size_to("....", 2 * 2, fs)));
		ft_putfillit(result);
		return (0);
	}
}
