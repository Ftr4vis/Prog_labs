.586 
.MODEL FLAT, STDCALL
PUBLIC summa
_DATA SEGMENT
	mas db 'Memory good',0
_DATA ENDS
_TEXT SEGMENT
	summa PROC num1:DWORD, num2:DWORD
		mov EAX, num1
		mov EBX, num2
		ADD EAX, EBX
		ret
	summa ENDP
_TEXT ENDS
END