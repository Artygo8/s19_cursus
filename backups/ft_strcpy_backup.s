		extern	_ft_strlen
		global	_ft_strcpy
_ft_strcpy:
		push 	rbx
		mov		rbx,			rdi
		mov		rdi,			rsi
		call	_ft_strlen
		mov		rdi,			rbx
loop:
		mov		dl,				[rsi + rax]
		mov		[rdi + rax],	dl
		dec		rax
		cmp		rax, 			-1
		jnz		loop
		mov		rax,			rsi
		pop		rbx
		ret
