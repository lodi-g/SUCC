LEXER	:=	flex
PARSER	:=	bison
LFILE	:=	lexer.c
PFILE	:=	parse.c

RM	:=	rm -f

CC	:=	gcc
CFLAGS	:=	-Wall -Wextra

SRCS	:=	main.c
SRCS	:=	$(addprefix srcs/, $(SRCS))

OBJS	:=	$(patsubst %.c, %.o, $(SRCS))

NAME	:=	SBMLParser

all:	$(NAME)

$(NAME):$(OBJS) $(PFILE) $(LFILE)
	$(CC) -o $@ $^ $(LDFLAGS)
	$(RM) $(LFILE) $(PFILE)
	$(RM) $(patsubst %.c, %.h, $(PFILE))

$(LFILE):lexer.l
	$(LEXER) -o $@ $^

$(PFILE):parse.y
	$(PARSER) -d -o $@ $^

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
