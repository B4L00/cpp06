CPP			:=	c++
CPPFLAGS	:=	-g -Wall -Wextra -Werror -std=c++98
OBJFLAGS 	:=	-c

NAME		:=	serialize

SRCS_F		:= 	main \
				Serializer \
				Data

SRCS		:=	$(addsuffix .cpp, $(SRCS_F))
OBJ			:=	$(addsuffix .o, $(SRCS_F))

DEP			:= Makefile Serializer.hpp Data.hpp

all: 		$(NAME)

%.o:		%.cpp $(DEP)
				$(CPP) $(CPPFLAGS) $(OBJFLAGS) $< -o $@ -I.

$(NAME):	$(OBJ)
				$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
				@rm -f $(OBJ)

fclean:		clean
				@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re