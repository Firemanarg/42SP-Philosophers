# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 08:50:05 by lsilva-q          #+#    #+#              #
#    Updated: 2023/07/18 08:50:05 by lsilva-q         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= philo

CC					= clang
CFLAGS				= -Wall -Wextra -Werror -pthread

SRCS_DIR			= .
SRC_FILES			= main.c \
					  simulation.c \
					  utils_1.c \
					  utils_2.c
SRCS				= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS_DIR			= objs
OBJS				= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:%.c=%.o))
HEADERS				= philo.h
SUBDIRS				= utils routines initializers core_utils
INCLUDES			= $(SUBDIRS:%=-I $(SRCS_DIR)/%) -I $(SRCS_DIR)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(HEADERS)
					@echo "Compiling $< into $@"
					mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/, $(SUBDIRS))
					$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:				$(NAME)

clean:
					rm -rf $(OBJS)
					rm -rf $(OBJS_DIR)

fclean:				clean
					rm $(NAME)

re:					fclean all

.PHONY:				all clean fclean re

# Debugging

debug:
					@echo "~~~~~~~~~~~~~"
					@echo "~ D E B U G ~"
					@echo "~~~~~~~~~~~~~"
					@make debug_srcs
					@make debug_objs
					@make debug_headers
					@make debug_subdirs
					@make debug_includes

debug_srcs:
					@echo "\n"
					@echo "\t~~~~~~~~~~~"
					@echo "\t~ S R C S ~"
					@echo "\t~~~~~~~~~~~"
					@echo "\n"
					@echo "SRCS_DIR: "$(SRCS_DIR)
					@echo "\n"
					@echo "SRC_FILES: "$(SRC_FILES)
					@echo "\n"
					@echo "SRCS: "$(SRCS)

debug_objs:
					@echo "\n"
					@echo "\t~~~~~~~~~~~"
					@echo "\t~ O B J S ~"
					@echo "\t~~~~~~~~~~~"
					@echo "\n"
					@echo "OBJS_DIR: "$(OBJS_DIR)
					@echo "\n"
					@echo "OBJS: "$(OBJS)

debug_headers:
					@echo "\n"
					@echo "\t~~~~~~~~~~~~~~~~~"
					@echo "\t~ H E A D E R S ~"
					@echo "\t~~~~~~~~~~~~~~~~~"
					@echo "\n"
					@echo "HEADERS: "$(HEADERS)

debug_subdirs:
					@echo "\n"
					@echo "\t~~~~~~~~~~~~~~~~~"
					@echo "\t~ S U B D I R S ~"
					@echo "\t~~~~~~~~~~~~~~~~~"
					@echo "\n"
					@echo "SUBDIRS: "$(SUBDIRS)

debug_includes:
					@echo "\n"
					@echo "\t~~~~~~~~~~~~~~~~~~~"
					@echo "\t~ I N C L U D E S ~"
					@echo "\t~~~~~~~~~~~~~~~~~~~"
					@echo "\n"
					@echo "INCLUDES: "$(INCLUDES)
