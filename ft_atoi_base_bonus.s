section	.bss
		string	resq 	2
		base	resq 	1
		n		resq 	1
section	.data
		result	dq	0
		signe	dq	1
		
section	.text
		global	ft_list_remove_if

ft_list_remove_if:
		; mov		QWORD[string], rdi
		; mov		WORD[base], rsi
		cmp		rsi, 2
		jl		return
		cmp		rsi, 16
		jg		return
		xor		rax, rax
skip_ws:
		cmp		BYTE[rdi + rax], 32
		je		inc_ws
		jmp		take_signe
inc_ws:
		inc		rax
		jmp		skip_ws
take_signe:
		cmp		rsi, 10
		jne		ab
		cmp		BYTE[rdi + rax], '-'
		jne		ab
		mov		QWORD[signe], -1
		inc		rax
ab:
		jmp		convert
check_base:
		cmp		rcx, base
		jge		return;
		cmp		rcx, 0
		jl		return
		push 	rax
		mov		rax, QWORD[result]
		mul		rsi
		add		rax, rcx
		mov		QWORD[result], rax
		pop		rax
		inc		rax
return:
		mov 	rax, QWORD[result]
		mul		QWORD[signe]
		ret
convert:
		cmp		QWORD[rdi + rax], 97
		jl		upercase
		mov		rcx, QWORD[rdi + rax]
		sub		rcx, 87
		jmp		check_base
upercase:
		cmp		QWORD[rdi + rax], 65
		jl		numerique
		mov		rcx, QWORD[rdi + rax]
		sub		rcx, 55
		jmp		check_base
numerique:
		mov		rcx, QWORD[rdi + rax]
		sub		rcx, 48
		jmp		check_base

