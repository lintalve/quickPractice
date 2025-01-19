	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.intel_syntax noprefix
	.globl	_localVars                      ## -- Begin function localVars
	.p2align	4, 0x90
_localVars:                             ## @localVars
## %bb.0:
	push	rbp
	mov	rbp, rsp
	imul	edi, edi     # where did the value come from???
	imul	esi, esi     # where did the value come from???
	add	esi, edi
	cvtsi2sd	xmm0, esi
	sqrtsd	xmm0, xmm0
	pop	rbp
	ret          # where does it return???

                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
## %bb.0:
	push	rbp
	mov	rbp, rsp
	xor	eax, eax
	pop	rbp
	ret
                                        ## -- End function
.subsections_via_symbols
