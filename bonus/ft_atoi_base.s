		global	_ft_strcmp
_ft_strcmp:
		mov		rax,				-1
loop:
		inc		rax
		mov		dl,					[rsi + rax]
		cmp		byte [rdi + rax],	0
		jz		diff
		cmp		byte [rdi + rax],	dl
		jz		loop
diff:
		mov		rdi,				[rdi + rax]
		mov		rsi,				[rsi + rax]
		mov		ax,					di
		sub		ax,					si
		cmp		di,					si
		jge		return
		sub		rax,				65536
return:
		ret
