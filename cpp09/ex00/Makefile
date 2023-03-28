NAME			= btc
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Wextra -std=c++98 -MD #-fsanitize=address #-WERRRO!!!
SRC_FILES		=  main.cpp BitcoinExchange.cpp
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
	@./$(NAME) input.csv

.PHONY : all clean fclean re
