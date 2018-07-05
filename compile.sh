make re -C ./libft
gcc -c -Wall -Werror -Wextra get_next_line.c -ggdb3 -I ./libft
gcc -c -Wall -Werror -Wextra main.c -I ./libft
gcc -o test_gnl get_next_line.o main.o -L ./libft -lft
make fclean -C ./libft
