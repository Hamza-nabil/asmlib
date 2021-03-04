			section	.text
			global	ft_strlen
ft_strlen:
		xor	rax, rax
increment:
		inc rax 
		cmp	BYTE[rdi + rax], 0
		jne	increment
		ret
