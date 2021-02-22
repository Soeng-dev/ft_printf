NAME = libftprintf.a
AR = ar -crs
COMP = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = -L./libft -lft
SRC = ./ft_printf/ft_printf.c		\
	  ./ft_printf/ft_putnbr_base.c	\
	  ./ft_printf/prt_char.c		\
	  ./ft_printf/prt_hexa.c		\
	  ./ft_printf/prt_int.c			\
	  ./ft_printf/prt_ptr.c			\
	  ./ft_printf/ft_putuint_fd.c	\
	  ./ft_printf/prt_str.c			\
	  ./ft_printf/prt_pct.c			\
	  ./ft_printf/iter_write.c		\
	  ./ft_printf/ftmin.c			\
	  ./ft_printf/ftmax.c			\
	  ./ft_printf/get_uintarg.c		\
	  ./ft_printf/get_intarg.c		\
	  ./ft_printf/manage_tag.c		\
	  ./ft_printf/prt_uint.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) libft
		cp libft/libft.a ./$(NAME)
		$(AR) $(NAME) $(OBJ) 

# libft compile
libft :
		@$(MAKE) -C ./libft all

clean :
		@$(MAKE) -C ./libft clean
		@rm -rf $(OBJ)
fclean : clean
		@$(MAKE) -C ./libft fclean
		@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re libft
