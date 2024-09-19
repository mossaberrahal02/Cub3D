NAME = cub3d
CC = cc
INCLUDES = -Iincludes
# CFLAGS = -Wall -Wextra  #-Werror
CFLAGS = -Wall -Wextra -fsanitize=address -g #-Werror
C_FILES = ${wildcard src/*.c}
O_FILES = ${C_FILES:.c=.o}

all: ${NAME}

%.o:%.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${O_FILES}
	${CC} ${CFLAGS} ${INCLUDES} ${O_FILES} -o ${NAME}

clean:
	rm -f ${O_FILES}
fclean:
	rm -f ${O_FILES}
	rm -f ${NAME}
re:fclean all

.SECONDARY:${O_FILES}