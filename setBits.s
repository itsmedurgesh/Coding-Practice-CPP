	.file	"setBits.cpp"
	.intel_syntax noprefix
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZNSt12_Base_bitsetILm1EEC2Ey,"axG",@progbits,_ZNSt12_Base_bitsetILm1EEC5Ey,comdat
	.align 2
	.weak	_ZNSt12_Base_bitsetILm1EEC2Ey
	.type	_ZNSt12_Base_bitsetILm1EEC2Ey, @function
_ZNSt12_Base_bitsetILm1EEC2Ey:
.LFB1414:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdx, QWORD PTR [rbp-16]
	mov	QWORD PTR [rax], rdx
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1414:
	.size	_ZNSt12_Base_bitsetILm1EEC2Ey, .-_ZNSt12_Base_bitsetILm1EEC2Ey
	.weak	_ZNSt12_Base_bitsetILm1EEC1Ey
	.set	_ZNSt12_Base_bitsetILm1EEC1Ey,_ZNSt12_Base_bitsetILm1EEC2Ey
	.globl	__popcountdi2
	.section	.text._ZNKSt12_Base_bitsetILm1EE11_M_do_countEv,"axG",@progbits,_ZNKSt12_Base_bitsetILm1EE11_M_do_countEv,comdat
	.align 2
	.weak	_ZNKSt12_Base_bitsetILm1EE11_M_do_countEv
	.type	_ZNKSt12_Base_bitsetILm1EE11_M_do_countEv, @function
_ZNKSt12_Base_bitsetILm1EE11_M_do_countEv:
.LFB1436:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rax, QWORD PTR [rax]
	mov	rdi, rax
	call	__popcountdi2
	cdqe
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1436:
	.size	_ZNKSt12_Base_bitsetILm1EE11_M_do_countEv, .-_ZNKSt12_Base_bitsetILm1EE11_M_do_countEv
	.text
	.globl	_Z15NumberOfSetBitsj
	.type	_Z15NumberOfSetBitsj, @function
_Z15NumberOfSetBitsj:
.LFB1543:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-4], edi
	mov	eax, DWORD PTR [rbp-4]
	shr	eax
	and	eax, 1431655765
	sub	DWORD PTR [rbp-4], eax
	mov	eax, DWORD PTR [rbp-4]
	and	eax, 858993459
	mov	edx, eax
	mov	eax, DWORD PTR [rbp-4]
	shr	eax, 2
	and	eax, 858993459
	add	eax, edx
	mov	DWORD PTR [rbp-4], eax
	mov	eax, DWORD PTR [rbp-4]
	shr	eax, 4
	mov	edx, eax
	mov	eax, DWORD PTR [rbp-4]
	add	eax, edx
	and	eax, 252645135
	imul	eax, eax, 16843009
	shr	eax, 24
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1543:
	.size	_Z15NumberOfSetBitsj, .-_Z15NumberOfSetBitsj
	.section	.text._ZNSt13_Sanitize_valILm32ELb1EE18_S_do_sanitize_valEy,"axG",@progbits,_ZNSt13_Sanitize_valILm32ELb1EE18_S_do_sanitize_valEy,comdat
	.weak	_ZNSt13_Sanitize_valILm32ELb1EE18_S_do_sanitize_valEy
	.type	_ZNSt13_Sanitize_valILm32ELb1EE18_S_do_sanitize_valEy, @function
_ZNSt13_Sanitize_valILm32ELb1EE18_S_do_sanitize_valEy:
.LFB1546:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	eax, eax
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1546:
	.size	_ZNSt13_Sanitize_valILm32ELb1EE18_S_do_sanitize_valEy, .-_ZNSt13_Sanitize_valILm32ELb1EE18_S_do_sanitize_valEy
	.section	.text._ZNSt6bitsetILm32EEC1Ey,"axG",@progbits,_ZNSt6bitsetILm32EEC1Ey,comdat
	.align 2
	.weak	_ZNSt6bitsetILm32EEC1Ey
	.type	_ZNSt6bitsetILm32EEC1Ey, @function
_ZNSt6bitsetILm32EEC1Ey:
.LFB1548:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	rax, QWORD PTR [rbp-16]
	mov	rdi, rax
	call	_ZNSt13_Sanitize_valILm32ELb1EE18_S_do_sanitize_valEy
	mov	rdx, rax
	mov	rax, QWORD PTR [rbp-8]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNSt12_Base_bitsetILm1EEC2Ey
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1548:
	.size	_ZNSt6bitsetILm32EEC1Ey, .-_ZNSt6bitsetILm32EEC1Ey
	.text
	.globl	main
	.type	main, @function
main:
.LFB1544:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR [rbp-8], rax
	xor	eax, eax
	mov	edi, 28
	call	_Z15NumberOfSetBitsj
	mov	esi, eax
	mov	edi, OFFSET FLAT:_ZSt4cout
	call	_ZNSolsEi
	mov	esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	mov	esi, 3
	mov	edi, OFFSET FLAT:_ZSt4cout
	call	_ZNSolsEi
	mov	esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	lea	rax, [rbp-16]
	mov	esi, 28
	mov	rdi, rax
	call	_ZNSt6bitsetILm32EEC1Ey
	lea	rax, [rbp-16]
	mov	rdi, rax
	call	_ZNKSt6bitsetILm32EE5countEv
	mov	rsi, rax
	mov	edi, OFFSET FLAT:_ZSt4cout
	call	_ZNSolsEm
	mov	esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	mov	eax, 0
	mov	rdx, QWORD PTR [rbp-8]
	xor	rdx, QWORD PTR fs:40
	je	.L11
	call	__stack_chk_fail
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1544:
	.size	main, .-main
	.section	.text._ZNKSt6bitsetILm32EE5countEv,"axG",@progbits,_ZNKSt6bitsetILm32EE5countEv,comdat
	.align 2
	.weak	_ZNKSt6bitsetILm32EE5countEv
	.type	_ZNKSt6bitsetILm32EE5countEv, @function
_ZNKSt6bitsetILm32EE5countEv:
.LFB1608:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZNKSt12_Base_bitsetILm1EE11_M_do_countEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1608:
	.size	_ZNKSt6bitsetILm32EE5countEv, .-_ZNKSt6bitsetILm32EE5countEv
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1736:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	DWORD PTR [rbp-4], edi
	mov	DWORD PTR [rbp-8], esi
	cmp	DWORD PTR [rbp-4], 1
	jne	.L16
	cmp	DWORD PTR [rbp-8], 65535
	jne	.L16
	mov	edi, OFFSET FLAT:_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	edx, OFFSET FLAT:__dso_handle
	mov	esi, OFFSET FLAT:_ZStL8__ioinit
	mov	edi, OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
	call	__cxa_atexit
.L16:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1736:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z15NumberOfSetBitsj, @function
_GLOBAL__sub_I__Z15NumberOfSetBitsj:
.LFB1737:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	esi, 65535
	mov	edi, 1
	call	_Z41__static_initialization_and_destruction_0ii
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1737:
	.size	_GLOBAL__sub_I__Z15NumberOfSetBitsj, .-_GLOBAL__sub_I__Z15NumberOfSetBitsj
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z15NumberOfSetBitsj
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2.1) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
