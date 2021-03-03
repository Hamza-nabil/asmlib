			section	.text
			extern	malloc
			extern	ft_strlen
			extern	ft_strcpy
			global	ft_strdup

; char *ft_strdup(const char *s)
ft_strdup:						; rax ft_strfup(rdi)

	push rdi					; save rdi
	call ft_strlen				; rax = strlen(rdi)
	mov rdi, rax				; rdi = rax;
	inc rdi						; rdi++
	call malloc 				; rax = _malloc(rdi)
	pop rdi						; redtore saved rdi
	mov rsi, rdi
	mov rdi, rax 				
	call ft_strcpy
	ret

