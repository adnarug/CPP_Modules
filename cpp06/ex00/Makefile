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


# Run tests ===========================
tests: 
	./$(NAME) 0
	@echo ---------------
	./$(NAME) nan
	@echo ---------------
	./$(NAME) 42.0f
	@echo ---------------
	./$(NAME) -inf
	@echo ---------------
	./$(NAME) +inf
	@echo ---------------
	./$(NAME) -42
	@echo ---------------
	./$(NAME) 42
	@echo ---------------
	./$(NAME) c
	@echo ---------------
	./$(NAME) 12312312312312
# Run tests ===========================


fclean : clean
	@rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re
