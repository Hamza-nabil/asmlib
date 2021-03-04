
			section	.text
			global	C_strcpy

;char *ft_strcpy(char *dest, const char *src);

C_strcpy: ; rax ft_strcpy(rdi, rsi);

		xor	rax, rax
compare :
		cmp	BYTE [rsi + rax] , 0
		je	return
		mov	dl ,BYTE [rsi + rax]
		mov BYTE [rdi + rax] , dl
		inc rax
		jmp compare
return :
		mov BYTE [rdi + rax] , 0
		mov rax , rdi
		ret