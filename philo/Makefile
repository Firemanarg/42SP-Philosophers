# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 09:43:41 by lsilva-q          #+#    #+#              #
#    Updated: 2023/04/20 09:43:41 by lsilva-q         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= philo

CC					= clang
CFLAGS				= -Wall -Wextra -Werror -pthread

SRCS_DIR			= philo
SRCS				= manager/manager_setup.c \
					  manager/manager_terminate.c \
					  philo_/philo_routine.c \
					  philo_/philo_utils.c \
					  philo_/forks.c \
					  utils/str_utils.c \
					  utils/time_utils.c \
					  main.c
OBJS_DIR			= objs
# OBJS				= $(SRCS:%.c=%.o)
OBJS				= $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))
# OBJS				= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:%.c=%.o)))
# OBJS				= $(SRCS:%.c=%.o)
HEADERS				= manager/manager.h \
					  philo_/philo.h \
					  utils/utils.h
SUBDIRS				= $(dir $(SRCS))
# INCLUDES			= $(addprefix -I , $(dir $(HEADERS)))
INCLUDES			= manager philo_ utils

# $(OBJS): $(OBJS_DIR)/%.o:	./%.c $(HEADERS)
$(OBJS_DIR)/%.o:	%.c $(HEADERS)
#					@mkdir -p $(dir $@)
					mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/, $(SUBDIRS))
					$(CC) $(CFLAGS) $(INCLUDES:%=-I%) -c $< -o $@

# $(OBJS_DIR):
# 					mkdir -p $(OBJS_DIR)

# $(OBJS):		$(SRCS) $(HEADERS)
# 					$(CC) $(CFLAGS) $(INCLUDES:%=-I%) -c $(SRCS)

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:				$(NAME)

clean:
					rm -rf $(OBJS)
					rm -rf $(OBJS_DIR)

fclean:				clean
					rm $(NAME)

re:					fclean all

debug:
					echo "\n"
					echo "SRCS: $(SRCS)"
					echo "\n"
					echo "OBJS: $(OBJS)"
					echo "\n"
					echo "HEADERS: $(HEADERS)"
					echo "\n"
					echo "INCLUDES: $(INCLUDES)"

.PHONY:				all clean fclean re
