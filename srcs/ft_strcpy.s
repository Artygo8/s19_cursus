		global	_ft_strcpy
_ft_strcpy:
		mov		rax,			-1
loop:
		inc		rax
		mov		dl,				[rsi + rax]
		mov		[rdi + rax],	dl
		cmp		byte [rsi + rax], 	0
		jnz		loop
		mov		rax,			rsi
		ret
