# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaara <kaara@student.42.jp>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 16:17:32 by kaara             #+#    #+#              #
#    Updated: 2025/01/17 16:17:32 by kaara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	src/main.c \
		src/allocation_pipex.c \
		src/allocation_and_cpy.c \
		src/store_args_in_struct.c \
		src/get_path_from_envp.c \
		src/spawn_child_and_process.c \
		src/setup_filefd.c \
		src/false_fork.c \
		src/chiled_process.c \
		src/validate_cmd_full_path.c \
		src/store_execve_argv.c \
		src/from_infile.c \
		src/spawn_pipefd.c \
		src/setup_pipefd.c \
		src/to_outfile.c \
		src/free_execve_argv.c \
		src/free_exit.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include -I$(LIBFT_DIR)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
