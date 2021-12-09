# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nattia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 17:57:57 by nattia            #+#    #+#              #
#    Updated: 2021/12/07 17:58:11 by nattia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES	=	ft_putchar		\
				ft_putstr		\
				ft_putnbr		\
				ft_putusg		\
				ft_puthex		\
				ft_putptr		\
				ft_putper		\
				ft_printf

SRCS		=	$(addprefix srcs/, $(addsuffix .c, $(SRCS_FILES)))
OBJS		=	$(addprefix srcs/, $(addsuffix .o, $(SRCS_FILES)))

HEADER		=	include/ft_printf.h
NAME		=	libftprintf.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar crs

RM			=	rm -f

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
	@make -C srcs/libft
	@cp srcs/libft/libft.a .
	@mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o			:	%.c
	$(CC) $(CFLAGS) -I include -c $< -o $(<:.c=.o)


clean		:
	@make clean -C srcs/libft
	$(RM) $(OBJS)

fclean		:	clean
	$(RM) srcs/libft/libft.a
	$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
