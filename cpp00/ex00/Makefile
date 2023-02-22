NAME			= megaphone
OBJ				= obj/
CXX				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98 -MD
SRC_FILES		= megaphone.cpp
OBJ_FILES		= $(addprefix $(OBJ), $(notdir $(SRC_FILES:.cpp=.o)))

all: $(NAME)

$(NAME) : $(OBJ_FILES)
	@$(CXX) $(CPPFLAGS) -o $@ $^

$(OBJ_FILES) : $(SRC_FILES) | obj_dir
	@$(CXX) $(CPPFLAGS) -c $? -o $(OBJ)$(notdir $@)

re: clean all

run:
	@make
	@./$(NAME)

obj_dir:
	@mkdir -p $(OBJ)

clean:
	@rm -f $(OBJ_FILES)
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

.PHONY: all re clean fclean