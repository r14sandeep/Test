	.file	"eg5.c"
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$36, %esp
	movl	$5, -16(%ebp)
	movl	$2, -12(%ebp)
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	sarl	$31, %edx
	idivl	-12(%ebp)
	pushl	%eax
	fildl	(%esp)
	leal	4(%esp), %esp
	fstps	-8(%ebp)
	flds	-8(%ebp)
	fstpl	4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	addl	$36, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-48)"
	.section	.note.GNU-stack,"",@progbits
