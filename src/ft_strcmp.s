section .text
global ft_strcmp

ft_strcmp:
	xor rcx, rcx

.loop:
	mov al, [rdi+rcx]
	cmp al, [rsi+rcx]
	jne .done
	test al, al
	jz .done
	inc rcx
	jmp .loop

.done:
	movzx eax, byte [rdi+rcx]
	movzx edx, byte [rsi+rcx]
	sub eax, edx
	ret
