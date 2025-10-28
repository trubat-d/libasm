section .text
global ft_strdup
extern __errno_location
extern malloc
extern ft_strlen

ft_strdup:
	push 	r12	
	push 	r13

	mov 	r12, rdi
	call 	ft_strlen
	mov 	rdi, rax
	mov 	r13, rdi
	inc 	rdi
	
	sub 	rsp, 8
	call 	malloc wrt ..plt
	add	rsp, 8

	test 	rax, rax
	jz 	.error
	xor 	r8, r8
.loop:
	cmp 	r8, r13
	je 	.done
	mov 	r9b, [r12+r8]
	mov 	[rax+r8], r9b
	inc 	r8
	jmp 	.loop	
.done:
	mov 	byte [rax+r8], 0
.end:
	pop 	r13
	pop 	r12
	ret
.error:
	sub 	rsp, 8
	call 	__errno_location wrt ..plt
	add	rsp, 8	
	mov 	dword [rax], 12
	xor 	rax, rax
	jmp 	.end
