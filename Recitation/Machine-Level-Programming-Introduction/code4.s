	.file	"code2.c"
	.text
	.globl	set
	.type	set, @function
set:
.LFB0:
	movq	%rsi, (%rdi)
	leaq	1(%rsi), %rax
	movq	%rax, 8(%rdi)
	leaq	2(%rsi), %rax
	movq	%rax, 16(%rdi)
	addq	%rdx, %rsi
	movq	%rsi, (%rdi,%rdx,8)
	ret
.LFE0:
	.size	set, .-set
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
