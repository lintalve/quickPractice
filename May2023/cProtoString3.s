	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -36(%rbp)
	leaq	L_.str(%rip), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rsi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.2(%rip), %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rsi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	L___const.main.charArray(%rip), %rax
	movq	%rax, -32(%rbp)
	movq	L___const.main.charArray+8(%rip), %rax
	movq	%rax, -24(%rbp)
	movl	L___const.main.charArray+16(%rip), %eax
	movl	%eax, -16(%rbp)
	movb	L___const.main.charArray+20(%rip), %al
	movb	%al, -12(%rbp)
	movl	$0, -60(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movslq	-60(%rbp), %rax
	cmpq	$21, %rax
	jae	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movslq	-60(%rbp), %rax
	movsbl	-32(%rbp,%rax), %esi
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-60(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -60(%rbp)
	jmp	LBB0_1
LBB0_4:
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	-32(%rbp), %rax
	movq	%rax, -72(%rbp)
	movl	$0, -76(%rbp)
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	movq	-72(%rbp), %rax
	movslq	-76(%rbp), %rcx
	movsbl	(%rax,%rcx), %eax
	cmpl	$0, %eax
	je	LBB0_7
## %bb.6:                               ##   in Loop: Header=BB0_5 Depth=1
	movq	-72(%rbp), %rax
	movslq	-76(%rbp), %rcx
	movsbl	(%rax,%rcx), %esi
	leaq	L_.str.5(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-76(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -76(%rbp)
	jmp	LBB0_5
LBB0_7:
	jmp	LBB0_8
LBB0_8:                                 ## =>This Inner Loop Header: Depth=1
	movq	-72(%rbp), %rax
	movsbl	(%rax), %eax
	cmpl	$0, %eax
	je	LBB0_10
## %bb.9:                               ##   in Loop: Header=BB0_8 Depth=1
	movq	-72(%rbp), %rax
	movsbl	(%rax), %esi
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-72(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -72(%rbp)
	jmp	LBB0_8
LBB0_10:
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB0_12
## %bb.11:
	xorl	%eax, %eax
	addq	$80, %rsp
	popq	%rbp
	retq
LBB0_12:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"this is a string"

L_.str.1:                               ## @.str.1
	.asciz	"%s\n"

L_.str.2:                               ## @.str.2
	.asciz	"this is another string"

	.p2align	4                               ## @__const.main.charArray
L___const.main.charArray:
	.asciz	"some undeniable shit"

L_.str.3:                               ## @.str.3
	.asciz	"%c"

L_.str.4:                               ## @.str.4
	.asciz	"\n"

L_.str.5:                               ## @.str.5
	.asciz	"%c\n"

.subsections_via_symbols
