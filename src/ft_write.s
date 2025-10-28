section .text
global ft_write
extern __errno_location


ft_write:
	mov rax, 1
	syscall
	cmp rax, 0
	jge .done
.error:
	neg rax
	mov rcx, rax
	call __errno_location wrt ..plt
	mov [rax], ecx
	mov rax, -1
.done:
	ret
