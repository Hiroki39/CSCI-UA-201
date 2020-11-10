	.file	"problem1.c"
	.text
	.globl	absdiff
	.type	absdiff, @function
absdiff:
.LFB23:
	.cfi_startproc
	cmpq	%rsi, %rdi
	jg	.L4
	movq	%rsi, %rax
	subq	%rdi, %rax
	ret
.L4:
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
	.cfi_endproc
.LFE23:
	.size	absdiff, .-absdiff
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"dif1: %ld\ndif2: %ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$7, %esi
	movl	$10, %edi
	call	absdiff
	movq	%rax, %rbx
	movl	$10, %esi
	movl	$7, %edi
	call	absdiff
	movq	%rax, %rcx
	movq	%rbx, %rdx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$0, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
