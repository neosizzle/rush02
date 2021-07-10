SRCS = srcs/main.c srcs/dict.c srcs/dict-utils.c srcs/rush.c srcs/str-utils.c srcs/bst.c srcs/num-utils.c srcs/conversion.c
OBJS= ${SRCS:.c=.o}
CCFLAGS = -Wall -Werror -Wextra
CC = gcc
NAME = rush-02

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CCFLAGS} -o ${NAME} ${OBJS}

.c.o :
	${CC} ${CCFLAGS} -I includes -c $< -o ${<:.c=.o}

clean :
	rm -f ${OBJS}


fclean : clean
	rm -f ${NAME}

re : fclean all
