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

NAME =	printf.a

#SRC = 	ft_printf.c ft_check_key.c ft_intputchar.c ft_itis.c ft_itoa_base.c \
#		ft_new_list_key.c ft_print_digit.c ft_print_result.c \
#		ft_processing_argument.c ft_strupper.c ft_print_char.c

SRC = *.c
OSRC = *.o
#OSRC = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)
	
$(NAME):
	gcc -c -Wall -Wextra -Werror *.c
	ar cr $(NAME) $(OSRC)
	ranlib $(NAME)

#%.o : %.c
#	gcc -c -Wall -Wextra -Werror $<

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all
