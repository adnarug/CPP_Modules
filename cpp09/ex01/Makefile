NAME			= RPN
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Wextra -std=c++98 -MD -g #-fsanitize=address #-WERRRO!!!
SRC_FILES		=  main.cpp RPN.cpp
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

fclean : clean
	@rm -f $(NAME)

re : clean all

run : 
	@make
	@echo  ***Subject Test***
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@./$(NAME) "7 7 * 7 - "
	@./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@./$(NAME) "(1 + 1)"

.PHONY : all clean fclean re
