			section	.text
			global	ft_strcmp
ft_strcmp:
		xor rax , rax 				; i = 0
compare :
		mov dl , BYTE[rsi + rax]
		cmp dl, BYTE[rdi + rax] 	
		jg	greater
		jl	lesser
		cmp BYTE[rdi + rax], 0
		je	equal
		inc rax
		jmp compare
greater:
		mov rax, 1
		ret
lesser:
		mov rax, -1
		ret
equal:
		mov rax, 0
		ret