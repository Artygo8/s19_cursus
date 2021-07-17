	global	_ft_strcmp
ft_strcmp:
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
	and		rdi,				255
	mov		rsi,				[rsi + rax]
	and		rsi,				255
	mov		rax,				rdi
	sub		rax,				rsi
	ret
