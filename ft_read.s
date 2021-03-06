			section	.data
SYS_read	equ 	SYS_read
			section	.text
			global	ft_read

ft_read:								; fd = rdi, buffer = rsi, bytes = rdx
			mov		rax, SYS_read
			syscall
			ret