.global maxsum
maxsum:
    movq $0,%r8         #left elems
    movq $0,%r9         #rightelems
    movq $0,%r10        #sumofelems
    movq $0,%r11        #values ka sum
    subq $1,%rsi 
    movq %rdi,%rcx
    movq $8,%r12
    imulq %r12,%rsi
    addq %rsi,%rdi
    loop_start:
        cmp %r10,%rdx
        je end
        movq (%rcx),%r13
        movq (%rdi),%r14
        cmp %r13,%r14
        jge rightmore
        jmp leftmore

    rightmore:
        addq %r14,%r11
        addq $1,%r9
        subq $8,%rdi
        addq $1,%r10
        jmp loop_start

    leftmore:
        addq %r13,%r11
        addq $1,%r8
        addq $8,%rcx
        addq $1,%r10
        jmp loop_start
    
    end:
        movq %r11,%rax
        ret 
