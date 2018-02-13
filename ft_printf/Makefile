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

SRC = 	ft_addchar.c ft_check_key.c ft_del_key.c ft_itoa_base.c ft_myputwstr.c \
		ft_n.c ft_new_list_key.c ft_nonoercent.c ft_print_char_str.c ft_print_date.c \
		ft_print_digit.c ft_print_float.c ft_print_res.c ft_print_unicode.c \
		ft_print_w_char.c ft_printf.c ft_processing_args.c ft_putuchar.c \
		ft_res_separate.c ft_search_in_line.c ft_size2dig.c ft_strtounicat.c \
		ft_strupper.c ft_wrealloc.c ft_wstrdel.c ft_wstrlen.c ft_wstrzero.c

OSRC = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)
	
$(NAME): $(OSRC)
	ar cr $(NAME) $(OSRC)
	ranlib $(NAME)

%.o : %.c
	gcc -c -Wall -Wextra -Werror $<

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all
