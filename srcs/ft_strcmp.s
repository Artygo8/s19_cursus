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
	mov		al,					dil
	sub		al,					sil
	cmp		dil,				sil
	jge		return
	sub		rax,				256
return:
	ret
