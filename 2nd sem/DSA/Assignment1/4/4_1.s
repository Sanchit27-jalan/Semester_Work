	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 0
	.globl	_transpose                      ; -- Begin function transpose
	.p2align	2
_transpose:                             ; @transpose
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #112
	stp	x29, x30, [sp, #96]             ; 16-byte Folded Spill
	add	x29, sp, #96
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	ldur	x8, [x29, #-8]
	ldr	x8, [x8, #16]
	stur	x8, [x29, #-24]
	mov	x0, #24
	bl	_malloc
	stur	x0, [x29, #-32]
	ldur	x9, [x29, #-32]
	mov	w8, #-1
	str	w8, [x9, #4]
	ldur	x9, [x29, #-32]
	str	w8, [x9]
	ldur	x8, [x29, #-32]
	str	wzr, [x8, #8]
	ldur	x8, [x29, #-32]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #16]
	stur	wzr, [x29, #-36]
	b	LBB0_1
LBB0_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB0_3 Depth 2
                                        ;     Child Loop BB0_10 Depth 2
                                        ;     Child Loop BB0_22 Depth 2
                                        ;     Child Loop BB0_31 Depth 2
	ldur	w8, [x29, #-36]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	b.ge	LBB0_37
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldur	x8, [x29, #-32]
	str	x8, [sp, #48]
	ldur	x8, [x29, #-32]
	str	x8, [sp, #40]
	ldur	x8, [x29, #-24]
	ldr	w8, [x8, #4]
	str	w8, [sp, #36]
	str	wzr, [sp, #32]
	b	LBB0_3
LBB0_3:                                 ;   Parent Loop BB0_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x8, [sp, #48]
	ldr	x8, [x8, #16]
	cbz	x8, LBB0_27
	b	LBB0_4
LBB0_4:                                 ;   in Loop: Header=BB0_3 Depth=2
	ldr	x8, [sp, #48]
	ldr	w8, [x8]
	ldr	w9, [sp, #36]
	subs	w8, w8, w9
	b.ge	LBB0_6
	b	LBB0_5
LBB0_5:                                 ;   in Loop: Header=BB0_3 Depth=2
	ldr	x8, [sp, #48]
	ldr	x8, [x8, #16]
	str	x8, [sp, #48]
	b	LBB0_6
LBB0_6:                                 ;   in Loop: Header=BB0_3 Depth=2
	ldr	x8, [sp, #48]
	ldr	w8, [x8]
	ldr	w9, [sp, #36]
	subs	w8, w8, w9
	b.le	LBB0_8
	b	LBB0_7
LBB0_7:                                 ;   in Loop: Header=BB0_1 Depth=1
	mov	w8, #1
	str	w8, [sp, #32]
	b	LBB0_27
LBB0_8:                                 ;   in Loop: Header=BB0_3 Depth=2
	ldr	x8, [sp, #48]
	ldr	w8, [x8]
	ldr	w9, [sp, #36]
	subs	w8, w8, w9
	b.ne	LBB0_26
	b	LBB0_9
LBB0_9:                                 ;   in Loop: Header=BB0_1 Depth=1
	mov	x0, #24
	bl	_malloc
	str	x0, [sp, #24]
	ldur	x8, [x29, #-24]
	ldr	w8, [x8]
	ldr	x9, [sp, #24]
	str	w8, [x9, #4]
	ldur	x8, [x29, #-24]
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #24]
	str	w8, [x9]
	ldur	x8, [x29, #-24]
	ldr	w8, [x8, #8]
	ldr	x9, [sp, #24]
	str	w8, [x9, #8]
	ldur	x8, [x29, #-24]
	ldr	w8, [x8]
	str	w8, [sp, #20]
	str	wzr, [sp, #16]
	b	LBB0_10
LBB0_10:                                ;   Parent Loop BB0_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x8, [sp, #48]
	ldr	x8, [x8, #16]
	cbz	x8, LBB0_18
	b	LBB0_11
LBB0_11:                                ;   in Loop: Header=BB0_10 Depth=2
	ldr	x8, [sp, #48]
	ldr	w8, [x8, #4]
	ldr	w9, [sp, #20]
	subs	w8, w8, w9
	b.ge	LBB0_13
	b	LBB0_12
LBB0_12:                                ;   in Loop: Header=BB0_10 Depth=2
	ldr	x8, [sp, #48]
	ldr	x8, [x8, #16]
	str	x8, [sp, #48]
	b	LBB0_13
LBB0_13:                                ;   in Loop: Header=BB0_10 Depth=2
	ldr	x8, [sp, #48]
	ldr	w8, [x8, #4]
	ldr	w9, [sp, #20]
	subs	w8, w8, w9
	b.le	LBB0_15
	b	LBB0_14
LBB0_14:                                ;   in Loop: Header=BB0_1 Depth=1
	mov	w8, #1
	str	w8, [sp, #16]
	b	LBB0_18
LBB0_15:                                ;   in Loop: Header=BB0_10 Depth=2
	ldr	x8, [sp, #48]
	ldr	w8, [x8]
	ldr	w9, [sp, #36]
	subs	w8, w8, w9
	b.eq	LBB0_17
	b	LBB0_16
LBB0_16:                                ;   in Loop: Header=BB0_1 Depth=1
	mov	w8, #1
	str	w8, [sp, #16]
	b	LBB0_18
LBB0_17:                                ;   in Loop: Header=BB0_10 Depth=2
	b	LBB0_10
LBB0_18:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #16]
	cbnz	w8, LBB0_20
	b	LBB0_19
LBB0_19:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	x8, [sp, #24]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #16]
	ldr	x8, [sp, #24]
	ldr	x9, [sp, #48]
	str	x8, [x9, #16]
	b	LBB0_20
LBB0_20:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #16]
	subs	w8, w8, #1
	b.ne	LBB0_25
	b	LBB0_21
LBB0_21:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	x8, [sp, #48]
	ldr	x9, [sp, #24]
	str	x8, [x9, #16]
	b	LBB0_22
LBB0_22:                                ;   Parent Loop BB0_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x8, [sp, #40]
	ldr	x8, [x8, #16]
	ldr	x9, [sp, #48]
	subs	x8, x8, x9
	b.eq	LBB0_24
	b	LBB0_23
LBB0_23:                                ;   in Loop: Header=BB0_22 Depth=2
	ldr	x8, [sp, #40]
	ldr	x8, [x8, #16]
	str	x8, [sp, #40]
	b	LBB0_22
LBB0_24:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	x9, [sp, #40]
	str	x8, [x9, #16]
	b	LBB0_25
LBB0_25:                                ;   in Loop: Header=BB0_1 Depth=1
	mov	w8, #2
	str	w8, [sp, #32]
	b	LBB0_27
LBB0_26:                                ;   in Loop: Header=BB0_3 Depth=2
	b	LBB0_3
LBB0_27:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #32]
	cbnz	w8, LBB0_29
	b	LBB0_28
LBB0_28:                                ;   in Loop: Header=BB0_1 Depth=1
	mov	x0, #24
	bl	_malloc
	str	x0, [sp, #8]
	ldur	x8, [x29, #-24]
	ldr	w8, [x8]
	ldr	x9, [sp, #8]
	str	w8, [x9, #4]
	ldur	x8, [x29, #-24]
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #8]
	str	w8, [x9]
	ldur	x8, [x29, #-24]
	ldr	w8, [x8, #8]
	ldr	x9, [sp, #8]
	str	w8, [x9, #8]
	ldr	x8, [sp, #8]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #16]
	ldr	x8, [sp, #8]
	ldr	x9, [sp, #48]
	str	x8, [x9, #16]
	b	LBB0_35
LBB0_29:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #32]
	subs	w8, w8, #1
	b.ne	LBB0_34
	b	LBB0_30
LBB0_30:                                ;   in Loop: Header=BB0_1 Depth=1
	mov	x0, #24
	bl	_malloc
	str	x0, [sp]
	ldur	x8, [x29, #-24]
	ldr	w8, [x8]
	ldr	x9, [sp]
	str	w8, [x9, #4]
	ldur	x8, [x29, #-24]
	ldr	w8, [x8, #4]
	ldr	x9, [sp]
	str	w8, [x9]
	ldur	x8, [x29, #-24]
	ldr	w8, [x8, #8]
	ldr	x9, [sp]
	str	w8, [x9, #8]
	ldr	x8, [sp, #48]
	ldr	x9, [sp]
	str	x8, [x9, #16]
	b	LBB0_31
LBB0_31:                                ;   Parent Loop BB0_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x8, [sp, #40]
	ldr	x8, [x8, #16]
	ldr	x9, [sp, #48]
	subs	x8, x8, x9
	b.eq	LBB0_33
	b	LBB0_32
LBB0_32:                                ;   in Loop: Header=BB0_31 Depth=2
	ldr	x8, [sp, #40]
	ldr	x8, [x8, #16]
	str	x8, [sp, #40]
	b	LBB0_31
LBB0_33:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	x8, [sp]
	ldr	x9, [sp, #40]
	str	x8, [x9, #16]
	b	LBB0_34
LBB0_34:                                ;   in Loop: Header=BB0_1 Depth=1
	b	LBB0_35
LBB0_35:                                ;   in Loop: Header=BB0_1 Depth=1
	ldur	x8, [x29, #-24]
	ldr	x8, [x8, #16]
	stur	x8, [x29, #-24]
	b	LBB0_36
LBB0_36:                                ;   in Loop: Header=BB0_1 Depth=1
	ldur	w8, [x29, #-36]
	add	w8, w8, #1
	stur	w8, [x29, #-36]
	b	LBB0_1
LBB0_37:
	ldur	x0, [x29, #-32]
	ldp	x29, x30, [sp, #96]             ; 16-byte Folded Reload
	add	sp, sp, #112
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_add                            ; -- Begin function add
	.p2align	2
_add:                                   ; @add
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	.cfi_def_cfa_offset 64
	str	x0, [sp, #56]
	str	x1, [sp, #48]
	ldr	x8, [sp, #56]
	ldr	x8, [x8, #16]
	str	x8, [sp, #40]
	ldr	x8, [sp, #48]
	ldr	x8, [x8, #16]
	str	x8, [sp, #32]
	ldr	x8, [sp, #56]
	ldr	x8, [x8, #16]
	str	x8, [sp, #24]
	ldr	x8, [sp, #48]
	ldr	x8, [x8, #16]
	str	x8, [sp, #16]
	str	wzr, [sp, #12]
	b	LBB1_1
LBB1_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB1_30 Depth 2
                                        ;     Child Loop BB1_36 Depth 2
	ldr	x8, [sp, #24]
	cbz	x8, LBB1_24
	b	LBB1_2
LBB1_2:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #16]
	cbz	x8, LBB1_24
	b	LBB1_3
LBB1_3:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #16]
	ldr	w9, [x9, #4]
	subs	w8, w8, w9
	b.ne	LBB1_9
	b	LBB1_4
LBB1_4:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	w8, [x8]
	ldr	x9, [sp, #16]
	ldr	w9, [x9]
	subs	w8, w8, w9
	b.ne	LBB1_9
	b	LBB1_5
LBB1_5:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	w8, [x8, #8]
	ldr	x9, [sp, #16]
	ldr	w9, [x9, #8]
	add	w8, w8, w9
	str	w8, [sp, #8]
	ldr	w8, [sp, #8]
	cbz	w8, LBB1_7
	b	LBB1_6
LBB1_6:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #16]
	str	x8, [sp, #24]
	ldr	x8, [sp, #16]
	ldr	x8, [x8, #16]
	str	x8, [sp, #16]
	b	LBB1_8
LBB1_7:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #16]
	str	x8, [sp, #24]
	ldr	x8, [sp, #16]
	ldr	x8, [x8, #16]
	str	x8, [sp, #16]
	b	LBB1_8
LBB1_8:                                 ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_23
LBB1_9:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	w8, [x8]
	ldr	x9, [sp, #16]
	ldr	w9, [x9]
	subs	w8, w8, w9
	b.ne	LBB1_12
	b	LBB1_10
LBB1_10:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #16]
	ldr	w9, [x9, #4]
	subs	w8, w8, w9
	b.le	LBB1_12
	b	LBB1_11
LBB1_11:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #16]
	ldr	x8, [x8, #16]
	str	x8, [sp, #16]
	b	LBB1_22
LBB1_12:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	w8, [x8]
	ldr	x9, [sp, #16]
	ldr	w9, [x9]
	subs	w8, w8, w9
	b.ne	LBB1_15
	b	LBB1_13
LBB1_13:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #16]
	ldr	w9, [x9, #4]
	subs	w8, w8, w9
	b.ge	LBB1_15
	b	LBB1_14
LBB1_14:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #16]
	str	x8, [sp, #24]
	b	LBB1_21
LBB1_15:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	w8, [x8]
	ldr	x9, [sp, #16]
	ldr	w9, [x9]
	subs	w8, w8, w9
	b.le	LBB1_17
	b	LBB1_16
LBB1_16:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #16]
	ldr	x8, [x8, #16]
	str	x8, [sp, #16]
	b	LBB1_20
LBB1_17:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	w8, [x8]
	ldr	x9, [sp, #16]
	ldr	w9, [x9]
	subs	w8, w8, w9
	b.ge	LBB1_19
	b	LBB1_18
LBB1_18:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #16]
	str	x8, [sp, #24]
	b	LBB1_19
LBB1_19:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_20
LBB1_20:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_21
LBB1_21:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_22
LBB1_22:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_23
LBB1_23:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_24
LBB1_24:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	cbnz	x8, LBB1_27
	b	LBB1_25
LBB1_25:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #16]
	cbnz	x8, LBB1_27
	b	LBB1_26
LBB1_26:
	b	LBB1_40
LBB1_27:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	cbnz	x8, LBB1_33
	b	LBB1_28
LBB1_28:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #16]
	cbz	x8, LBB1_33
	b	LBB1_29
LBB1_29:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_30
LBB1_30:                                ;   Parent Loop BB1_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x8, [sp, #16]
	cbz	x8, LBB1_32
	b	LBB1_31
LBB1_31:                                ;   in Loop: Header=BB1_30 Depth=2
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #16]
	ldr	x8, [x8, #16]
	str	x8, [sp, #16]
	b	LBB1_30
LBB1_32:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_33
LBB1_33:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #24]
	cbz	x8, LBB1_39
	b	LBB1_34
LBB1_34:                                ;   in Loop: Header=BB1_1 Depth=1
	ldr	x8, [sp, #16]
	cbnz	x8, LBB1_39
	b	LBB1_35
LBB1_35:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_36
LBB1_36:                                ;   Parent Loop BB1_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x8, [sp, #24]
	cbz	x8, LBB1_38
	b	LBB1_37
LBB1_37:                                ;   in Loop: Header=BB1_36 Depth=2
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #16]
	str	x8, [sp, #24]
	b	LBB1_36
LBB1_38:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_39
LBB1_39:                                ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_1
LBB1_40:
	b	LBB1_41
LBB1_41:                                ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB1_70 Depth 2
                                        ;     Child Loop BB1_76 Depth 2
	ldr	x8, [sp, #40]
	cbz	x8, LBB1_64
	b	LBB1_42
LBB1_42:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #32]
	cbz	x8, LBB1_64
	b	LBB1_43
LBB1_43:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #32]
	ldr	w9, [x9, #4]
	subs	w8, w8, w9
	b.ne	LBB1_49
	b	LBB1_44
LBB1_44:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	ldr	w8, [x8]
	ldr	x9, [sp, #32]
	ldr	w9, [x9]
	subs	w8, w8, w9
	b.ne	LBB1_49
	b	LBB1_45
LBB1_45:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	ldr	w8, [x8, #8]
	ldr	x9, [sp, #32]
	ldr	w9, [x9, #8]
	add	w8, w8, w9
	str	w8, [sp, #4]
	ldr	w8, [sp, #4]
	cbz	w8, LBB1_47
	b	LBB1_46
LBB1_46:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #40]
	ldr	x8, [x8, #16]
	str	x8, [sp, #40]
	ldr	x8, [sp, #32]
	ldr	x8, [x8, #16]
	str	x8, [sp, #32]
	b	LBB1_48
LBB1_47:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	ldr	x8, [x8, #16]
	str	x8, [sp, #40]
	ldr	x8, [sp, #32]
	ldr	x8, [x8, #16]
	str	x8, [sp, #32]
	b	LBB1_48
LBB1_48:                                ;   in Loop: Header=BB1_41 Depth=1
	b	LBB1_63
LBB1_49:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	ldr	w8, [x8]
	ldr	x9, [sp, #32]
	ldr	w9, [x9]
	subs	w8, w8, w9
	b.ne	LBB1_52
	b	LBB1_50
LBB1_50:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #32]
	ldr	w9, [x9, #4]
	subs	w8, w8, w9
	b.le	LBB1_52
	b	LBB1_51
LBB1_51:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #32]
	ldr	x8, [x8, #16]
	str	x8, [sp, #32]
	b	LBB1_62
LBB1_52:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	ldr	w8, [x8]
	ldr	x9, [sp, #32]
	ldr	w9, [x9]
	subs	w8, w8, w9
	b.ne	LBB1_55
	b	LBB1_53
LBB1_53:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #32]
	ldr	w9, [x9, #4]
	subs	w8, w8, w9
	b.ge	LBB1_55
	b	LBB1_54
LBB1_54:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #40]
	ldr	x8, [x8, #16]
	str	x8, [sp, #40]
	b	LBB1_61
LBB1_55:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	ldr	w8, [x8]
	ldr	x9, [sp, #32]
	ldr	w9, [x9]
	subs	w8, w8, w9
	b.le	LBB1_57
	b	LBB1_56
LBB1_56:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #32]
	ldr	x8, [x8, #16]
	str	x8, [sp, #32]
	b	LBB1_60
LBB1_57:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	ldr	w8, [x8]
	ldr	x9, [sp, #32]
	ldr	w9, [x9]
	subs	w8, w8, w9
	b.ge	LBB1_59
	b	LBB1_58
LBB1_58:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #40]
	ldr	x8, [x8, #16]
	str	x8, [sp, #40]
	b	LBB1_59
LBB1_59:                                ;   in Loop: Header=BB1_41 Depth=1
	b	LBB1_60
LBB1_60:                                ;   in Loop: Header=BB1_41 Depth=1
	b	LBB1_61
LBB1_61:                                ;   in Loop: Header=BB1_41 Depth=1
	b	LBB1_62
LBB1_62:                                ;   in Loop: Header=BB1_41 Depth=1
	b	LBB1_63
LBB1_63:                                ;   in Loop: Header=BB1_41 Depth=1
	b	LBB1_64
LBB1_64:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	cbnz	x8, LBB1_67
	b	LBB1_65
LBB1_65:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #32]
	cbnz	x8, LBB1_67
	b	LBB1_66
LBB1_66:
	b	LBB1_80
LBB1_67:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	cbnz	x8, LBB1_73
	b	LBB1_68
LBB1_68:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #32]
	cbz	x8, LBB1_73
	b	LBB1_69
LBB1_69:                                ;   in Loop: Header=BB1_41 Depth=1
	b	LBB1_70
LBB1_70:                                ;   Parent Loop BB1_41 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x8, [sp, #32]
	cbz	x8, LBB1_72
	b	LBB1_71
LBB1_71:                                ;   in Loop: Header=BB1_70 Depth=2
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #32]
	ldr	x8, [x8, #16]
	str	x8, [sp, #32]
	b	LBB1_70
LBB1_72:                                ;   in Loop: Header=BB1_41 Depth=1
	b	LBB1_73
LBB1_73:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #40]
	cbz	x8, LBB1_79
	b	LBB1_74
LBB1_74:                                ;   in Loop: Header=BB1_41 Depth=1
	ldr	x8, [sp, #32]
	cbnz	x8, LBB1_79
	b	LBB1_75
LBB1_75:                                ;   in Loop: Header=BB1_41 Depth=1
	b	LBB1_76
LBB1_76:                                ;   Parent Loop BB1_41 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x8, [sp, #40]
	cbz	x8, LBB1_78
	b	LBB1_77
LBB1_77:                                ;   in Loop: Header=BB1_76 Depth=2
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	x8, [sp, #40]
	ldr	x8, [x8, #16]
	str	x8, [sp, #40]
	b	LBB1_76
LBB1_78:                                ;   in Loop: Header=BB1_41 Depth=1
	b	LBB1_79
LBB1_79:                                ;   in Loop: Header=BB1_41 Depth=1
	b	LBB1_41
LBB1_80:
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_insert                         ; -- Begin function insert
	.p2align	2
_insert:                                ; @insert
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	str	x0, [sp, #32]
	str	w1, [sp, #28]
	str	w2, [sp, #24]
	str	w3, [sp, #20]
	str	w4, [sp, #16]
	str	wzr, [sp, #12]
	b	LBB2_1
LBB2_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #16]
	subs	w8, w8, w9
	b.ge	LBB2_7
	b	LBB2_2
LBB2_2:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mov	x10, #12
	mul	x9, x9, x10
	ldr	w8, [x8, x9]
	ldr	w9, [sp, #28]
	subs	w8, w8, w9
	b.ne	LBB2_5
	b	LBB2_3
LBB2_3:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mov	x10, #12
	mul	x9, x9, x10
	add	x8, x8, x9
	ldr	w8, [x8, #4]
	ldr	w9, [sp, #24]
	subs	w8, w8, w9
	b.ne	LBB2_5
	b	LBB2_4
LBB2_4:
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mov	x11, #12
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #8]
	ldr	w9, [sp, #20]
	add	w8, w8, w9
	ldr	x9, [sp, #32]
	ldrsw	x10, [sp, #12]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #8]
	ldr	w8, [sp, #16]
	str	w8, [sp, #44]
	b	LBB2_8
LBB2_5:                                 ;   in Loop: Header=BB2_1 Depth=1
	b	LBB2_6
LBB2_6:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB2_1
LBB2_7:
	ldr	w8, [sp, #28]
	ldr	x9, [sp, #32]
	ldrsw	x10, [sp, #16]
	mov	x11, #12
	mul	x10, x10, x11
	str	w8, [x9, x10]
	ldr	w8, [sp, #24]
	ldr	x9, [sp, #32]
	ldrsw	x10, [sp, #16]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #4]
	ldr	w8, [sp, #20]
	ldr	x9, [sp, #32]
	ldrsw	x10, [sp, #16]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #8]
	ldr	w8, [sp, #16]
	add	w8, w8, #1
	str	w8, [sp, #44]
	b	LBB2_8
LBB2_8:
	ldr	w0, [sp, #44]
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_merge                          ; -- Begin function merge
	.p2align	2
_merge:                                 ; @merge
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	str	x0, [sp, #40]
	str	x1, [sp, #32]
	str	x2, [sp, #24]
	str	w3, [sp, #20]
	str	w4, [sp, #16]
	str	wzr, [sp, #12]
	str	wzr, [sp, #8]
	str	wzr, [sp, #4]
	b	LBB3_1
LBB3_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w9, [sp, #12]
	ldr	w10, [sp, #20]
	mov	w8, #0
	subs	w9, w9, w10
	str	w8, [sp]                        ; 4-byte Folded Spill
	b.ge	LBB3_3
	b	LBB3_2
LBB3_2:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	w8, [sp, #8]
	ldr	w9, [sp, #16]
	subs	w8, w8, w9
	cset	w8, lt
	str	w8, [sp]                        ; 4-byte Folded Spill
	b	LBB3_3
LBB3_3:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	w8, [sp]                        ; 4-byte Folded Reload
	tbz	w8, #0, LBB3_15
	b	LBB3_4
LBB3_4:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mov	x11, #12
	mul	x9, x9, x11
	ldr	w8, [x8, x9]
	ldr	x9, [sp, #24]
	ldrsw	x10, [sp, #12]
	mul	x10, x10, x11
	ldr	w9, [x9, x10]
	subs	w8, w8, w9
	b.ge	LBB3_6
	b	LBB3_5
LBB3_5:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mov	x11, #12
	mul	x9, x9, x11
	ldr	w8, [x8, x9]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	str	w8, [x9, x10]
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #4]
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #8]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #8]
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB3_14
LBB3_6:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mov	x11, #12
	mul	x9, x9, x11
	ldr	w8, [x8, x9]
	ldr	x9, [sp, #24]
	ldrsw	x10, [sp, #8]
	mul	x10, x10, x11
	ldr	w9, [x9, x10]
	subs	w8, w8, w9
	b.le	LBB3_8
	b	LBB3_7
LBB3_7:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #8]
	mov	x11, #12
	mul	x9, x9, x11
	ldr	w8, [x8, x9]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	str	w8, [x9, x10]
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #8]
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #4]
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #8]
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #8]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #8]
	ldr	w8, [sp, #8]
	add	w8, w8, #1
	str	w8, [sp, #8]
	b	LBB3_13
LBB3_8:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mov	x11, #12
	mul	x9, x9, x11
	ldr	w8, [x8, x9]
	ldr	x9, [sp, #24]
	ldrsw	x10, [sp, #8]
	mul	x10, x10, x11
	ldr	w9, [x9, x10]
	subs	w8, w8, w9
	b.ne	LBB3_11
	b	LBB3_9
LBB3_9:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mov	x11, #12
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #24]
	ldrsw	x10, [sp, #8]
	mul	x10, x10, x11
	add	x9, x9, x10
	ldr	w9, [x9, #4]
	subs	w8, w8, w9
	b.ge	LBB3_11
	b	LBB3_10
LBB3_10:                                ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mov	x11, #12
	mul	x9, x9, x11
	ldr	w8, [x8, x9]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	str	w8, [x9, x10]
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #4]
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #8]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #8]
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB3_12
LBB3_11:                                ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #8]
	mov	x11, #12
	mul	x9, x9, x11
	ldr	w8, [x8, x9]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	str	w8, [x9, x10]
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #8]
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #4]
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #8]
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #8]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #8]
	ldr	w8, [sp, #8]
	add	w8, w8, #1
	str	w8, [sp, #8]
	b	LBB3_12
LBB3_12:                                ;   in Loop: Header=BB3_1 Depth=1
	b	LBB3_13
LBB3_13:                                ;   in Loop: Header=BB3_1 Depth=1
	b	LBB3_14
LBB3_14:                                ;   in Loop: Header=BB3_1 Depth=1
	ldr	w8, [sp, #4]
	add	w8, w8, #1
	str	w8, [sp, #4]
	b	LBB3_1
LBB3_15:
	b	LBB3_16
LBB3_16:                                ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #20]
	subs	w8, w8, w9
	b.ge	LBB3_18
	b	LBB3_17
LBB3_17:                                ;   in Loop: Header=BB3_16 Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mov	x11, #12
	mul	x9, x9, x11
	ldr	w8, [x8, x9]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	str	w8, [x9, x10]
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #4]
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #12]
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #8]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #8]
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	ldr	w8, [sp, #4]
	add	w8, w8, #1
	str	w8, [sp, #4]
	b	LBB3_16
LBB3_18:
	b	LBB3_19
LBB3_19:                                ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #8]
	ldr	w9, [sp, #16]
	subs	w8, w8, w9
	b.ge	LBB3_21
	b	LBB3_20
LBB3_20:                                ;   in Loop: Header=BB3_19 Depth=1
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #8]
	mov	x11, #12
	mul	x9, x9, x11
	ldr	w8, [x8, x9]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	str	w8, [x9, x10]
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #8]
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #4]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #4]
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #8]
	mul	x9, x9, x11
	add	x8, x8, x9
	ldr	w8, [x8, #8]
	ldr	x9, [sp, #40]
	ldrsw	x10, [sp, #4]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #8]
	ldr	w8, [sp, #8]
	add	w8, w8, #1
	str	w8, [sp, #8]
	ldr	w8, [sp, #4]
	add	w8, w8, #1
	str	w8, [sp, #4]
	b	LBB3_19
LBB3_21:
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_merge_sort                     ; -- Begin function merge_sort
	.p2align	2
_merge_sort:                            ; @merge_sort
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	sub	sp, sp, #96
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	stur	x0, [x29, #-16]
	stur	w1, [x29, #-20]
	ldur	w8, [x29, #-20]
	subs	w8, w8, #1
	b.gt	LBB4_2
	b	LBB4_1
LBB4_1:
	b	LBB4_11
LBB4_2:
	ldur	w8, [x29, #-20]
	mov	w9, #2
	sdiv	w8, w8, w9
	stur	w8, [x29, #-24]
	ldur	w8, [x29, #-24]
                                        ; kill: def $x8 killed $w8
	mov	x9, sp
	stur	x9, [x29, #-32]
	mov	x9, #12
	mul	x9, x8, x9
	mov	x10, #15
	stur	x10, [x29, #-88]                ; 8-byte Folded Spill
	add	x9, x9, #15
	and	x9, x9, #0xfffffffffffffff0
	stur	x9, [x29, #-96]                 ; 8-byte Folded Spill
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	ldur	x10, [x29, #-96]                ; 8-byte Folded Reload
	ldur	x11, [x29, #-88]                ; 8-byte Folded Reload
	mov	x9, sp
	subs	x9, x9, x10
	mov	sp, x9
	stur	x9, [x29, #-80]                 ; 8-byte Folded Spill
	stur	x8, [x29, #-40]
	ldur	w8, [x29, #-20]
	ldur	w9, [x29, #-24]
	subs	w9, w8, w9
	mov	x8, x9
	mov	w10, #12
	umaddl	x9, w9, w10, x11
	and	x9, x9, #0xfffffffffffffff0
	stur	x9, [x29, #-72]                 ; 8-byte Folded Spill
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	ldur	x10, [x29, #-72]                ; 8-byte Folded Reload
	mov	x9, sp
	subs	x9, x9, x10
	mov	sp, x9
	stur	x9, [x29, #-64]                 ; 8-byte Folded Spill
	stur	x8, [x29, #-48]
	stur	wzr, [x29, #-52]
	b	LBB4_3
LBB4_3:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-52]
	ldur	w9, [x29, #-24]
	subs	w8, w8, w9
	b.ge	LBB4_6
	b	LBB4_4
LBB4_4:                                 ;   in Loop: Header=BB4_3 Depth=1
	ldur	x9, [x29, #-80]                 ; 8-byte Folded Reload
	ldur	x8, [x29, #-16]
	ldursw	x10, [x29, #-52]
	mov	x11, #12
	mul	x10, x10, x11
	ldr	w8, [x8, x10]
	ldursw	x10, [x29, #-52]
	mul	x10, x10, x11
	str	w8, [x9, x10]
	ldur	x8, [x29, #-16]
	ldursw	x10, [x29, #-52]
	mul	x10, x10, x11
	add	x8, x8, x10
	ldr	w8, [x8, #4]
	ldursw	x10, [x29, #-52]
	mul	x12, x10, x11
	mov	x10, x9
	add	x10, x10, x12
	str	w8, [x10, #4]
	ldur	x8, [x29, #-16]
	ldursw	x10, [x29, #-52]
	mul	x10, x10, x11
	add	x8, x8, x10
	ldr	w8, [x8, #8]
	ldursw	x10, [x29, #-52]
	mul	x10, x10, x11
	add	x9, x9, x10
	str	w8, [x9, #8]
	b	LBB4_5
LBB4_5:                                 ;   in Loop: Header=BB4_3 Depth=1
	ldur	w8, [x29, #-52]
	add	w8, w8, #1
	stur	w8, [x29, #-52]
	b	LBB4_3
LBB4_6:
	ldur	w8, [x29, #-24]
	stur	w8, [x29, #-56]
	b	LBB4_7
LBB4_7:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-56]
	ldur	w9, [x29, #-20]
	subs	w8, w8, w9
	b.ge	LBB4_10
	b	LBB4_8
LBB4_8:                                 ;   in Loop: Header=BB4_7 Depth=1
	ldur	x11, [x29, #-64]                ; 8-byte Folded Reload
	ldur	x8, [x29, #-16]
	ldursw	x9, [x29, #-56]
	mov	x10, #12
	mul	x9, x9, x10
	ldr	w8, [x8, x9]
	ldur	w9, [x29, #-56]
	ldur	w12, [x29, #-24]
	subs	w9, w9, w12
	mov	w12, #12
	smull	x9, w9, w12
	str	w8, [x11, x9]
	ldur	x8, [x29, #-16]
	ldursw	x9, [x29, #-56]
	mul	x9, x9, x10
	add	x8, x8, x9
	ldr	w8, [x8, #4]
	ldur	w9, [x29, #-56]
	ldur	w12, [x29, #-24]
	subs	w9, w9, w12
	mov	x13, x11
	mov	w12, #12
	smaddl	x9, w9, w12, x13
	str	w8, [x9, #4]
	ldur	x8, [x29, #-16]
	ldursw	x9, [x29, #-56]
	mul	x9, x9, x10
	add	x8, x8, x9
	ldr	w8, [x8, #8]
	ldur	w9, [x29, #-56]
	ldur	w10, [x29, #-24]
	subs	w9, w9, w10
	mov	w10, #12
	smaddl	x9, w9, w10, x11
	str	w8, [x9, #8]
	b	LBB4_9
LBB4_9:                                 ;   in Loop: Header=BB4_7 Depth=1
	ldur	w8, [x29, #-56]
	add	w8, w8, #1
	stur	w8, [x29, #-56]
	b	LBB4_7
LBB4_10:
	ldur	x0, [x29, #-80]                 ; 8-byte Folded Reload
	ldur	w1, [x29, #-24]
	bl	_merge_sort
	ldur	x0, [x29, #-64]                 ; 8-byte Folded Reload
	ldur	w8, [x29, #-20]
	ldur	w9, [x29, #-24]
	subs	w1, w8, w9
	bl	_merge_sort
	ldur	x1, [x29, #-80]                 ; 8-byte Folded Reload
	ldur	x2, [x29, #-64]                 ; 8-byte Folded Reload
	ldur	x0, [x29, #-16]
	ldur	w3, [x29, #-24]
	ldur	w8, [x29, #-20]
	ldur	w9, [x29, #-24]
	subs	w4, w8, w9
	bl	_merge
	ldur	x8, [x29, #-32]
	mov	sp, x8
	b	LBB4_11
LBB4_11:
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	b.eq	LBB4_13
	b	LBB4_12
LBB4_12:
	bl	___stack_chk_fail
LBB4_13:
	mov	sp, x29
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_multiply_2                     ; -- Begin function multiply_2
	.p2align	2
_multiply_2:                            ; @multiply_2
	.cfi_startproc
; %bb.0:
	stp	x28, x27, [sp, #-32]!           ; 16-byte Folded Spill
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	mov	w9, #6992
	movk	w9, #183, lsl #16
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	sub	sp, sp, #2929, lsl #12          ; =11997184
	sub	sp, sp, #2896
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w27, -24
	.cfi_offset w28, -32
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-24]
	str	x0, [sp, #64]
	str	x1, [sp, #56]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldr	x8, [sp, #64]
	ldr	x8, [x8, #16]
	str	x8, [sp, #48]
	ldr	x8, [sp, #56]
	ldr	x8, [x8, #16]
	str	x8, [sp, #40]
	str	wzr, [sp, #36]
	b	LBB5_1
LBB5_1:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB5_3 Depth 2
                                        ;     Child Loop BB5_8 Depth 2
	ldr	x8, [sp, #48]
	cbz	x8, LBB5_16
	b	LBB5_2
LBB5_2:                                 ;   in Loop: Header=BB5_1 Depth=1
	ldr	x8, [sp, #48]
	ldr	w8, [x8]
	str	w8, [sp, #32]
	b	LBB5_3
LBB5_3:                                 ;   Parent Loop BB5_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x8, [sp, #40]
	mov	w9, #0
	str	w9, [sp, #4]                    ; 4-byte Folded Spill
	cbz	x8, LBB5_5
	b	LBB5_4
LBB5_4:                                 ;   in Loop: Header=BB5_3 Depth=2
	ldr	w8, [sp, #32]
	ldr	x9, [sp, #40]
	ldr	w9, [x9]
	subs	w8, w8, w9
	cset	w8, gt
	str	w8, [sp, #4]                    ; 4-byte Folded Spill
	b	LBB5_5
LBB5_5:                                 ;   in Loop: Header=BB5_3 Depth=2
	ldr	w8, [sp, #4]                    ; 4-byte Folded Reload
	tbz	w8, #0, LBB5_7
	b	LBB5_6
LBB5_6:                                 ;   in Loop: Header=BB5_3 Depth=2
	ldr	x8, [sp, #40]
	ldr	x8, [x8, #16]
	str	x8, [sp, #40]
	b	LBB5_3
LBB5_7:                                 ;   in Loop: Header=BB5_1 Depth=1
	ldr	x8, [sp, #40]
	str	x8, [sp, #24]
	b	LBB5_8
LBB5_8:                                 ;   Parent Loop BB5_1 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldr	x8, [sp, #40]
	mov	w9, #0
	str	w9, [sp]                        ; 4-byte Folded Spill
	cbz	x8, LBB5_10
	b	LBB5_9
LBB5_9:                                 ;   in Loop: Header=BB5_8 Depth=2
	ldr	x8, [sp, #40]
	ldr	w8, [x8]
	ldr	w9, [sp, #32]
	subs	w8, w8, w9
	cset	w8, eq
	str	w8, [sp]                        ; 4-byte Folded Spill
	b	LBB5_10
LBB5_10:                                ;   in Loop: Header=BB5_8 Depth=2
	ldr	w8, [sp]                        ; 4-byte Folded Reload
	tbz	w8, #0, LBB5_12
	b	LBB5_11
LBB5_11:                                ;   in Loop: Header=BB5_8 Depth=2
	ldr	x8, [sp, #48]
	ldr	w8, [x8, #8]
	ldr	x9, [sp, #40]
	ldr	w9, [x9, #8]
	mul	w8, w8, w9
	str	w8, [sp, #20]
	ldr	x8, [sp, #48]
	ldr	w8, [x8, #4]
	str	w8, [sp, #16]
	ldr	x8, [sp, #40]
	ldr	w8, [x8, #4]
	str	w8, [sp, #12]
	ldr	w1, [sp, #16]
	ldr	w2, [sp, #12]
	ldr	w3, [sp, #20]
	ldr	w4, [sp, #36]
	add	x0, sp, #72
	bl	_insert
	str	w0, [sp, #36]
	ldr	x8, [sp, #40]
	ldr	x8, [x8, #16]
	str	x8, [sp, #40]
	b	LBB5_8
LBB5_12:                                ;   in Loop: Header=BB5_1 Depth=1
	ldr	x8, [sp, #48]
	ldr	x8, [x8, #16]
	str	x8, [sp, #48]
	ldr	x8, [sp, #48]
	cbz	x8, LBB5_15
	b	LBB5_13
LBB5_13:                                ;   in Loop: Header=BB5_1 Depth=1
	ldr	x8, [sp, #48]
	ldr	w8, [x8]
	ldr	w9, [sp, #32]
	subs	w8, w8, w9
	b.ne	LBB5_15
	b	LBB5_14
LBB5_14:                                ;   in Loop: Header=BB5_1 Depth=1
	ldr	x8, [sp, #24]
	str	x8, [sp, #40]
	b	LBB5_15
LBB5_15:                                ;   in Loop: Header=BB5_1 Depth=1
	b	LBB5_1
LBB5_16:
	ldr	w1, [sp, #36]
	add	x0, sp, #72
	bl	_merge_sort
	str	wzr, [sp, #8]
	b	LBB5_17
LBB5_17:                                ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #8]
	ldr	w9, [sp, #36]
	subs	w8, w8, w9
	b.ge	LBB5_20
	b	LBB5_18
LBB5_18:                                ;   in Loop: Header=BB5_17 Depth=1
	b	LBB5_19
LBB5_19:                                ;   in Loop: Header=BB5_17 Depth=1
	ldr	w8, [sp, #8]
	add	w8, w8, #1
	str	w8, [sp, #8]
	b	LBB5_17
LBB5_20:
	ldur	x9, [x29, #-24]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	b.eq	LBB5_22
	b	LBB5_21
LBB5_21:
	bl	___stack_chk_fail
LBB5_22:
	add	sp, sp, #2929, lsl #12          ; =11997184
	add	sp, sp, #2896
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x28, x27, [sp], #32             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #384
	stp	x28, x27, [sp, #352]            ; 16-byte Folded Spill
	stp	x29, x30, [sp, #368]            ; 16-byte Folded Spill
	add	x29, sp, #368
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w27, -24
	.cfi_offset w28, -32
	stur	wzr, [x29, #-20]
	mov	x9, sp
	sub	x8, x29, #24
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_scanf
	ldursb	w8, [x29, #-24]
	subs	w8, w8, #65
	b.ne	LBB6_10
	b	LBB6_1
LBB6_1:
	mov	x9, sp
	sub	x8, x29, #28
	str	x8, [x9]
	sub	x8, x29, #32
	str	x8, [x9, #8]
	sub	x8, x29, #36
	str	x8, [x9, #16]
	sub	x8, x29, #40
	str	x8, [x9, #24]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_scanf
	mov	x0, #24
	str	x0, [sp, #64]                   ; 8-byte Folded Spill
	bl	_malloc
	mov	x8, x0
	ldr	x0, [sp, #64]                   ; 8-byte Folded Reload
	stur	x8, [x29, #-64]
	ldur	x9, [x29, #-64]
	mov	w8, #-1
	str	w8, [sp, #76]                   ; 4-byte Folded Spill
	str	w8, [x9, #4]
	ldur	x9, [x29, #-64]
	str	w8, [x9]
	ldur	x8, [x29, #-64]
	str	wzr, [x8, #8]
	ldur	x8, [x29, #-64]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #16]
	bl	_malloc
	ldr	w8, [sp, #76]                   ; 4-byte Folded Reload
	stur	x0, [x29, #-72]
	ldur	x9, [x29, #-72]
	str	w8, [x9, #4]
	ldur	x9, [x29, #-72]
	str	w8, [x9]
	ldur	x8, [x29, #-72]
	str	wzr, [x8, #8]
	ldur	x8, [x29, #-72]
	str	xzr, [x8, #16]
	ldur	x8, [x29, #-64]
	stur	x8, [x29, #-80]
	stur	wzr, [x29, #-84]
	b	LBB6_2
LBB6_2:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-84]
	ldur	w9, [x29, #-36]
	subs	w8, w8, w9
	b.ge	LBB6_5
	b	LBB6_3
LBB6_3:                                 ;   in Loop: Header=BB6_2 Depth=1
	mov	x9, sp
	sub	x8, x29, #44
	str	x8, [x9]
	sub	x8, x29, #48
	str	x8, [x9, #8]
	sub	x8, x29, #52
	str	x8, [x9, #16]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_scanf
	mov	x0, #24
	bl	_malloc
	stur	x0, [x29, #-96]
	ldur	x8, [x29, #-96]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #16]
	ldur	w8, [x29, #-48]
	ldur	x9, [x29, #-96]
	str	w8, [x9, #4]
	ldur	w8, [x29, #-52]
	ldur	x9, [x29, #-96]
	str	w8, [x9, #8]
	ldur	w8, [x29, #-44]
	ldur	x9, [x29, #-96]
	str	w8, [x9]
	ldur	x8, [x29, #-96]
	ldur	x9, [x29, #-80]
	str	x8, [x9, #16]
	ldur	x8, [x29, #-80]
	ldr	x8, [x8, #16]
	stur	x8, [x29, #-80]
	b	LBB6_4
LBB6_4:                                 ;   in Loop: Header=BB6_2 Depth=1
	ldur	w8, [x29, #-84]
	add	w8, w8, #1
	stur	w8, [x29, #-84]
	b	LBB6_2
LBB6_5:
	ldur	x8, [x29, #-72]
	stur	x8, [x29, #-104]
	stur	wzr, [x29, #-108]
	b	LBB6_6
LBB6_6:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-108]
	ldur	w9, [x29, #-40]
	subs	w8, w8, w9
	b.ge	LBB6_9
	b	LBB6_7
LBB6_7:                                 ;   in Loop: Header=BB6_6 Depth=1
	mov	x9, sp
	sub	x8, x29, #44
	str	x8, [x9]
	sub	x8, x29, #48
	str	x8, [x9, #8]
	sub	x8, x29, #52
	str	x8, [x9, #16]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_scanf
	mov	x0, #24
	bl	_malloc
	stur	x0, [x29, #-120]
	ldur	x8, [x29, #-120]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #16]
	ldur	w8, [x29, #-48]
	ldur	x9, [x29, #-120]
	str	w8, [x9, #4]
	ldur	w8, [x29, #-52]
	ldur	x9, [x29, #-120]
	str	w8, [x9, #8]
	ldur	w8, [x29, #-44]
	ldur	x9, [x29, #-120]
	str	w8, [x9]
	ldur	x8, [x29, #-120]
	ldur	x9, [x29, #-104]
	str	x8, [x9, #16]
	ldur	x8, [x29, #-104]
	ldr	x8, [x8, #16]
	stur	x8, [x29, #-104]
	b	LBB6_8
LBB6_8:                                 ;   in Loop: Header=BB6_6 Depth=1
	ldur	w8, [x29, #-108]
	add	w8, w8, #1
	stur	w8, [x29, #-108]
	b	LBB6_6
LBB6_9:
	ldur	x0, [x29, #-64]
	ldur	x1, [x29, #-72]
	bl	_add
	b	LBB6_32
LBB6_10:
	ldursb	w8, [x29, #-24]
	subs	w8, w8, #84
	b.ne	LBB6_20
	b	LBB6_11
LBB6_11:
	mov	x9, sp
	sub	x8, x29, #124
	str	x8, [x9]
	sub	x8, x29, #128
	str	x8, [x9, #8]
	sub	x8, x29, #132
	str	x8, [x9, #16]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_scanf
	mov	x0, #24
	bl	_malloc
	stur	x0, [x29, #-152]
	ldur	x9, [x29, #-152]
	mov	w8, #-1
	str	w8, [x9, #4]
	ldur	x9, [x29, #-152]
	str	w8, [x9]
	ldur	x8, [x29, #-152]
	str	wzr, [x8, #8]
	ldur	x8, [x29, #-152]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #16]
	ldur	x8, [x29, #-152]
	stur	x8, [x29, #-160]
	stur	wzr, [x29, #-164]
	b	LBB6_12
LBB6_12:                                ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-164]
	ldur	w9, [x29, #-132]
	subs	w8, w8, w9
	b.ge	LBB6_15
	b	LBB6_13
LBB6_13:                                ;   in Loop: Header=BB6_12 Depth=1
	mov	x9, sp
	sub	x8, x29, #136
	str	x8, [x9]
	sub	x8, x29, #140
	str	x8, [x9, #8]
	sub	x8, x29, #144
	str	x8, [x9, #16]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_scanf
	mov	x0, #24
	bl	_malloc
	stur	x0, [x29, #-176]
	ldur	x8, [x29, #-176]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #16]
	ldur	w8, [x29, #-140]
	ldur	x9, [x29, #-176]
	str	w8, [x9, #4]
	ldur	w8, [x29, #-144]
	ldur	x9, [x29, #-176]
	str	w8, [x9, #8]
	ldur	w8, [x29, #-136]
	ldur	x9, [x29, #-176]
	str	w8, [x9]
	ldur	x8, [x29, #-176]
	ldur	x9, [x29, #-160]
	str	x8, [x9, #16]
	ldur	x8, [x29, #-160]
	ldr	x8, [x8, #16]
	stur	x8, [x29, #-160]
	b	LBB6_14
LBB6_14:                                ;   in Loop: Header=BB6_12 Depth=1
	ldur	w8, [x29, #-164]
	add	w8, w8, #1
	stur	w8, [x29, #-164]
	b	LBB6_12
LBB6_15:
	ldur	x0, [x29, #-152]
	ldur	w1, [x29, #-132]
	bl	_transpose
	str	x0, [sp, #184]
	ldr	x8, [sp, #184]
	ldr	x8, [x8, #16]
	str	x8, [sp, #184]
	str	wzr, [sp, #180]
	b	LBB6_16
LBB6_16:                                ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #180]
	ldur	w9, [x29, #-132]
	subs	w8, w8, w9
	b.ge	LBB6_19
	b	LBB6_17
LBB6_17:                                ;   in Loop: Header=BB6_16 Depth=1
	ldr	x8, [sp, #184]
	ldr	x8, [x8, #16]
	str	x8, [sp, #184]
	b	LBB6_18
LBB6_18:                                ;   in Loop: Header=BB6_16 Depth=1
	ldr	w8, [sp, #180]
	add	w8, w8, #1
	str	w8, [sp, #180]
	b	LBB6_16
LBB6_19:
	b	LBB6_31
LBB6_20:
	ldursb	w8, [x29, #-24]
	subs	w8, w8, #77
	b.ne	LBB6_30
	b	LBB6_21
LBB6_21:
	mov	x9, sp
	add	x8, sp, #176
	str	x8, [x9]
	add	x8, sp, #172
	str	x8, [x9, #8]
	add	x8, sp, #168
	str	x8, [x9, #16]
	add	x8, sp, #164
	str	x8, [x9, #24]
	add	x8, sp, #160
	str	x8, [x9, #32]
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_scanf
	mov	x0, #24
	str	x0, [sp, #48]                   ; 8-byte Folded Spill
	bl	_malloc
	mov	x8, x0
	ldr	x0, [sp, #48]                   ; 8-byte Folded Reload
	str	x8, [sp, #136]
	ldr	x9, [sp, #136]
	mov	w8, #-1
	str	w8, [sp, #60]                   ; 4-byte Folded Spill
	str	w8, [x9, #4]
	ldr	x9, [sp, #136]
	str	w8, [x9]
	ldr	x8, [sp, #136]
	str	wzr, [x8, #8]
	ldr	x8, [sp, #136]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #16]
	bl	_malloc
	ldr	w8, [sp, #60]                   ; 4-byte Folded Reload
	str	x0, [sp, #128]
	ldr	x9, [sp, #128]
	str	w8, [x9, #4]
	ldr	x9, [sp, #128]
	str	w8, [x9]
	ldr	x8, [sp, #128]
	str	wzr, [x8, #8]
	ldr	x8, [sp, #128]
	str	xzr, [x8, #16]
	ldr	x8, [sp, #136]
	str	x8, [sp, #120]
	str	wzr, [sp, #116]
	b	LBB6_22
LBB6_22:                                ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #116]
	ldr	w9, [sp, #164]
	subs	w8, w8, w9
	b.ge	LBB6_25
	b	LBB6_23
LBB6_23:                                ;   in Loop: Header=BB6_22 Depth=1
	mov	x9, sp
	add	x8, sp, #156
	str	x8, [x9]
	add	x8, sp, #152
	str	x8, [x9, #8]
	add	x8, sp, #148
	str	x8, [x9, #16]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_scanf
	mov	x0, #24
	bl	_malloc
	str	x0, [sp, #104]
	ldr	x8, [sp, #104]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #16]
	ldr	w8, [sp, #152]
	ldr	x9, [sp, #104]
	str	w8, [x9, #4]
	ldr	w8, [sp, #148]
	ldr	x9, [sp, #104]
	str	w8, [x9, #8]
	ldr	w8, [sp, #156]
	ldr	x9, [sp, #104]
	str	w8, [x9]
	ldr	x8, [sp, #104]
	ldr	x9, [sp, #120]
	str	x8, [x9, #16]
	ldr	x8, [sp, #120]
	ldr	x8, [x8, #16]
	str	x8, [sp, #120]
	b	LBB6_24
LBB6_24:                                ;   in Loop: Header=BB6_22 Depth=1
	ldr	w8, [sp, #116]
	add	w8, w8, #1
	str	w8, [sp, #116]
	b	LBB6_22
LBB6_25:
	ldr	x0, [sp, #136]
	ldr	w1, [sp, #164]
	bl	_transpose
	str	x0, [sp, #136]
	ldr	x8, [sp, #128]
	str	x8, [sp, #96]
	str	wzr, [sp, #92]
	b	LBB6_26
LBB6_26:                                ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #92]
	ldr	w9, [sp, #160]
	subs	w8, w8, w9
	b.ge	LBB6_29
	b	LBB6_27
LBB6_27:                                ;   in Loop: Header=BB6_26 Depth=1
	mov	x9, sp
	add	x8, sp, #156
	str	x8, [x9]
	add	x8, sp, #152
	str	x8, [x9, #8]
	add	x8, sp, #148
	str	x8, [x9, #16]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_scanf
	mov	x0, #24
	bl	_malloc
	str	x0, [sp, #80]
	ldr	x8, [sp, #80]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #16]
	ldr	w8, [sp, #152]
	ldr	x9, [sp, #80]
	str	w8, [x9, #4]
	ldr	w8, [sp, #148]
	ldr	x9, [sp, #80]
	str	w8, [x9, #8]
	ldr	w8, [sp, #156]
	ldr	x9, [sp, #80]
	str	w8, [x9]
	ldr	x8, [sp, #80]
	ldr	x9, [sp, #96]
	str	x8, [x9, #16]
	ldr	x8, [sp, #96]
	ldr	x8, [x8, #16]
	str	x8, [sp, #96]
	b	LBB6_28
LBB6_28:                                ;   in Loop: Header=BB6_26 Depth=1
	ldr	w8, [sp, #92]
	add	w8, w8, #1
	str	w8, [sp, #92]
	b	LBB6_26
LBB6_29:
	ldr	x8, [sp, #136]
	ldr	w9, [x8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	ldr	x0, [sp, #136]
	ldr	x1, [sp, #128]
	bl	_multiply_2
	b	LBB6_30
LBB6_30:
	b	LBB6_31
LBB6_31:
	b	LBB6_32
LBB6_32:
	ldur	w0, [x29, #-20]
	ldp	x29, x30, [sp, #368]            ; 16-byte Folded Reload
	ldp	x28, x27, [sp, #352]            ; 16-byte Folded Reload
	add	sp, sp, #384
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"hi\n"

l_.str.1:                               ; @.str.1
	.asciz	"%s\n"

l_.str.2:                               ; @.str.2
	.asciz	"%d %d %d %d"

l_.str.3:                               ; @.str.3
	.asciz	"%d %d %d"

l_.str.4:                               ; @.str.4
	.asciz	"%d %d %d %d %d"

l_.str.5:                               ; @.str.5
	.asciz	"askdjf %d\n"

.subsections_via_symbols
