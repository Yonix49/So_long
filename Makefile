# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 15:25:26 by mhajji-b          #+#    #+#              #
#    Updated: 2023/03/01 12:07:40 by mhajji-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRC_DIR = ./SRCS

SRCS	= cord_start_ext.c ft_split.c get_next_line.c get_next_line_utils.c parsing.c\
			pathfinding.c so_long.c utils_1.c parsing2.c parsing3.c display_img.c\
			get_map.c move_image.c The_end.c get_cord_conso.c utils_2.c
			

OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))

NAME			=	so_long

CC				=	gcc

CFLAGS			=	-g -Wall -Werror -Wextra -g3

RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	cd minilibx-linux && make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) minilibx-linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx_linux/


clean:	
	cd minilibx-linux && make clean	
	${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean			
		${RM} ${NAME} $(BONUS)

re:			fclean all

.PHONY: 	all clean fclean re
