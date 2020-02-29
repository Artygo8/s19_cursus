	global	_ft_strdup
	extern	_ft_strlen
	extern	_malloc
_ft_strdup:
	push	rbx
	mov		rbx,		[rdi]
	call	_ft_strlen
	mov		rdi,		rax
	call	_malloc
	pop		rbx
	ret
