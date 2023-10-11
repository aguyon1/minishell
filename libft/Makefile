# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 23:06:31 by aguyon            #+#    #+#              #
#    Updated: 2023/10/11 22:36:37 by aguyon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_ALLOC		=	alloc/

DIR_BTREE		=	btree/

DIR_CONVERT		=	convert/

DIR_IO			=	io/

DIR_LIST		=	list/

DIR_PREDICATE	=	predicate/

DIR_STRING		=	string/

DIR_XLIB		=	xlib/

NAME_ALLOC		=	ft_calloc.c \
					ft_realloc.c

NAME_BTREE		=	btree_apply_by_level.c \
					btree_apply_infix.c \
					btree_apply_prefix.c \
					btree_apply_suffix.c \
					btree_array_to_tree.c \
					btree_create_node.c \
					btree_free.c \
					btree_insert_data.c \
					btree_level_count.c \
					btree_search_item.c

NAME_CONVERT	=	ft_atoi.c \
					ft_itoa.c \
					ft_tolower.c \
					ft_toupper.c

NAME_IO			=	ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					get_next_line.c

NAME_LIST		=	ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstsize.c

NAME_PREDICATE	=	ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_islower.c \
					ft_isprint.c \
					ft_isspace.c \
					ft_isupper.c

NAME_STRING		=	ft_bzero.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_split.c \
					ft_strcat.c \
					ft_strchr.c \
					ft_strcmp.c \
					ft_strcspn.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strncpy.c \
					ft_strndup.c \
					ft_strnstr.c \
					ft_strpbrk.c \
					ft_strrchr.c \
					ft_strscpy.c \
					ft_strslen.c \
					ft_strspn.c \
					ft_strtrim.c \
					ft_substr.c

NAME_XLIB		=	xcalloc.c \
					xrealloc.c \
					xsplit.c \
					xstrdup.c \
					xstrjoin.c \
					xstrndup.c \
					xsubstr.c

SRC_ALLOC		=	$(addprefix ${DIR_ALLOC}, ${NAME_ALLOC})

SRC_BTREE		=	$(addprefix ${DIR_BTREE}, ${NAME_BTREE})

SRC_CONVERT		=	$(addprefix ${DIR_CONVERT}, ${NAME_CONVERT})

SRC_IO			=	$(addprefix ${DIR_IO}, ${NAME_IO})

SRC_LIST		=	$(addprefix ${DIR_LIST}, ${NAME_LIST})

SRC_PREDICATE	=	$(addprefix ${DIR_PREDICATE}, ${NAME_PREDICATE})

SRC_STRING		=	$(addprefix ${DIR_STRING}, ${NAME_STRING})

SRC_XLIB		=	$(addprefix ${DIR_XLIB}, ${NAME_XLIB})

DIR_SRC			=	src/

SRC_NAME		=	$(SRC_ALLOC) $(SRC_BTREE) $(SRC_CONVERT) $(SRC_IO) $(SRC_LIST) $(SRC_PREDICATE) $(SRC_STRING) $(SRC_XLIB)

SRC				=	$(addprefix $(DIR_SRC), $(SRC_NAME))

DIR_HEADER		=	inc/

HEADER			=	$(DIR_HEADER)/libft.h

OBJS = ${SRC:%.c=$(DIR_BUILD)/%.o}

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB_ALLOC		= ./liballoc/liballoc.a

DIR_BUILD		= build

LD_FLAGS		= -L./liballoc -lalloc

all :	$(NAME)

$(DIR_BUILD)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LD_FLAGS) -c $< -o $@

$(NAME) :	${HEADER} $(LIB_ALLOC) ${OBJS}
			ar rcs ${NAME} ${OBJS}

$(LIB_ALLOC):
			make -C liballoc/

clean :
	rm -rf $(DIR_BUILD)

fclean :	clean
			rm -f ${NAME}

re :	fclean all

.PHONY : all clean fclean re bonus
