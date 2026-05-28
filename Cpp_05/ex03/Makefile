NAME        = exec

CXX         = c++
CXXFLAGS    = -g -Wall -Wextra -Werror -std=c++98

SRCSDIR     = src/

SRCS        = main.cpp \
			  Bureaucrat.cpp Intern.cpp\
			  AForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp

SRCFILES    = $(addprefix $(SRCSDIR), $(SRCS))

OBJDIR      = .obj
OBJS        = $(SRCS:.cpp=.o)
OBJFILES    = $(addprefix $(OBJDIR)/,$(OBJS))

RM          = rm -rf
MKDIR       = mkdir -p

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

$(OBJDIR)/%.o: $(SRCSDIR)%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $(NAME)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
