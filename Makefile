# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 03:00:14 by zamazzal          #+#    #+#              #
#    Updated: 2018/11/10 04:20:24 by zamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = src/backtraking.c src/main.c src/help1.c src/help2.c src/help3.c src/help4.c src/help5.c src/help6.c src/tools1.c src/tools2.c src/tools3.c src/tools4.c src/tools5.c src/validation1.c src/validation2.c

OBJ = backtraking.o main.o help1.o help2.o help3.o help4.o help5.o help6.o tools1.o tools2.o tools3.o tools4.o tools5.o validation1.o validation2.o

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -c $(FILES)
	gcc -Wall -Wextra -Werror $(OBJ) -o fillit

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
