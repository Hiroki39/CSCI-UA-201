	.text
	.globl _max_char
_max_char:
LFB4:
	movl	%esi, %eax
	cmpb	%sil, %dil
	jle	L2
	movl	%edi, %eax
L2:
	ret
LFE4:
	.globl _max_int
_max_int:
LFB5:
	movsbl	%sil, %eax
	cmpl	%edi, %eax
	jge	L3
	movl	%edi, %eax
L3:
	ret
LFE5:
	.globl _max_long
_max_long:
LFB6:
	movq	%rsi, %rax
	cmpq	%rsi, %rdi
	jle	L6
	movq	%rdi, %rax
L6:
	ret
LFE6:
	.cstring
lC0:
	.ascii "%c\12\0"
lC1:
	.ascii "%d\12\0"
lC2:
	.ascii "%ld\12\0"
	.section __TEXT,__text_startup,regular,pure_instructions
	.globl _main
_main:
LFB7:
	subq	$8, %rsp
LCFI0:
	movl	$65, %esi
	movl	$97, %edi
	call	_max_char
	movsbl	%al, %esi
	leaq	lC0(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	$65, %esi
	movl	$97, %edi
	call	_max_int
	movl	%eax, %esi
	leaq	lC1(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	$65, %esi ; Instructions that Instructions that move or generate 
	movl	$97, %edi ; 32-bit register values also set the upper 32 bits of 
	call	_max_long ; the register to zero.
	movq	%rax, %rsi
	leaq	lC2(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	$0, %eax
	addq	$8, %rsp
LCFI1:
	ret
LFE7:
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
	.align 3
LEFDE3:
LSFDE5:
	.set L$set$5,LEFDE5-LASFDE5
	.long L$set$5
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB6-.
	.set L$set$6,LFE6-LFB6
	.quad L$set$6
	.byte	0
	.align 3
LEFDE5:
LSFDE7:
	.set L$set$7,LEFDE7-LASFDE7
	.long L$set$7
LASFDE7:
	.long	LASFDE7-EH_frame1
	.quad	LFB7-.
	.set L$set$8,LFE7-LFB7
	.quad L$set$8
	.byte	0
	.byte	0x4
	.set L$set$9,LCFI0-LFB7
	.long L$set$9
	.byte	0xe
	.byte	0x10
	.byte	0x4
	.set L$set$10,LCFI1-LCFI0
	.long L$set$10
	.byte	0xe
	.byte	0x8
	.align 3
LEFDE7:
	.ident	"GCC: (Homebrew GCC 10.2.0) 10.2.0"
	.subsections_via_symbols
