make re -C ./libft
gcc -c -Wall -Werror -Wextra get_next_line.c -ggdb3 -I ./libft
gcc -c -Wall -Werror -Wextra get_from_std_io.c -I ./libft
gcc -o test_gnl get_next_line.o get_from_std_io.o -L ./libft -lft
make fclean -C ./libft
rm get_from_std_io.o
rm get_next_line.o