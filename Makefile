SRCS = srcs/main.c srcs/dict.c srcs/dict-util.c srcs/string-util.c

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
