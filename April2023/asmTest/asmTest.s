	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.globl	_multiply                       ## -- Begin function multiply
	.p2align	4, 0x90
_multiply:                              ## @multiply
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	imull	-8(%rbp), %eax
	popq	%rbp
	retq
                                        ## -- End function
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2                               ## -- Begin function main
LCPI1_0:
	.long	0x4048f5c3                      ## float 3.1400001
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$9, -8(%rbp)
	jge	LBB1_4
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	cvtsi2ssl	-8(%rbp), %xmm1
	movss	LCPI1_0(%rip), %xmm0            ## xmm0 = mem[0],zero,zero,zero
	mulss	%xmm1, %xmm0
	cvttss2si	%xmm0, %edx
	movslq	-8(%rbp), %rcx
	movq	_array@GOTPCREL(%rip), %rax
	movl	%edx, (%rax,%rcx,4)
## %bb.3:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB1_1
LBB1_4:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
                                        ## -- End function
	.section	__TEXT,__const
	.globl	_PI                             ## @PI
	.p2align	2
_PI:
	.long	0x4048f5c3                      ## float 3.1400001

	.globl	_size                           ## @size
_size:
	.byte	23                              ## 0x17

	.comm	_array,36,4                     ## @array
	.comm	_someInt,4,2                    ## @someInt
	.comm	_x,4,2                          ## @x
	.comm	_y,4,2                          ## @y
	.comm	_z,4,2                          ## @z
	.comm	_someArray,92,4                 ## @someArray
.subsections_via_symbols
