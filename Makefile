##
## Makefile for make in /home/zanard_a/rendu/Projets Piscines/expr
##
## Made by Antoine Zanardi
## Login   <zanard_a@epitech.net>
##
## Started on  Tue Oct 21 16:47:57 2014 Antoine Zanardi
## Last update Wed Jan  7 13:43:17 2015 Antoine Zanardi
##

DEBUG	=	no

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g -Wall -Wextra -W
endif

LIB_PA	=	./lib/my/

NAME	=	my_select

SRCS	=	sources/main.c \
		sources/error.c \
		sources/lists.c \
		sources/term.c \
		sources/my_select.c \
		sources/fc_term.c \
		sources/police.c

SRCS_LI	=	$(LIB_PA)my_getnbr.c \
		$(LIB_PA)my_putchar.c \
		$(LIB_PA)my_put_nbr.c \
		$(LIB_PA)my_putstr.c \
		$(LIB_PA)my_strlen.c \
		$(LIB_PA)my_lists.c \

OBJS	=	$(SRCS:.c=.o)

OBJS_LI	=	$(SRCS_LI:.c=.o)

INC	=	-I include/

LIB_CMP	=	$(LIB_PA)libmy.a

CFLAGS	+=	$(INC)


all: $(LIB_CMP) $(NAME)

$(LIB_CMP): $(OBJS_LI)
	ar rc $(LIB_CMP) $(OBJS_LI)
	ranlib $(LIB_CMP)
	cp $(LIB_PA)my.h ./include/

$(NAME): $(OBJS)
	cc -Wall $(OBJS) lib/my/libmy.a -lncurses $(INC) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_LI)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_CMP)

re: fclean all

.PHONY: all clean fclean all
