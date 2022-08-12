
NAME        := push_swap
CFLAGS            := -Iincludes -g -fPIE
FT_PRINTF_SRC    := libft/libft.a
FT_PRINTF_LIB    := libft/libft.a
SRC_CLIENT        :=	src/push_swap.c \
						src/ft_instruction.c \
						src/ft_free_tab.c \
						src/ft_better_tab.c \
						src/ft_sorting.c \
						src/ft_utils.c \
						src/ft_init_tab.c \
						src/ft_str.c \
						
CLIENT        := $(SRC_CLIENT:.c=.o)
PATH_LIB        = libft

all: $(PATH_LIB) $(FT_PRINTF_LIB) $(NAME) 

$(PATH_LIB):
	mkdir -p $(PATH_LIB)

$(FT_PRINTF_LIB):
	 make -C $(FT_PRINTF_SRC) all

src/client.o: src/client.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(CLIENT)
	@$(CC) $(CFLAGS) -o $@ $(CLIENT) $(FT_PRINTF_LIB) 

clean:
	@$(RM) $(CLIENT) $(NAME)
	:make -C $(FT_PRINTF_SRC) clean

fclean:            clean
	@$(RM) $(NAME)
	@$(RM) $(FT_PRINTF_LIB)
	make -C $(FT_PRINTF_SRC) fclean

re: fclean $(FT_PRINTF_LIB) $(NAME)

.PHONY:            all clean fclean re
