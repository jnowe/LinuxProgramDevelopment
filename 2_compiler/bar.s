	.file	"bar.c"
	.section .rdata,"dr"
.LC0:
	.ascii " \12 The >real< Hello World ! \0"
	.text
	.globl	some_func
	.def	some_func;	.scl	2;	.type	32;	.endef
	.seh_proc	some_func
some_func:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	.LC0(%rip), %rcx
	call	puts
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 5.3.0"
	.def	puts;	.scl	2;	.type	32;	.endef
