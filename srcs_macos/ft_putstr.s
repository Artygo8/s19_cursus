	global	_ft_putstr
	extern	_ft_write
	extern	_ft_strlen
_ft_putstr:
	call	_ft_strlen
	mov		rdx,		rax
	mov		rsi,		rdi
	mov		rdi,		1
	call	_ft_write
	ret
