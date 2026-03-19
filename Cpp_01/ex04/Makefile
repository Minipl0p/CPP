NAME        = SedIsForLosers

CXX         = c++
CXXFLAGS    = -g -Wall -Wextra -Werror -std=c++98

SRCS        = main.cpp \

OBJDIR      = .obj
OBJS        = $(SRCS:.cpp=.o)
	OBJFILES    = $(addprefix $(OBJDIR)/,$(OBJS))

RM          = rm -rf
MKDIR       = mkdir -p

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $(NAME)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
