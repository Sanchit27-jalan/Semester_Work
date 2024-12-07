.global exists
exists:
    movq %rdi,%r8       #moving array ptr to %r8
    movq %rsi,%rcx
    addq %rsi,%rsi
    movq %rdx,%rbx
    movq $0,%rdx
    movq $0,%r9         #i=0
    movq $8,%r12
    loop_start:
        cmp %r9,%rsi
        je array_sorted
        movq $100000000,%r11       #min value intialize
        movq %r9,%r10
        movq %r9,%r13      #index intialize
        loop:
            movq $8,%r12
            cmp %r10,%rsi
            je end_of_inner_loop
            imulq %r10,%r12
            addq %r12,%rdi
            movq (%rdi),%r14
            movq $8,%r12
            cmp %r14,%r11
            jg change
            addq $1,%r10
            movq %r8,%rdi
            jmp loop


    change:
        movq %r10,%r13
        movq %r8,%rdi
        movq $8,%r12
        imulq %r10,%r12
        addq %r12,%rdi
        movq (%rdi),%r11
        addq $1,%r10
        movq %r8,%rdi
        jmp loop
    
    end_of_inner_loop:
        movq $8,%r12
        movq %r8,%rdi
        imulq %r9,%r12
        addq %r12,%rdi
        movq (%rdi),%r14   #i value in %r14
        movq $8,%r12
        imulq %r13,%r12
        movq %r8,%rdi
        addq %r12,%rdi
        movq (%rdi),%r15
        movq $8,%r12
        movq %r8,%rdi
        imulq %r9,%r12
        addq %r12,%rdi
        movq %r15,(%rdi)
        movq $8,%r12
        movq %r8,%rdi
        imulq %r13,%r12
        addq %r12,%rdi
        movq %r14,(%rdi)
        addq $1,%r9
        movq %r8,%rdi
        jmp loop_start

    array_sorted:
        movq %r8,%rdi
        movq $0,%r9
        movq %rcx,%r10
        loop1:
            cmp %r9,%rcx
            je end 
            movq (%rdi),%r11
            movq (%rdi,%rcx,8),%r12
            subq %r11,%r12
            cmp %r12,%rbx
            jg end_neg
            addq $1,%r9
            addq $1,%r10
            addq $8,%rdi
            jmp loop1
    
    end:
        movq $1,%rax
        ret
    end_neg:
        movq $0,%rax
        ret
