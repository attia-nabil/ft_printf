NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =   ft_memset.c     \
        ft_bzero.c      \
        ft_memcpy.c     \
        ft_memmove.c    \
        ft_memchr.c     \
        ft_strlen.c     \
        ft_isalpha.c    \
        ft_isdigit.c    \
        ft_isalnum.c    \
        ft_isascii.c    \
        ft_isprint.c    \
		ft_split.c		\
		ft_strnstr.c	\
        ft_toupper.c    \
        ft_tolower.c    \
        ft_strchr.c     \
        ft_strrchr.c    \
		ft_memcmp.c		\
		ft_striteri.c	\
        ft_substr.c     \
        ft_atoi.c       \
        ft_calloc.c     \
        ft_strjoin.c    \
        ft_strlcpy.c    \
        ft_putchar_fd.c \
        ft_putnbr_fd.c  \
        ft_strdup.c     \
        ft_putstr_fd.c  \
        ft_itoa.c       \
        ft_strlcat.c    \
        ft_strtrim.c    \
        ft_strdup.c     \
        ft_strmapi.c    \
        ft_putendl_fd.c \
        ft_strncmp.c


OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) libft.h
	ar rcs $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
