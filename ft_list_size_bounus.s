
			section	.text
			global	ft_list_size

; int list_size(t_list *head)
ft_list_size: ; rax list_size(rdi)

		xor rax			, rax			; i = 0;
		jmp compare

increment:
		inc rax
		mov rdi			, [rdi + 8]

compare :
		cmp DWORD [rdi]	, 0
		je increment
		ret