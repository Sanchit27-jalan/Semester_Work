.global bubble
bubble:
    movq %rdi,%r8
    movq $0,%r9
    movq %rsi,%r10
    decq %r10
    loop_start:
        cmp %r9,%r10
        je end
        movq $0,%r11
        movq %r10,%r12
        subq %r9,%r12
        loop_inner:
            cmp %r11,%r12
            je inner_end
            movq (%rdi,%r11,8),%r13
            movq %r11,%r14
            incq %r14
            movq (%rdi,%r14,8),%r15
            cmp %r13,%r15
            jl swap
            addq $1,%r11
            jmp loop_inner
        swap:
            movq %r15,(%rdi,%r11,8)
            movq %r13,(%rdi,%r14,8)
            addq $1,%r11
            jmp loop_inner
        inner_end:
            addq $1,%r9
            jmp loop_start
    end:
        ret
