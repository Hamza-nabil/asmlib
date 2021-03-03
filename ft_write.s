			section	.text
			global	ft_write

ft_write:								; fd = rdi, buffer = rsi, bytes = rdx
			mov		rax, 0x000001
			syscall
			ret