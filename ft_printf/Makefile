# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 21:30:32 by yena              #+#    #+#              #
#    Updated: 2022/12/17 23:02:40 by yena             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ./ft_printf.c\
	   ./util/common_util.c\
	   ./converter/char_converter.c\
	   ./converter/number_converter.c\
	   ./converter/pointer_converter.c\

LIBFT_DIR = libft
LIBFT_LIB = libft.a

OBJS   = $(SRCS:.c=.o)
INC	   = .

AR	   = ar rc
CC	   = cc
CFLAGS = -Wall -Wextra -Werror
RM	   = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
		${CC} ${CFLAGS} -I ${INC} -c $< -o ${<:.c=.o}

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
