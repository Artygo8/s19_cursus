	global	_ft_read
_ft_read:
	push	rbx
	mov		rax,		0x2000003
	syscall
	cmp		rdi,		1
	je		error
	mov		rbx,		rax
	mov		rsi,		3
	mov		rax,		0x200005C
	syscall
	and		rax,		0b100
	cmp		rax,		0
	je		error
	mov		rax, 		rbx
	pop		rbx
	ret

error:
	mov		rax,		-1
	pop		rbx
	ret
