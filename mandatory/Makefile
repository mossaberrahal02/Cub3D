NAME = cub3d
CC = cc
INCLUDES = -Iincludes
CFLAGS = -Wall -Wextra  -g#-Werror
# CFLAGS = -Wall -Wextra -fsanitize=address -g #-Werror
C_FILES = ${wildcard src/*.c src/utils/*.c}
C_FILES_GNL = ${wildcard gnl/*.c}	#TODO remove wildcard 
C_FILES_LIBFT = libft/ft_putstr_fd.c libft/ft_putchar_fd.c libft/ft_substr.c libft/ft_strlen.c\
libft/ft_strjoin.c libft/ft_strdup.c libft/ft_strchr.c libft/ft_calloc.c libft/ft_bzero.c libft/ft_strncmp.c 
O_FILES = ${C_FILES:.c=.o}
O_FILES += ${C_FILES_GNL:.c=.o}
O_FILES += ${C_FILES_LIBFT:.c=.o}

#Colors:
GREEN		=	\e[92;118m
YELLOW		=	\e[93;226m
GRAY		=	\e[33;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

all: ${NAME}


${NAME}: ${O_FILES}
	${CC} ${CFLAGS} ${INCLUDES} lib -o ${NAME}
	@printf "$(CURSIVE)$(GRAY)	- Compilation finished $(RESET)\n"
	@printf "$(CURSIVE)$(GRAY)	- Executable ${NAME} is ready $(RESET)\n"

%.o:%.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
	@printf "$(CURSIVE)$(YELLOW)	- Compiling $(RESET)\n"
	@ar -rc lib $@

clean:
	@printf "$(CURSIVE)$(YELLOW)	- cleanning $(NAME)... $(RESET)\n"
	rm -f ${O_FILES}
fclean:
	@printf "$(CURSIVE)$(GRAY)	- Full cleanning $(NAME)... $(RESET)\n"
	rm -f ${O_FILES}
	rm -f ${NAME}
re: fclean all

.SECONDARY:${O_FILES}