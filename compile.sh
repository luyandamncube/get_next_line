make re ./libft
gcc -Wall -Werror -Wextra get_next_line.c mainc.c -I ./libft 
gcc -Wall -Werror -Wextra get_next_line.c get_next_line.c -I ./libft
gcc -o run main.o get_next_line.o -L ./libft -lft
#-ggdb3 -o run