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

SRCS =	testmain.c \
		allocation_pipex.c \
		allocation_and_cpy.c \
		store_args_in_struct.c \
		get_path_from_envp.c \
		spawn_child_and_process.c \
		false_fork.c \
		validate_cmd_full_path.c \
		store_execve_argv.c \
		exec_from_infile.c \
		exec_to_from_pipefd.c \
		exec_to_outfile.c \
		free_execve_argv.c \
		free_exit.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

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
