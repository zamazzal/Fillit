/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 01:54:06 by zamazzal          #+#    #+#             */
/*   Updated: 2018/11/08 02:00:13 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 5

typedef struct		s_s
{
	char			*r;
	char			*t;
	struct s_s		*prev;
	struct s_s		*next;
}					t_s;

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
int					get_next_line(const int fd, char **line);
void				ft_putfillit(char *s);
void				ft_clear(t_s *ss);
void				ft_t(char **tetrimino, int t);
void				ft_merge(char **result, char *tetrimino);
void				ft_fill_rs(char *rs, int now, char **tab, char *d);
void				ft_set(char ***tab);
int					ft_tetcmp(char *tet1, char *tet2);
int					ft_os(char **tab);
int					ft_valid(char *name);
int					ft_li(char *t);
int					ft_optim(t_s **ss);
int					ft_cross(char *result, char *tetrimino);
int					ft_place(char **result, char *tetrimino);
int					ft_in_end(char *t);
int					ft_n(char *s);
int					ft_strtablen(char **tab);
int					ft_longest_dim(char *tetrimino);
int					ft_fit_in(char *result, char *tetrimino);
int					ft_os_co(int os, char ***sstab, char *h);
int					ft_expand_tab(char ***sstab, int m, int os);
int					ft_sqrt(int n);
int					ft_num_of_hashs(char *s);
int					ft_is_valid_line(char *s, int l);
int					ft_is_valid_file(char *name);
int					ft_ttimes(char *t, int w);
int					ft_is_tetrimino(char *t);
int					ft_are_all_tetriminos(char *name);
char				*ft_comb_min(char **stab, t_s **ss, int *m);
char				*ft_comb(char **stab, int i, t_s *ss, char *r);
char				*ft_topleft(char **tetrimino);
char				*ft_expand(char *square);
char				*ft_size_to(char *tetrimino, int os, int size);
char				*ft_join(char **tab, char *d);
char				*ft_old(char *tetrimino);
char				**ft_split_squares(char *name);
t_s					*ft_push(t_s *ss, char **stab);

#endif
