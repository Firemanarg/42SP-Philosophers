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

SRCS_DIR			= philo/srcs
SRCS				= main.c \
					  utils/ft_atoi.c \
					  utils/ft_atoll.c \
					  utils/ft_isdigit.c \
					  utils/get_mstime.c \
					  utils/is_valid_number.c \
					  routines/manager_routine.c \
					  routines/philo_routine.c \
					  initializers/init_manager.c \
					  initializers/init_philos.c \
					  core_utils/get_philo_state.c \
					  core_utils/set_philo_state.c \
					  core_utils/philo_finished_meal.c \
					  core_utils/philo_starved.c \
					  core_utils/philo_woke_up.c \
					  core_utils/print_message.c \
					  core_utils/release_forks.c \
					  core_utils/take_forks.c
OBJS_DIR			= objs
OBJS				= $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))
HEADERS				= $(SRCS_DIR)/core.h \
					  $(SRCS_DIR)/utils/utils.h
SUBDIRS				= $(dir $(SRCS))
INCLUDES			= utils routines initializers core_utils

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(HEADERS)
					mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/, $(SUBDIRS))
					$(CC) $(CFLAGS) $(INCLUDES:%=-I%) -c $< -o $@

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
