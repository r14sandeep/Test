	.file	"binary_file.c"
	.section	.rodata
.LC0:
	.string	"rb"
.LC1:
	.string	"a.out"
.LC2:
	.string	"%c\n"
.LC3:
	.string	"\n%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, -16(%rbp)
	movl	$0, -12(%rbp)
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	fopen
	movq	%rax, -8(%rbp)
	jmp	.L2
.L4:
	movsbl	-17(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	cmpb	$49, -17(%rbp)
	jne	.L3
	addl	$1, -16(%rbp)
	movsbl	-17(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L2
.L3:
	addl	$1, -12(%rbp)
.L2:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fgetc
	movb	%al, -17(%rbp)
	cmpb	$-1, -17(%rbp)
	jne	.L4
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
