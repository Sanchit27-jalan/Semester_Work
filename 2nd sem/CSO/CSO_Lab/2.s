.global conversion
conversion:
    movq $1,%r8
    movq $0,%r9
    movq $3,%r10
    movq $5,%r11
    movq %rdi,%rcx
    loop_start:
        movq $0,%r12
        movq $0,%rdx
        cmp %r9,%rcx
        je end
        movq %r8,%rax
        idivq %r10
        cmp $0,%rdx
        je divisible_by_3
        movq $0,%rdx
        movq %r8,%rax
        idivq %r11
        cmp $0,%rdx
        je divisible_by_5
        movq %r8,(%rsi)
        addq $8,%rsi
        addq $1,%r8
        addq $1,%r9
        jmp loop_start

divisible_by_3:
    addq $1,%r12
    movq $0,%rdx
    movq %r8,%rax
    idivq %r11
    cmp $0,%rdx
    je divisible_by_5
    neg %r12
    movq %r12,(%rsi)
    addq $8,%rsi
    addq $1,%r8
    addq $1,%r9
    jmp loop_start

divisible_by_5:
    addq $2,%r12
    neg %r12
    movq %r12,(%rsi)
    addq $8,%rsi
    addq $1,%r8
    addq $1,%r9
    jmp loop_start

end:
    ret
