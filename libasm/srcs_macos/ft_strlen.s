		global	_ft_strlen
_ft_strlen:
		mov		rax, -1
add_loop:
		inc		rax
		cmp		byte [rdi + rax], 0
		jne		add_loop
		ret
