.global palindrome
palindrome:
    movq $0,%r8
    movq %rdi,%rax
    movq $10,%r10
    loop_start:
        movq $0,%rdx
        cmp $0,%rax
        je digitcal
        idivq %r10
        addq $1,%r8
        jmp loop_start
    
    digitcal:
        movq $1,%r12
        movq $1,%r13
        loop:
            cmp %r12,%r8
            je numberdone
            imulq %r10,%r13
            addq $1,%r12
            jmp loop


    numberdone:
        movq %rdi,%rax
        movq $0,%r11
        movq $0,%r9
        loop_1:
            cmp %r9,%r8
            je end
            movq $0,%rdx
            idivq %r10
            movq %rax,%r14
            imulq %r13,%rdx
            addq %rdx,%r11
            movq $0,%rdx
            movq %r13,%rax
            idivq %r10
            movq %rax,%r13
            movq %r14,%rax
            addq $1,%r9
            jmp loop_1
    end:
        cmp %r11,%rdi
        je end1
        movq $0,%rax
        ret
    end1:
        movq $1,%rax
        ret





