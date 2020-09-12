	global	ft_read
ft_read:
	push	rbx
	mov		rax,		0
	syscall
	cmp		rdi,		1
	je		error
	mov		rbx,		rax
	mov		rsi,		3
	mov		rax,		72
	syscall
	and		rax,		0b100
	cmp		rax,		0
	jne		error
	mov		rax, 		rbx
	pop		rbx
	ret

error:
	mov		rax,		-1
	pop		rbx
	ret
