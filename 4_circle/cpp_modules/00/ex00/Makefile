NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

SRCS = megaphone.cpp
OBJS = megaphone.o

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm $(NAME)
re: fclean all