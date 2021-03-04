			section	.text
			extern	malloc
			global	ft_list_push_front.s

;void	list_push_front(t_list **begin_list, void *data)
ft_list_push_front: ;  list_push_bask(rdi, rsi)

		push	rdi								;save rdi
		mov		rdi				, 16			
		call	malloc							;new_list = malloc(16);
		pop		rdi
		mov		[rax]		, rsi			;new->data = data
		mov		rcx 			, [rdi]
		mov		[rax + 8] , rcx			;new->next = *begin_list
		mov		[rdi]		, rax			;*begin_list = new;
