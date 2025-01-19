	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.intel_syntax noprefix
	.globl	_localVars                      ## -- Begin function localVars
	.p2align	4, 0x90
_localVars:                             ## @localVars
## %bb.0:
	push	rbp
	mov	rbp, rsp
	mov	dword ptr [rbp - 4], edi
	mov	dword ptr [rbp - 8], esi
	mov	eax, dword ptr [rbp - 4]
	imul	eax, dword ptr [rbp - 4]
	mov	dword ptr [rbp - 12], eax
	mov	eax, dword ptr [rbp - 8]
	imul	eax, dword ptr [rbp - 8]
	mov	dword ptr [rbp - 16], eax
	mov	eax, dword ptr [rbp - 12]
	add	eax, dword ptr [rbp - 16]
	cvtsi2sd	xmm0, eax
	sqrtsd	xmm0, xmm0
	movsd	qword ptr [rbp - 24], xmm0
	movsd	xmm0, qword ptr [rbp - 24]      ## xmm0 = mem[0],zero
	pop	rbp
	ret
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
## %bb.0:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 144
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	mov	dword ptr [rbp - 52], 0
	mov	dword ptr [rbp - 56], edi
	mov	qword ptr [rbp - 64], rsi
	mov	rax, rsp
	mov	qword ptr [rbp - 72], rax
	mov	dword ptr [rbp - 76], 3
	mov	dword ptr [rbp - 80], 5
	mov	edi, dword ptr [rbp - 76]
	mov	esi, dword ptr [rbp - 80]
	call	_localVars
	movsd	qword ptr [rbp - 88], xmm0
	mov	dword ptr [rbp - 52], 0
	mov	rax, qword ptr [rbp - 72]
	mov	rsp, rax
	mov	eax, dword ptr [rbp - 52]
	mov	dword ptr [rbp - 132], eax      ## 4-byte Spill
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	LBB1_2
## %bb.1:
	mov	eax, dword ptr [rbp - 132]      ## 4-byte Reload
	add	rsp, 144
	pop	rbp
	ret
LBB1_2:
	call	___stack_chk_fail
	ud2
                                        ## -- End function
	.section	__DATA,__data
	.globl	_var0                           ## @var0
	.p2align	2
_var0:
	.long	6                               ## 0x6

	.section	__TEXT,__const
	.globl	_var4                           ## @var4
	.p2align	2
_var4:
	.long	7                               ## 0x7

	.globl	_var5                           ## @var5
	.p2align	2
_var5:
	.long	9                               ## 0x9

.subsections_via_symbols
