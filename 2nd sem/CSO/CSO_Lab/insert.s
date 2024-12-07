.global insert
insert:
    movq $1,%r8
    loop_outer:
        cmp %r8,%rsi
        je end
        movq %r8,%r9
        decq %r9
        movq (%rdi,%r8,8),%r10
        loop_inner:
            cmp $0,%r9
            jl end_inner
            movq (%rdi,%r9,8),%r11
            cmp %r10,%r11
            jle end_inner
            movq %r9,%r12
            incq %r12
            movq %r11,(%rdi,%r12,8)
            decq %r9
            jmp loop_inner
        end_inner:
            incq %r9
            movq %r10,(%rdi,%r9,8)
            incq %r8
            jmp loop_outer

    end:
        ret
