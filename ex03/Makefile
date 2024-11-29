NAME     = a.out
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 
SRCS     = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS     = $(SRCS:.cpp=.o)
INCLUDES	= -I .
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) *_shrubbery

fclean: clean
	$(RM) $(NAME)
	$(RM) *_shrubbery

re: fclean all

.PHONY: all clean fclean re