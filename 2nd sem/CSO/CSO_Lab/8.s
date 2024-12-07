.global sort
sort:
    movq %rdi,%r8       #moving array ptr to %r8
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
        movq %rsi,%rax
        movq $2,%r9
        movq $0,%rdx
        idivq %r9
        movq $0,%r9
        loop_wavy:
            cmp %r9,%rax
            je end 
            movq (%rdi),%r10
            addq $8,%rdi
            movq (%rdi),%r11
            movq %r10,(%rdi)
            subq $8,%rdi
            movq %r11,(%rdi)
            addq $16,%rdi
            addq $1,%r9
            jmp loop_wavy
    end:
        ret

