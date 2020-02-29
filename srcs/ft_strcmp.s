	global	_ft_strcmp
_ft_strcmp:
	mov		rax,				-1
loop:
	inc		rax
	mov		dl,					[rsi + rax]
	cmp		byte [rdi + rax],	0
	jz		end
	cmp		byte [rdi + rax],	dl
	jz		loop
end:
	mov		rdi,				[rdi + rax]
	mov		rsi,				[rsi + rax]
	mov		rax,				rdi
	sub		rax,				rsi
	ret
