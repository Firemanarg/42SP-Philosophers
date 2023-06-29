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

NAME			= philo

CC				= clang
CFLAGS			= -Wall -Wextra -Werror

SRCS			= $(shell find $(SOURCEDIR) -name '*.c')
OBJS			= $(SRCS:%.c=%.o)
HEADERS			= $(shell find $(SOURCEDIR) -name '*.h')
INCLUDES		= $(dir $(HEADERS))

$(OBJS):	$(SRCS) $(HEADERS)
				$(CC) $(CFLAGS) $(INCLUDES:%=-I%) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:			$(NAME)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm $(NAME)

re:				fclean all

debug:
				echo "\n"
				echo "SRCS: $(SRCS)"
				echo "\n"
				echo "OBJS: $(OBJS)"
				echo "\n"
				echo "HEADERS: $(HEADERS)"
				echo "\n"
				echo "INCLUDES: $(INCLUDES)"

.PHONY:			all clean fclean re
