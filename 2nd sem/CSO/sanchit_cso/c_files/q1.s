.global get_sum

get_sum:
    mov $0,%r8             #to calculate sum of number
    mov $-1,%rbx    #initializing to -1 to iterate through array elements
    loop_start:     #loop start
        mov $0,%rdx    #initializing %rdx to 0 to avoid floating point error
        add $1,%rbx    #incrementing length
        cmp %rbx,%rsi  #condition for checking if array has been traversed or not
        jz loop_exit      #loop_exit
        mov (%rdi),%rax   #to move value stored at the address of %rdi to %rax
        mov %rax,%rcx     #to move value stored at %rax to %rcx
        add $8,%rdi       #to get next address of the array
        mov $3,%r9        #to move 3 to %r9 which is used to divide
        idivq %r9         #%rax / %r9 quotient in %rax and remainder in %rdx
        cmp $0,%rdx       #remainder and 0 compared 
        jz add_multiple   #goes to add_multiple part 
        jmp loop_start      #jumps to loop_start
    add_multiple:
        add %rcx,%r8    #add that number to %r8
        jmp loop_start
    loop_exit:
        mov %r8,%rax   #moves %r8 and %rax so that it can be returned
        ret

