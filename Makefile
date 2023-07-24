LIBX11 = /usr/lib/x86_64-linux-gnu/libX11.so
LIBXEXT = /usr/lib/x86_64-linux-gnu/libXext.so
LIBZ = /usr/lib/x86_64-linux-gnu/libz.so
LIBM = /usr/lib/x86_64-linux-gnu/libm.so	

SRC_DIR 	=	./source
OBJ_DIR 	=	./objects
INC_DIR		= 	./includes

FILES 		=	main 

SRCS 		= 	$(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))
OBJS 		= 	$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

NAME		=	so_long
#FLAGS		=	-Wall -Werror -Wextra -Ofast
MLX_FLAGS	=	-L/usr/X11/lib -lX11 -lXext -lm
INC			=	-I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR) -I /usr/X11/include

LIBFT_DIR = ./ft_printf
LIBFT = ./ft_printf/libftprintf.a

MLX_DIR = ./minilibx-linux
MLX = ./minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@cc $(FLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

$(MLX):
	@echo "$(YELLOW)Compiling [$(MLX)]...$(RESET)"
	@make -C $(MLX_DIR)
	@echo "$(GREEN)Finished [$(MLX)]$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@cc $(FLAGS) $(INC) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

clean:
	@echo "$(BLUE)[$(NAME)] Deleting all objects $(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(MLX_DIR) clean --no-print-directory 2> /dev/null > /dev/null

fclean: clean
	@echo "$(BLUE)Deleting $(NAME) $(RESET)"
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@make -C $(MLX_DIR) clean --no-print-directory 2> /dev/null > /dev/null

re: fclean all

.PHONY: all clean fclean re

