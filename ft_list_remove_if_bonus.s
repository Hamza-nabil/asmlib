
section	.bss
		head	resq	2
		data	resq	2
		cmp_fun	resq	2
		tmp1	resq	2
		tmp2	resq	2
		h_deref	resq	2

section	.text
		extern	free
		global	ft_list_remove_if

ft_list_remove_if:
		mov		QWORD[head], rdi		
		mov		QWORD[data], rsi
		mov		QWORD[cmp_fun], rdx
		cmp		QWORD[head], 0
		je		end								; if (head == NULL)	return
		mov		rax, [rdi]
		mov		QWORD[h_deref],rax				; h_derf = *head
remove_head:
		cmp		QWORD[h_deref], 0
		je		return
		mov		rdi, QWORD[h_deref]
		mov		rdi, QWORD[rdi]					; rdi = (*head)->data
		mov		rsi, QWORD[data]				; rsi = data
		call	QWORD[cmp_fun]
		cmp		rax, 0
		jne		middle							; if (cmp((*head)->data, data) != 0) goto middle 
		mov		rax, QWORD[h_deref]				; rax = *head
		mov		QWORD[tmp1],rax					; tmp1 = head
		mov		rax, QWORD[h_deref]
		mov		rax, [rax + 8]
		mov		QWORD[h_deref], rax				; *head = (*head)->next
		mov		rdi, QWORD[tmp1]				; rdi = tmp1
		mov		rdi, QWORD[rdi]					; rdi = tmp1->data
		call	free							; free(tmp1->data)
		mov		rdi, QWORD[tmp1]				; rdi = tmp1
		call	free							; free(tmp1)
		jmp		remove_head
middle:
		mov		rax, QWORD[h_deref]				
		mov		QWORD[tmp2], rax				; tmp2 = *head
remove_middle:
		mov		rax, QWORD[h_deref]				; rax = *head
		cmp		QWORD[rax + 8], 0
		je		reset_head						; if ((*head)->next == NULL) goto reset_head
		mov		rdi, QWORD[rax + 8]				; rdi = (*head)->next
		mov		rdi, QWORD[rdi]					; rdi = (*head)->next->data
		mov		rsi, QWORD[data]				; rsi = data
		call	QWORD[cmp_fun]
		cmp		rax, 0
		jne		inc_List						; if (cmp((*head)->next->data, data) != 0) goto increment
		mov		rax, QWORD[h_deref]				; rax = *head
		mov		rax, QWORD[rax + 8]				; rax = (*head)->next
		mov		QWORD[tmp1], rax				; tmp1 = (*head)->next
		mov		rax, QWORD[rax + 8]				; rax = (*head)->next->next
		mov		rcx, QWORD[h_deref]				; rcx = *head
		mov 	QWORD[rcx + 8], rax				; (*head)->next = (*head)->next->next;
		mov		rdi, QWORD[tmp1]				; rdi = tmp1
		mov		rdi, QWORD[rdi]					; rdi = tmp1->data
		call	free							; free(tmp1->data)
		mov		rdi, QWORD[tmp1]				; rdi = tmp1
		call	free							; free(tmp1)
		jmp		remove_middle
inc_List:
		mov		rax, QWORD[h_deref]
		mov		rax, [rax + 8]
		mov		QWORD[h_deref], rax				; *head = (*head)->next
		jmp		remove_middle
reset_head:
		mov	rax, QWORD[tmp2]
		mov	QWORD[h_deref], rax					; *head = tmp2
return:
		mov rax, QWORD[head]
		mov	rdx, QWORD[h_deref]
		mov	QWORD[rax], rdx
end:
		ret