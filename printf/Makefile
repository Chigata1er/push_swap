
CC = gcc

CFLAGS =  -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c ft_putnbr.c ft_putstr.c hexa_base.c ft_putchar.c 

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	
clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re
