# COLORS
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

# SYMBOLS
INFO = $(WHITE)[$(BLUE)ℹ️$(WHITE)] $(NOP)
SUCCESS = $(WHITE)[$(GREEN)✅$(WHITE)] $(GREEN)
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)

# Binary
NAME=client
SERVER_NAME=server

# Path
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INCDIR = includes

# Name
SRC_NAME = client.c
SERVER_SRCS = server.c

OBJ_NAME = $(SRC_NAME:.c=.o)
SERVER_OBJ_NAME = $(SERVER_SRCS:.c=.o)

# Files
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

SERVER_SRC = $(addprefix $(SRC_PATH)/, $(SERVER_SRCS))
SERVER_OBJ = $(addprefix $(OBJ_PATH), $(SERVER_OBJ_NAME))

# Libft
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# Flags
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror


all: obj $(FT_LIB) $(NAME) $(SERVER_NAME)

obj:
	@echo "$(INFO)Creating objects folder... $(NOC)"
	@mkdir -p $(OBJ_PATH)
	@echo "$(SUCCESS)Objects folder created successfully$(NOC)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@echo "$(INFO)Building libft library...$(NOC)"
	@make -C $(FT)
	@echo "$(SUCCESS)Libft library built successfully!$(NOC)"

$(NAME): $(OBJ)
	@echo "$(INFO)Building $(NAME)...$(NOC)"
	@$(CC) $(OBJ) $(FT_LNK) -o $@
	@echo "$(SUCCESS)$(NAME) built successfully!$(NOC)"

$(SERVER_NAME): $(SERVER_OBJ)
	@echo "$(INFO)Building $(SERVER_NAME)...$(NOC)"
	@$(CC) $(SERVER_OBJ) $(FT_LNK) -o $@
	@echo "$(SUCCESS)$(SERVER_NAME) built successfully!$(NOC)"

clean:
	@echo "$(INFO)Deleting $(NAME) .o files...$(NOC)"
	@rm -rf $(OBJ_PATH)
	@echo "$(SUCCESS)$(NAME) .o files deleted successfully!$(NOC)"
	@echo "$(INFO)Deleting $(SERVER_NAME) .o files...$(NOC)"
	@rm -rf $(SERVER_NAME)
	@rm -rf $(SERVER_OBJ_PATH)
	@echo "$(SUCCESS)$(SERVER_NAME) .o files deleted successfully!$(NOC)"
	@echo "$(INFO)Deleting libft files..."
	@make -C $(FT) clean
	@echo "$(SUCCESS)Libft files deleted successfully!$(NOC)"

fclean: clean
	@echo "$(INFO)Deleting $(NAME)...$(NOC)"
	@rm -rf $(NAME)
	@echo "$(SUCCESS)$(NAME) deleted successfully!$(NOC)"
	@make -C $(FT) fclean

re: fclean all