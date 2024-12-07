.global get_address_smallest   # function declaration

get_address_smallest:   # function definition
    mov (%rdi),%r8   # initialize %r8 to the value pointed by %rdi
    mov %rdi,%r9   # initialize %r9 to the address in %rdi
    mov $-1,%rbx   # initialize %rbx to -1
    loop_start:
        add $1,%rbx   # increment %rbx by 1
        cmp %rbx,%rsi   # compare %rbx with the value in %rsi (loop counter)
        jz loop_exit   # jump to loop_exit if %rbx == %rsi (loop counter)

        cmp %r8,(%rdi)   # compare %r8 with the value pointed by %rdi
        jl less_than   # jump to less_than if the value pointed by %rdi is less than %r8
        
        add $8,%rdi   # increment %rdi by 8 (move to the next 64-bit address)
        jmp loop_start   # jump to loop_start
        
    less_than:
        mov (%rdi),%r8   # set %r8 to the value pointed by %rdi
        mov %rdi,%r9   # set %r9 to the address in %rdi
        add $8,%rdi   # increment %rdi by 8 (move to the next 64-bit address)
        jmp loop_start   # jump to loop_start

    loop_exit:
        mov %r9,%rax   # set %rax to the address in %r9 (the address of the smallest value)
        ret   # return the address of the smallest value
