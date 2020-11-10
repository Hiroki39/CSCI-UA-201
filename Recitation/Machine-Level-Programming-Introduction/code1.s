	.file	"code4.c"
	.text
	.globl	plus
	.type	plus, @function
plus:
.LFB0:
	.cfi_startproc
	leaq	(%rdi,%rsi), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	plus, .-plus
	.globl	sumstore
	.type	sumstore, @function
sumstore:
.LFB1:
	pushq	%rbx
	movq	%rdx, %rbx
	call	plus
	movq	%rax, (%rbx)
	popq	%rbx
	ret
.LFE1:
	.size	sumstore, .-sumstore
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
