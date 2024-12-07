.global answer
answer:
    movq %rdi,%r8           #first pointer in %rdi
    decq %rdx
    movq $8,%r9
    imulq %rdx,%r9
    addq %r9,%r8            #last pointer in %r8
    incq %rdx
    movq $0,%r10            #initial sum of line without any changes
    movq $0,%r12
    loop_start:
        cmp %rdx,%r12
        je initialcalc
        movq (%rdi,%r12,8),%r11
        cmp $0,%r11
        je zeroadd
        jmp oneadd

    zeroadd:
        addq %r12,%r10
        addq $1,%r12
        jmp loop_start

    oneadd:
        movq %rdx,%r11
        decq %r11
        subq %r12,%r11
        addq %r11,%r10
        addq $1,%r12
        jmp loop_start

    initialcalc:
        movq $0,%r11      #left index
        #movq $0,%r12      #right count
        movq $0,%r13      #total count
        movq %rdx,%r14
        decq %r14         #index for right 
        movq %rdx,%rbx
        decq %rbx
        loop:
            cmp %rdx,%r13
            je end
            cmp %r11,%r14
            jl maxmvalue_reached
            movq %r11,%rcx
            addq %r14,%rcx
            cmp %rcx,%rbx
            jge leftadd
            jmp rightadd
        leftadd:
            movq (%rdi,%r11,8),%r15
            cmp $0,%r15
            je leftchange
            addq $1,%r11
            jmp loop
        rightadd:
            movq (%rdi,%r14,8),%r15
            cmp $1,%r15
            je rightchange
            subq $1,%r14
            jmp loop
        leftchange:
            subq %r11,%r10
            movq %rdx,%r15
            decq %r15
            subq %r11,%r15
            addq %r15,%r10
            addq $1,%r11
            movq %r10,(%rsi,%r13,8)
            addq $1,%r13
            jmp loop

        rightchange:
            addq %r14,%r10
            movq %rdx,%r15
            decq %r15
            subq %r14,%r15
            subq %r15,%r10
            movq %r10,(%rsi,%r13,8)
            addq $1,%r13
            subq $1,%r14
            jmp loop

        maxmvalue_reached:
            cmp %rdx,%r13
            je end
            movq %r10,(%rsi,%r13,8)
            addq $1,%r13
            jmp maxmvalue_reached

        end:
            ret 
