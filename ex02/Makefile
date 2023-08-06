NAME		=	test

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

INCS		=	./Account.hpp\

SRCS		=	./tests.cpp\
				./Account.cpp\

OBJS		=	$(SRCS:%.cpp=%.o)

RM 			=	rm -f

all:	$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%o:	%.cpp $(INCS)
	$(CXX) $(CXXFLAGS) $(INCS) -c $^ -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re