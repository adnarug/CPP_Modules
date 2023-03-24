NAME			= easyfind
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Werror -Wextra -std=c++98 -MD 
SRC_FILES		=  main.cpp 
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
	@./$(NAME)

.PHONY : all clean fclean re
