NAME = push_swap

CC = cc
INCLUDES = -I./$(LIBFT_DIR)/include -I./include
CFLAGS = -Wall -Wextra -Werror -g3 $(INCLUDES)

VCF				= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
ERR				= 2> error.txt

SRCS_DIR = ./srcs
OBJS_DIR = ./obj
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -f $(OBJS_DIR)/*.o
	@rmdir $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test2:		$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-2 -n 2))
					@echo $(ARG)
					$(VCF) ./push_swap $(ARG) $(ERR)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:		$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-3 -n 3))
					$(VCF) ./push_swap $(ARG) $(ERR)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test4:		$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-4 -n 4))
					@$(VCF) ./push_swap $(ARG) $(ERR)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:		$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-5 -n 5))
					@$(VCF) ./push_swap $(ARG) $(ERR)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test10:		$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-10 -n 10))
					@$(VCF) ./push_swap $(ARG) $(ERR)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:	$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-100 -n 100))
					@$(VCF) ./push_swap $(ARG) $(ERR)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:	$(LIBFT) $(NAME)	
					$(eval ARG = $(shell shuf -i 1-500 -n 500))
					@$(VCF) ./push_swap $(ARG) $(ERR)
					@ ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

random:
					@seq -1000 1000 | shuf -n 100 | tr '\n' ' '; echo

.PHONY: all clean fclean re