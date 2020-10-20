	.file	"code2.c"
	.text
	.globl	exchange
	.type	exchange, @function
exchange:
.LFB0:
	movq	(%rdi), %rax
	movq	%rsi, (%rdi)
	ret
.LFE0:
	.size	exchange, .-exchange
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
