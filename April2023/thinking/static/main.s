	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.intel_syntax noprefix
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	dword ptr [rbp - 4], 0
	mov	rax, qword ptr [rip + _anotherConstInt@GOTPCREL]
	mov	esi, dword ptr [rax]
	lea	rdi, [rip + L_.str]
	mov	al, 0
	call	_printf
	mov	rax, qword ptr [rip + _someInt@GOTPCREL]
	mov	esi, dword ptr [rax]
	lea	rdi, [rip + L_.str.1]
	mov	al, 0
	call	_printf
	mov	rax, qword ptr [rip + _someExternConstInt@GOTPCREL]
	mov	esi, dword ptr [rax]
	lea	rdi, [rip + L_.str.2]
	mov	al, 0
	call	_printf
	mov	edi, 2345
	call	__Z5func2i
	mov	esi, eax
	lea	rdi, [rip + L_.str]
	mov	al, 0
	call	_printf
	mov	edi, 287
	call	__Z7incFuncs
	movsx	esi, ax
	lea	rdi, [rip + L_.str.3]
	mov	al, 0
	call	_printf
	mov	dword ptr [rbp - 8], 0
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 8], 12
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	xor	edi, edi
	call	__Z7incFuncs
	movsx	esi, ax
	lea	rdi, [rip + L_.str.4]
	mov	al, 0
	call	_printf
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	mov	eax, dword ptr [rbp - 8]
	add	eax, 1
	mov	dword ptr [rbp - 8], eax
	jmp	LBB0_1
LBB0_4:
	xor	eax, eax
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"this is anotherConst %d\n"

L_.str.1:                               ## @.str.1
	.asciz	"this is someInt %d\n"

L_.str.2:                               ## @.str.2
	.asciz	"this is someExternConstInt %d\n"

L_.str.3:                               ## @.str.3
	.asciz	"this is incFunc %d\n"

L_.str.4:                               ## @.str.4
	.asciz	"this is return statement from incFunc %d\n"

.subsections_via_symbols
