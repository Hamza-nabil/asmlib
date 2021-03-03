			section	.text
			global	ft_strcmp
ft_strcmp:
	mov rdx , 0 ; i = 0
compare :
	mov dl , BYTE[rsi + rdx]
	cmp dl, BYTE[rdi + rdx] ; s1[i] - s2[i]
jg greater
jl lesser
cmp BYTE[rdi + rdx], 0
jz equal
inc rdx
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