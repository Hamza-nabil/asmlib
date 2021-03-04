SRCS		=	ft_strlen.s ft_strcmp.s ft_read.s ft_write.s ft_strcpy.s \
				ft_strdup.s  ft_list_size_bonus.s ft_list_push_front_bonus.s \
OBJS		=	$(SRCS:.s=.o)
# BONUS_SRCS	=	ft_atoi_base_bonus.s ft_list_size_bonus.s ft_list_push_front_bonus.s \
# 				ft_list_remove_if_bonus.s ft_list_sort_bonus.s
# BONUS_OBJS	=	$(BONUS_SRCS:.s=.o)

NA			=	nasm
NA_FLAGS	=	-f elf64
FLAGS 		=	
NAME		=	libasm.a
TEST		=	test
# TEST_BONUS	=	test_bonus

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -rf *.o

fclean:			clean
				rm -rf $(NAME)  $(TEST)

re:				fclean $(NAME)

test:			$(NAME)
				@gcc -c main.c
				@gcc -no-pie -o $(TEST) main.o $(NAME)
				@./$(TEST)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

test_bonus:		bonus
				gcc $(FLAGS) -L. -lasm -o $(TEST_BONUS) main_bonus.c
				./$(TEST_BONUS)

.PHONY:			clean fclean re test bonus test_bonus