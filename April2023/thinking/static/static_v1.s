	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.intel_syntax noprefix
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90                         ## -- Begin function __cxx_global_var_init
___cxx_global_var_init:                 ## @__cxx_global_var_init
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	lea	rdi, [rip + _ent]
	mov	esi, 4354
	call	__ZN6EntityC1Ei
	mov	rdi, qword ptr [rip + __ZN6EntityD1Ev@GOTPCREL]
	lea	rsi, [rip + _ent]
	lea	rdx, [rip + ___dso_handle]
	call	___cxa_atexit
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN6EntityC1Ei                 ## -- Begin function _ZN6EntityC1Ei
	.weak_def_can_be_hidden	__ZN6EntityC1Ei
	.p2align	4, 0x90
__ZN6EntityC1Ei:                        ## @_ZN6EntityC1Ei
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	dword ptr [rbp - 12], esi
	mov	rdi, qword ptr [rbp - 8]
	mov	esi, dword ptr [rbp - 12]
	call	__ZN6EntityC2Ei
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6EntityD1Ev                 ## -- Begin function _ZN6EntityD1Ev
	.weak_def_can_be_hidden	__ZN6EntityD1Ev
	.p2align	4, 0x90
__ZN6EntityD1Ev:                        ## @_ZN6EntityD1Ev
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	call	__ZN6EntityD2Ev
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__Z5func2i                      ## -- Begin function _Z5func2i
	.p2align	4, 0x90
__Z5func2i:                             ## @_Z5func2i
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	dword ptr [rbp - 4], edi
	mov	eax, dword ptr [rbp - 4]
	mov	dword ptr [rbp - 8], eax
	mov	esi, dword ptr [rbp - 8]
	lea	rdi, [rip + L_.str]
	mov	al, 0
	call	_printf
	mov	eax, dword ptr [rbp - 8]
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6EntityC2Ei                 ## -- Begin function _ZN6EntityC2Ei
	.weak_def_can_be_hidden	__ZN6EntityC2Ei
	.p2align	4, 0x90
__ZN6EntityC2Ei:                        ## @_ZN6EntityC2Ei
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	dword ptr [rbp - 12], esi
	mov	rax, qword ptr [rbp - 8]
	mov	ecx, dword ptr [rbp - 12]
	mov	dword ptr [rax], ecx
	lea	rcx, [rip + L_.str.1]
	mov	qword ptr [rax + 8], rcx
	lea	rdi, [rip + L_.str.2]
	mov	al, 0
	call	_printf
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN6EntityD2Ev                 ## -- Begin function _ZN6EntityD2Ev
	.weak_def_can_be_hidden	__ZN6EntityD2Ev
	.p2align	4, 0x90
__ZN6EntityD2Ev:                        ## @_ZN6EntityD2Ev
## %bb.0:
	push	rbp
	mov	rbp, rsp
	mov	qword ptr [rbp - 8], rdi
	pop	rbp
	ret
                                        ## -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90                         ## -- Begin function _GLOBAL__sub_I_static_v1.cpp
__GLOBAL__sub_I_static_v1.cpp:          ## @_GLOBAL__sub_I_static_v1.cpp
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	call	___cxx_global_var_init
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	_ent                            ## @ent
.zerofill __DATA,__common,_ent,16,3
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"this is the d %d\n"

	.section	__DATA,__data
	.globl	_anotherConstInt                ## @anotherConstInt
	.p2align	2
_anotherConstInt:
	.long	87                              ## 0x57

	.section	__TEXT,__const
	.globl	_someExternConstInt             ## @someExternConstInt
	.p2align	2
_someExternConstInt:
	.long	32523                           ## 0x7f0b

	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	"Entity"

L_.str.2:                               ## @.str.2
	.asciz	"object Entity constructor envoked\n"

	.section	__DATA,__mod_init_func,mod_init_funcs
	.p2align	3
	.quad	__GLOBAL__sub_I_static_v1.cpp
.subsections_via_symbols
