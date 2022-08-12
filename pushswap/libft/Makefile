# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alprival <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 11:57:09 by alprival          #+#    #+#              #
#    Updated: 2022/04/16 14:56:38 by alprival         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		= 	ft_calloc.c \
			ft_isascii.c \
			ft_itoa.c \
		    ft_memcmp.c \
			ft_memset.c \
			ft_putnbr_fd.c \
			ft_strchr.c \
			ft_strlcpy.c \
			ft_strncmp.c \
			ft_strtrim.c \
			ft_toupper.c \
			ft_atoi.c \
			ft_isalnum.c \
			ft_isdigit.c \
			ft_memcpy.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strnstr.c \
			ft_substr.c \
			ft_bzero.c \
			ft_isalpha.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memmove.c \
			ft_putendl_fd.c \
			ft_split.c \
			ft_striteri.c \
			ft_strlcat.c \
			ft_strmapi.c \
			ft_strrchr.c \
			ft_tolower.c \
			get_next_line.c \
			get_next_line_utils.c \

SRCBS	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c 

OBJ		= $(SRC:.c=.o)

OBJBS	= $(SRCBS:.c=.o)

CC		= gcc -g

RM		= rm -f

CFLAGS = -Werror -Wextra -Wall 

$(NAME):	$(OBJ)
	ar rcs libft.a $(OBJ)

bonus:	$(OBJBS)
	ar rcs libft.a $(OBJBS)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJBS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
