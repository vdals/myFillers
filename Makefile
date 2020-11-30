NAME = jnydia.filler
LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror -O2

SRC_DIR = src
OBJ_DIR = obj

INCLUDE = -I./inc
INCLUDE += -I./libft

HEADERS = inc/filler.h

SRCS = main.c
SRCS += reading.c
SRCS += additional.c
SRCS += decision.c

OBJS = $(SRCS:.c=.o)

SRCS_PATH = $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS_PATH = $(addprefix $(OBJ_DIR)/,$(OBJS))

.PHONY: clean fclean all re make_lib

all: $(LIBFT) $(NAME)

$(LIBFT) : make_lib
	@mkdir -p $(OBJ_DIR)
 
make_lib:
	@make -C ./libft/

$(NAME): $(OBJS_PATH) $(LIBFT) $(HEADERS)
	$(CC) -o $@ $(OBJS_PATH) $(LIBFT) $(INCLUDE)
	cp $(NAME) players

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS) Makefile
	$(CC) -o $@ -c $< $(INCLUDE) $(FLAGS)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C ./libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft/ fclean

re: fclean all

.PHONY: make_lib clean fclean re
