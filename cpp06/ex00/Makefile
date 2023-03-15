NAME			= convert
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Werror -Wextra -std=c++98 -MD
SRC_FILES		=  main.cpp ScalarConverter.cpp
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


test:
	@make
	@echo "*****Subject tests*****"
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f
	@echo "*****My tests*****"
	./$(NAME) 123123123
	./$(NAME) 123
	./$(NAME) -10.5f

fclean : clean
	@rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re
