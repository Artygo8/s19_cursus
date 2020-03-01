section.text:
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy
_ft_strdup:
	push	rbx
	mov		rbx,		rdi
	call	_ft_strlen
	mov		rdi,		rax
	add		rdi,		1
	call	_malloc
	test	rax,		rax
	jz		end
	mov		rsi,		rbx
	mov		rdi,		rax
	call	_ft_strcpy
	mov		rax,		rdi
end:
	pop		rbx
	ret
