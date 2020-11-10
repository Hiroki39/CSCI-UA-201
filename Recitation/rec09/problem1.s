	.text
	.globl _absdiff
_absdiff:
LFB1:
	cmpq	%rsi, %rdi ; compare y and x
	jle	L2 ; if y >= x goto L2
	movq	%rdi, %rax ; if y >= x, return y - x
	subq	%rsi, %rax
	ret
L2:
	movq	%rsi, %rax ; else return x - y
	subq	%rdi, %rax
	ret
LFE1:
	.cstring
lC0:
	.ascii "dif1: %ld\12dif2: %ld\12\0"
	.section __TEXT,__text_startup,regular,pure_instructions
	.globl _main
_main:
LFB2:
	pushq	%rbx
LCFI0:
	movl	$7, %esi
	movl	$10, %edi
	call	_absdiff
	movq	%rax, %rbx
	movl	$10, %esi
	movl	$7, %edi
	call	_absdiff
	movq	%rax, %rdx
	movq	%rbx, %rsi
	leaq	lC0(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	$0, %eax
	popq	%rbx
LCFI1:
	ret
LFE2:
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
	.ident	"GCC: (Homebrew GCC 10.2.0) 10.2.0"
	.subsections_via_symbols
