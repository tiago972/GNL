CC = clang 
CFLAGS = -Wall -Wextra -Werror -I $(INCL)
OBJDIR = objs
SRCDIR = ./srcs
SRC = ft_putchar.c ft_putstr.c ft_putnbr.c \
	   ft_strcat.c ft_strlen.c ft_strdup.c \
	   ft_strcmp.c ft_atoi.c ft_memset.c \
	   ft_bzero.c ft_memcpy.c ft_memchr.c \
	   ft_memcmp.c ft_strcpy.c ft_memccpy.c \
	   ft_strncpy.c ft_strncat.c ft_strchr.c \
	   ft_strrchr.c ft_strstr.c ft_strnstr.c \
	   ft_strncmp.c ft_isalpha.c ft_isdigit.c \
	   ft_isalnum.c ft_isprint.c ft_isascii.c \
	   ft_memmove.c ft_strlcat.c ft_tolower.c \
	   ft_toupper.c ft_memalloc.c ft_memdel.c \
	   ft_strnew.c ft_strdel.c ft_strclr.c \
	   ft_striter.c ft_striteri.c ft_strmap.c \
	   ft_strmapi.c ft_strequ.c ft_strnequ.c \
	   ft_strsub.c ft_strjoin.c ft_strtrim.c \
	   ft_strsplit.c ft_print_words_tables.c \
	   ft_itoa.c ft_strrev.c ft_putendl.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
	   ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	   ft_realloc.c ft_putchar_err.c ft_putstr_err.c
INCL = ./includes
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SRC))))
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $?
	ranlib $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS) 

clean: 
	rm -f $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
