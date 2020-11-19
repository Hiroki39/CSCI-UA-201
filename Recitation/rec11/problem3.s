	.text
	.globl _division
_division:
LFB4:
	jmp	L2
L3:
	subl	%esi, %edi
L2:
	cmpl	%esi, %edi
	jg	L3
	jge	L5
	movl	%edi, %eax
	ret
L5:
	movl	$0, %eax
	ret
LFE4:
	.cstring
lC0:
	.ascii "%d\12\0"
	.section __TEXT,__text_startup,regular,pure_instructions
	.globl _main
_main:
LFB5:
	subq	$8, %rsp
LCFI0:
	movl	$3, %esi
	movl	$17, %edi
	call	_division
	movl	%eax, %esi
	leaq	lC0(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	$7, %esi
	movl	$21, %edi
	call	_division
	movl	%eax, %esi
	leaq	lC0(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	$0, %eax
	addq	$8, %rsp
LCFI1:
	ret
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
	.byte	0x4
	.set L$set$6,LCFI1-LCFI0
	.long L$set$6
	.byte	0xe
	.byte	0x8
	.align 3
LEFDE3:
	.ident	"GCC: (Homebrew GCC 10.2.0) 10.2.0"
	.subsections_via_symbols
