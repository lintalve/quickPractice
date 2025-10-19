	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.intel_syntax noprefix
	.globl	__Z7incCharc                    ## -- Begin function _Z7incCharc
	.p2align	4, 0x90
__Z7incCharc:                           ## @_Z7incCharc
## %bb.0:
	push	rbp
	mov	rbp, rsp
	mov	al, dil
	mov	byte ptr [rbp - 1], al
	mov	al, byte ptr [rbp - 1]
	mov	cl, al
	add	cl, 1
	mov	byte ptr [rbp - 1], cl
	movsx	eax, al
	pop	rbp
	ret
                                        ## -- End function
	.globl	__Z6incInti                     ## -- Begin function _Z6incInti
	.p2align	4, 0x90
__Z6incInti:                            ## @_Z6incInti
## %bb.0:
	push	rbp
	mov	rbp, rsp
	mov	dword ptr [rbp - 4], edi
	mov	eax, dword ptr [rbp - 4]
	mov	ecx, eax
	add	ecx, 1
	mov	dword ptr [rbp - 4], ecx
	pop	rbp
	ret
                                        ## -- End function
	.globl	__Z7incFuncs                    ## -- Begin function _Z7incFuncs
	.p2align	4, 0x90
__Z7incFuncs:                           ## @_Z7incFuncs
## %bb.0:
	push	rbp
	mov	rbp, rsp
	mov	ax, di
	mov	word ptr [rbp - 4], ax
	cmp	word ptr [rbp - 4], 0
	je	LBB2_2
## %bb.1:
	mov	ax, word ptr [rbp - 4]
	mov	word ptr [rip + __ZZ7incFuncsE7stShort], ax
	mov	ax, word ptr [rip + __ZZ7incFuncsE7stShort]
	mov	word ptr [rbp - 2], ax
	jmp	LBB2_3
LBB2_2:
	mov	ax, word ptr [rip + __ZZ7incFuncsE7stShort]
	mov	cx, ax
	add	cx, 1
	mov	word ptr [rip + __ZZ7incFuncsE7stShort], cx
	mov	word ptr [rbp - 2], ax
LBB2_3:
	movsx	eax, word ptr [rbp - 2]
	pop	rbp
	ret
                                        ## -- End function
	.section	__DATA,__data
	.globl	_someInt                        ## @someInt
	.p2align	2
_someInt:
	.long	7654                            ## 0x1de6

.zerofill __DATA,__bss,__ZZ7incFuncsE7stShort,2,1 ## @_ZZ7incFuncsE7stShort
.subsections_via_symbols
