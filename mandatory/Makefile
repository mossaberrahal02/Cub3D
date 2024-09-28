NAME = cub3d
CC = cc
INCLUDES = -Iincludes
CFLAGS = -Wall -Wextra  -g#-Werror
# CFLAGS = -Wall -Wextra -fsanitize=address -g #-Werror
C_FILES = ${addprefix  src/utils/, utils1.c}
C_FILES_GNL = ${addprefix gnl/, gc.c gnl.c gnl_utils.c}
C_FILES_LIBFT = ${addprefix libft/, ft_isdigit.c ft_putstr_fd.c ft_putchar_fd.c ft_substr.c ft_strlen.c ft_atoi.c\
									ft_strjoin.c ft_strdup.c ft_strchr.c ft_calloc.c ft_bzero.c\
									ft_strncmp.c ft_isalpha.c ft_strtrim.c ft_split_multi.c ft_strlcpy.c}
O_FILES = ${C_FILES:.c=.o}
O_FILES += src/main.o
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
	${CC} ${CFLAGS} ${INCLUDES}  lib -o ${NAME}
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