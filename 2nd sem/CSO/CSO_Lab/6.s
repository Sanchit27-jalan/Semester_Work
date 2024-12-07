.global answer

answer:
    movq $0,%r8
    movq $2,%r9
    movq $3,%r10
    movq $0,%r11
    movq (%rdi),%r12
    movq $0,%r13
    movq %rdx,%rcx
    loop_start:
        cmp %r13,%rsi
        je end
        cmp %r8,%rcx
        je rowchange
        movq $0,%rdx
        movq (%r12),%rax
        idivq %r9
        cmp $0,%rdx
        je divisible_by_2
        addq $1,%r8
        addq $8,%r12
        jmp loop_start
    
    divisible_by_2:
        movq $0,%rdx
        movq (%r12),%rax
        idivq %r10
        cmp $0,%rdx
        jne not_divisible_by_3
        addq $1,%r8
        addq $8,%r12
        jmp loop_start
    
    not_divisible_by_3:
        movq (%r12),%rax
        addq %rax,%r11
        addq $1,%r8
        addq $8,%r12
        jmp loop_start

    rowchange:
        addq $8,%rdi
        movq (%rdi),%r12
        addq $1,%r13
        movq $0,%r8
        jmp loop_start

    end:
        movq %r11,%rax
        ret

