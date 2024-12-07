.global bacteria
bacteria:
    movq $0,%r8
    movq $2,%r9
    loop_start:
        movq $0,%rdx
        cmp $1,%rax
        jge divide
        cmp $1,%rax
        jl terminate

    divide:
        idivq %r9
        cmp $1,%rdx
        je plus
        jmp loop_start
    plus:
        addq $1,%r8
        jmp loop_start
    
    terminate:
        movq %r8,%rax
        ret
