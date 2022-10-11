.586 
.MODEL FLAT, stdcall
PUBLIC itostr
_DATA SEGMENT
	StrMas db 11 dup(?)
	dec1 dd 10
_DATA ENDS
_TEXT SEGMENT
	itostr PROC par:DWORD
		lea EBX, StrMas
		mov ECX, 11
	label1:
		mov BYTE PTR [EBX], ' '
		inc EBX
		Loop label1
		mov EAX, par
		push EAX
		or EAX, EAX
		jns label2
		neg EAX
	label2:
		xor EDX, EDX
		div dec1
		add DX, '0'
		dec EBX
		mov BYTE PTR [EBX], DL
		inc ECX
		or EAX, EAX
		jnz label2
		pop EAX
		or EAX, EAX
		jns label3
		dec EBX
		mov BYTE PTR [EBX], '-'
		inc ECX
	label3:
		mov EAX, EBX
		ret
	itostr ENDP
_TEXT ENDS
END