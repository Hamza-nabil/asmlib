			section	.text
			global	ft_read

ft_read:								; fd = rdi, buffer = rsi, bytes = rdx
			mov		rax, 0x0000000
			syscall
			ret