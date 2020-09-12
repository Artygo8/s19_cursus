	global	ft_putstr
	extern	ft_write
	extern	ft_strlen
ft_putstr:
	call	ft_strlen
	mov		rdx,		rax
	mov		rsi,		rdi
	mov		rdi,		1
	call	ft_write
	ret
