			section	.text
			global	ft_strlen
ft_strlen:
	mov rdx, 0
increment:
		inc rdx 
cmp		BYTE[rdi + rdx], 0
jnz     increment
mov		rax, rdx
ret
