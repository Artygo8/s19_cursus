		global	ft_strlen
ft_strlen:
		mov		rax, -1
add_loop:
		inc		rax
		cmp		byte [rdi + rax], 0
		jne		add_loop
		ret
