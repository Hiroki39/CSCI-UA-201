	.text
	.globl _sparse_switch_eg
_sparse_switch_eg:
LFB4:
	movq	%rdx, %rcx
	cmpq	$300, %rdi
	je	L8
	jg	L3
	cmpq	$100, %rdi
	je	L4
	cmpq	$200, %rdi
	jne	L10
	movq	%rsi, %rax
	cqto
	idivq	%rcx
L2:
	addq	%rcx, %rax
	jmp	L7
L10:
	movl	$2, %eax
	ret
L3:
	cmpq	$600, %rdi
	jne	L11
	movl	$1, %eax
L7:
	subq	%rcx, %rax
	ret
L11:
	movl	$2, %eax
	ret
L4:
	movq	%rdx, %rax
	imulq	%rsi, %rax
	ret
L8:
	movl	$1, %eax
	jmp	L2
LFE4:
	.cstring
	.align 3
lC0:
	.ascii "x = %ld, y = %ld, z = %ld --> %ld\12\0"
	.section __TEXT,__text_startup,regular,pure_instructions
	.globl _main
_main:
LFB5:
	subq	$8, %rsp
LCFI0:
	movl	$20, %edx
	movl	$10, %esi
	movl	$200, %edi
	call	_sparse_switch_eg
	movq	%rax, %r8
	movl	$20, %ecx
	movl	$10, %edx
	movl	$200, %esi
	leaq	lC0(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	$0, %edi
	call	_exit
LFE5:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB4-.
	.set L$set$2,LFE4-LFB4
	.quad L$set$2
	.byte	0
	.align 3
LEFDE1:
LSFDE3:
	.set L$set$3,LEFDE3-LASFDE3
	.long L$set$3
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB5-.
	.set L$set$4,LFE5-LFB5
	.quad L$set$4
	.byte	0
	.byte	0x4
	.set L$set$5,LCFI0-LFB5
	.long L$set$5
	.byte	0xe
	.byte	0x10
	.align 3
LEFDE3:
	.ident	"GCC: (Homebrew GCC 10.2.0) 10.2.0"
	.subsections_via_symbols
