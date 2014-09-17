##
## Makefile for Makefile in /home/loisel_k/travail/Librairie/listech/doubchaine
## 
## Made by kevin loiseleur
## Login   <loisel_k@epitech.net>
## 
## Started on  Mon Nov  4 17:16:59 2013 kevin loiseleur
## Last update Sun Dec  1 20:09:26 2013 kevin loiseleur
##

CC		= cc

CCLIB		= ar rc

ASSEMB		= ranlib

RM		= rm -f

CP		= cp

H_FILES		= liste.h

C_FILES		= list_init.c \
		elem_insert.c \
		elem_insert2.c \
		list_display.c \
		elem_del.c \
		list_del.c \
		list_tools.c

OBJ		= $(C_FILES:.c=.o)

NAME		= libdlc.a

INCL		= ../include/

LIB_PATH	= ../

all:$(NAME)

$(NAME): $(OBJ)
	$(CCLIB) $(NAME) $(OBJ)
	$(ASSEMB) $(NAME)
	$(CP) $(NAME) $(LIB_PATH)
	$(CP) $(H_FILES) $(INCL)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all
