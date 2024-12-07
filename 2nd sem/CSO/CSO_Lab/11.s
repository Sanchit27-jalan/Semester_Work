.global convert
convert:
    movq %rdi,%r8
    movq $0,%r9             #odd sum
    movq $0,%r10            #even sum
    movq $0,%r11            #total sum
    movq $2,%r12
    loop:
        cmp %r11,%rsi
        je loop_ended
        movq $0,%rdx
        movq (%rdi),%rax
        idivq %r12
        cmp $0,%rdx
        je even
        addq $1,%r9
        addq $1,%r11
        addq $8,%rdi
        jmp loop

    even:
        addq $1,%r10
        addq $1,%r11
        addq $8,%rdi
        jmp loop

    loop_ended:
        cmp $0,%r9
        je end
        cmp $0,%r10
        je end
        jmp sort
    
    sort:
        movq $0,%r9         #i=0
        movq $8,%r12
        loop_start:
            cmp %r9,%rsi
            je end
            movq $100000000,%r11       #min value intialize
            movq %r9,%r10
            movq %r9,%r13      #index intialize
            loop3:
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
                jmp loop3


    change:
        movq %r10,%r13
        movq %r8,%rdi
        movq $8,%r12
        imulq %r10,%r12
        addq %r12,%rdi
        movq (%rdi),%r11
        addq $1,%r10
        movq %r8,%rdi
        jmp loop3
    
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

    end:
        ret

