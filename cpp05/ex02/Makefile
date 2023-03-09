NAME			= bureaucrat_form
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Wextra -std=c++98 -MD #-Werror
SRC_FILES		= Bureaucrat.cpp AForm.cpp AForm.cpp ShrubberyCreationForm.cpp main.cpp
OBJ_FILES		= $(addprefix obj/,$(notdir $(SRC_FILES:.cpp=.o)))

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	@$(CXX) $(CPPFLAGS) -o $@ $^ 

obj/%.o : %.cpp  obj
	@$(CXX) $(CPPFLAGS) -c $< -o $@

obj :
	@mkdir obj

clean :
	@rm -rf obj
	@rm -f *_shrubbery

run:
	@make
	@./$(NAME)

fclean : clean
	@rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re
