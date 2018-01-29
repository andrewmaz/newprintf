# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amazurok <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/04 14:55:05 by amazurok          #+#    #+#              #
#    Updated: 2017/11/07 11:54:58 by amazurok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

MAKELIB = make -C libft

MAKEPRF = make -C ft_printf

all:$(NAME)

$(NAME):
	$(MAKELIB)
	$(MAKEPRF)
	@ar x libft/libft.a 
	@ar x ft_printf/printf.a
	@ar cr $(NAME) *.o
	@rm -f *.o 
	@rm -f "__.SYMDEF SORTED"
	ranlib $(NAME)

clean:
	$(MAKELIB) clean
	$(MAKEPRF) clean

fclean:
	$(MAKELIB) fclean
	$(MAKEPRF) fclean
	rm -f $(NAME)

re: fclean all
