##
## Makefile for Makefile in /home/loisel_k/travail/Systeme-Unix/my_ls/src
## 
## Made by kevin loiseleur
## Login   <loisel_k@epitech.net>
## 
## Started on  Sat Nov 30 00:34:56 2013 kevin loiseleur
## Last update Sun Dec  1 20:34:33 2013 kevin loiseleur
##

NAME		= my_ls

OBJ		= main_ls.c \
		ls_parser.c \
		ls_aff.c \
		lex_path.c \
		lex_opt.c \
		tools.c \
		find_comp.c \
		find_comp2.c \

OBJ		= $(SRC:.c=.o)

CC		= cc

CP		= cp

RM		= RM -f

HFILES		= my_ls.h \

LIBS		= -lmy -llibdlc.a -L.

all: $(NAME)

$(NAME): $(OBJ)
	$(CP) $(HFILES) ../include
	$(CC) $(OBJ) -o $(NAME) -lmy -L ../ -I ../include
	$(CP) $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all
