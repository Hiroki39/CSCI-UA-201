	.text
	.globl _mult2
_mult2:
LFB1:
	movq	%rdi, %rax
	imulq	%rsi, %rax
	ret
LFE1:
	.globl _multstore
_multstore:
LFB2:
	pushq	%rbx
LCFI0:
	movq	%rdx, %rbx
	call	_mult2
	movq	%rax, (%rbx)
	popq	%rbx
LCFI1:
	ret
LFE2:
	.cstring
lC0:
	.ascii "2, 3 --> %ld\12\0"
	.section __TEXT,__text_startup,regular,pure_instructions
	.globl _main
_main:
LFB3:
	subq	$24, %rsp
LCFI2:
	leaq	8(%rsp), %rdx
	movl	$3, %esi
	movl	$2, %edi
	call	_multstore
	movq	8(%rsp), %rsi
	leaq	lC0(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	$0, %eax
	addq	$24, %rsp
LCFI3:
	ret
LFE3:
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
	.quad	LFB1-.
	.set L$set$2,LFE1-LFB1
	.quad L$set$2
	.byte	0
	.align 3
LEFDE1:
LSFDE3:
	.set L$set$3,LEFDE3-LASFDE3
	.long L$set$3
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB2-.
	.set L$set$4,LFE2-LFB2
	.quad L$set$4
	.byte	0
	.byte	0x4
	.set L$set$5,LCFI0-LFB2
	.long L$set$5
	.byte	0xe
	.byte	0x10
	.byte	0x83
	.byte	0x2
	.byte	0x4
	.set L$set$6,LCFI1-LCFI0
	.long L$set$6
	.byte	0xe
	.byte	0x8
	.align 3
LEFDE3:
LSFDE5:
	.set L$set$7,LEFDE5-LASFDE5
	.long L$set$7
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB3-.
	.set L$set$8,LFE3-LFB3
	.quad L$set$8
	.byte	0
	.byte	0x4
	.set L$set$9,LCFI2-LFB3
	.long L$set$9
	.byte	0xe
	.byte	0x20
	.byte	0x4
	.set L$set$10,LCFI3-LCFI2
	.long L$set$10
	.byte	0xe
	.byte	0x8
	.align 3
LEFDE5:
	.ident	"GCC: (Homebrew GCC 10.2.0) 10.2.0"
	.subsections_via_symbols
