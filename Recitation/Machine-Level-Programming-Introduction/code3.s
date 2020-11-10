	.file	"code3.c"
	.text
	.globl	scale
	.type	scale, @function
scale:
.LFB0:
	.cfi_startproc
	leaq (%rdi,%rsi,4), %rax 
	leaq (%rdx,%rdx,2), %rdx 
	leaq (%rax,%rdx,4), %rax 
	ret
	.cfi_endproc
.LFE0:
	.size	scale, .-scale
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
