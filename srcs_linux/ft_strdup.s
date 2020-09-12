	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy
ft_strdup:
	push	rbx
	mov		rbx,		rdi
	call	ft_strlen
	mov		rdi,		rax
	add		rdi,		1
	call	malloc
	test	rax,		rax
	jz		end
	mov		rsi,		rbx
	mov		rdi,		rax
	call	ft_strcpy
	mov		rax,		rdi
end:
	pop		rbx
	ret
