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
	sub	rsp, 32
	mov	dword ptr [rbp - 4], 0
	mov	dword ptr [rbp - 8], edi
	mov	qword ptr [rbp - 16], rsi
	mov	dword ptr [rbp - 20], 3
	mov	dword ptr [rbp - 24], 5
	mov	edi, dword ptr [rbp - 20]
	mov	esi, dword ptr [rbp - 24]
	call	_localVars
	movsd	qword ptr [rbp - 32], xmm0
	xor	eax, eax
	add	rsp, 32
	pop	rbp
	ret
                                        ## -- End function
	.section	__DATA,__data
	.globl	_var0                           ## @var0
	.p2align	2
_var0:
	.long	6                               ## 0x6

.subsections_via_symbols
