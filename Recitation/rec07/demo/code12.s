	.file	"code1.c"
	.text
	.globl	scale
	.type	scale, @function
scale:
.LFB23:
	.cfi_startproc
	leaq	4(%rdx,%rdx,2), %rdx
	leaq	3(%rdi,%rsi), %rax
	leaq	(%rax,%rdx,4), %rax
	ret
	.cfi_endproc
.LFE23:
	.size	scale, .-scale
	.globl	sum
	.type	sum, @function
sum:
.LFB24:
	.cfi_startproc
	movl	$5, %edx
	movl	$4, %esi
	movl	$3, %edi
	call	scale
	addq	$5, %rax
	ret
	.cfi_endproc
.LFE24:
	.size	sum, .-sum
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
