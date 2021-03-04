
			section	.text
			global	ft_strcpy

;char *ft_strcpy(char *dest, const char *src);

ft_strcpy: ; rax ft_strcpy(rdi, rsi);

		xor rax, rax

copy :
		mov dl , BYTE[rsi + rax]
		mov BYTE[rdi + rax] , dl
		cmp BYTE[rsi + rax]	, 0
		je	end
		inc	rax
		jmp	copy
end :
		mov BYTE[rdi + rax]	, 0
		mov rax , rdi
		ret

