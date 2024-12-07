.global convert
convert:
    movq $0,%r8
    movq $0,%r9
    movq $0,%r10
    loop_start:
        cmp %r10,%rdi
        je no_calc
        addq $1,%r10
        cmpq $0,(%rsi)
        je zero
        cmpq $1,(%rsi)
        je one
    
    zero:
        addq $1,%r8
        addq $8,%rsi
        jmp loop_start
    
    one:
        addq $1,%r9
        addq $8,%rsi
        jmp loop_start

    no_calc:
        movq $0,%r10
        loop_1:
            cmp %r10,%r8
            je loop_2
            movq $0,(%rdx)
            addq $8,%rdx
            addq $1,%r10
            jmp loop_1

    loop_2:
        cmp %r10,%rdi
        je end
        movq $1,(%rdx)
        addq $8,%rdx
        addq $1,%r10
        jmp loop_2

    end:
        ret





