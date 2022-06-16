	SRCS  = main.c

	OBJS = ${SRCS:.c=.o}

	CC = gcc

	CFLAGS = -Wall -Wextra -Werror -g3

	OS = $(shell uname)

	LIBFT = libs/libft/libft.a


