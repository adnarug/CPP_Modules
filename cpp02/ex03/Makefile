NAME			= bsp
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98 -MD -fsanitize=address
SRC_FILES		=  Fixed.cpp main.cpp Point.cpp bsp.cpp
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

log:
	@make
	@./$(NAME) > my_log

run : 
	@make
	@./$(NAME)

fclean : clean
	@rm -f $(NAME)
	@rm -f my_log

re : clean all

.PHONY : all clean fclean re
