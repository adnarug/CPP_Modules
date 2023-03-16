NAME			= convert
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Werror -g -Wextra -std=c++98 -MD 
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
	@echo TEST1 #non displayable
	@echo My---------------
	./$(NAME) 0
	@echo Jaad---------------
	./jaad 0

	@echo TEST2
	@echo My---------------
	./$(NAME) nan
	@echo Jaad---------------
	./jaad nan

	@echo TEST3
	@echo My---------------
	@echo ---------------
	./$(NAME) 42.0f
	@echo Jaad---------------
	./jaad 42.0f

	@echo TEST4
	@echo ---------------
	./$(NAME) -inf
	@echo Jaad---------------
	./jaad -inf

	@echo TEST5
	@echo ---------------
	./$(NAME) +inf
	@echo Jaad---------------
	./jaad +inf


	@echo TEST6
	@echo ---------------
	./$(NAME) -42
	@echo Jaad---------------
	./jaad -42

	@echo TEST7
	@echo ---------------
	./$(NAME) 42
	@echo Jaad---------------
	./jaad 42

	@echo TEST8
	@echo ---------------
	./$(NAME) c
	@echo Jaad---------------
	./jaad c

	@echo TEST9
	@echo ---------------
	./$(NAME) 12312312312312
	@echo Jaad---------------
	./jaad -123123123123

	@echo TEST10
	@echo ---------------
	./$(NAME) 12312312312312312312.12312312312312312312
	@echo Jaad---------------
	./jaad 12312312312312312312.12312312312312312312

	@echo TEST11
	@echo ---------------
	./$(NAME) -123123123123
		@echo Jaad---------------
	./jaad -123123123123

	@echo TEST12
	@echo --------------
	./$(NAME) -123123123123.ad122312
		@echo Jaad---------------
	./jaad -123123123123.ad122312

	@echo TEST13
	@echo --------------
	./$(NAME) -1a3123123123.122312
		@echo Jaad---------------
	./jaad -1a3123123123.122312
# Run tests ===========================


fclean : clean
	@rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re
