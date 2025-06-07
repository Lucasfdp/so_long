# #Cross platform Makefile

# # ───── Compiler & Flags ─────
# CC      = cc
# CFLAGS  = -Wall -Wextra -Werror

# # ───── Project Name ─────
# NAME    = so_long

# # ───── Libft ─────
# LIBFT_DIR = ./libft
# LIBFT     = $(LIBFT_DIR)/libft.a

# # ───── MLX Platform Detection ─────
# UNAME   := $(shell uname)
# ifeq ($(UNAME), Darwin)
# 	MLX_DIR = ./mlx_mac
# 	MLX_FLAGS = -framework OpenGL -framework AppKit
# else
# 	MLX_DIR = ./mlx_linux
# 	MLX_FLAGS = -lXext -lX11 -lm
# endif

# MLX     = -L$(MLX_DIR) -lmlx

# # ───── Source Files ─────
# SRC_DIR = src
# SRCS    = $(wildcard $(SRC_DIR)/*.c)
# OBJS    = $(SRCS:.c=.o)

# # ───── Build Rules ─────
# all: $(LIBFT) $(NAME)

# $(LIBFT):
# 	@$(MAKE) -C $(LIBFT_DIR)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

# # ───── Utility ─────
# clean:
# 	@$(MAKE) -C $(LIBFT_DIR) clean
# 	@rm -f $(OBJS)

# fclean: clean
# 	@$(MAKE) -C $(LIBFT_DIR) fclean
# 	@rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re
