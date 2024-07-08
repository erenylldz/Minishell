NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = main.c
OBJECTS = $(SRC:.c=.o)
READLINE = -L./lib/readline/lib -I./lib/readline/include/readline -lreadline
DIR = $(shell echo $(PWD))
RL = ./lib/readline/lib/libreadline.a
RM = rm -rf


all: $(NAME)
	$(NAME) : $(RL) $(OBJECTS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(READLINE)
	$(RL):
				@echo "Downloading the readline library"
				@curl -O https://ftp.gnu.org/gnu/readline/readline-8.2-rc1.tar.gz
				@tar -xvf readline-8.2-rc1.tar.gz
				@$(RM) readline-8.2-rc1.tar.gz
				@cd readline-8.2-rc1 && ./configure --prefix=$(DIR)/lib/readline && make && make install
				@$(RM) readline-8.2-rc1
				@echo "Download completed"

rclean:
	@$(RM) lib/readline
	@echo "Readline removed"

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re push
