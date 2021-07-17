	global	_ft_write
_ft_write:
	push	rbx
	mov		rax,		0x2000004
	syscall
	cmp		rdi,		1
	je		error
	mov		rbx,		rax
	mov		rsi,		3
	mov		rax,		0x200005C
	syscall
	and		rax,		0b1000
	cmp		rax,		0
	jne		error
	mov		rax, 		rbx
	pop		rbx
	ret

error:
	mov		rax,		-1
	pop		rbx
	ret
