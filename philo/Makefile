SRCS = ft_utils.c main.c

OBJS = ${SRCS:.c=.o}

NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $?

$(NAME)	: $(OBJS)
	$(CC) $(FLAGS) $(OBJS)  -o $(NAME)

clean :
	-rm -f ${OBJS}

fclean: clean
	-rm -f ${NAME}

re : fclean all

test :
	./philo