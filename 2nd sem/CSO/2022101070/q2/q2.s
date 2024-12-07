.global calculate

calculate:
    mov %rsi,%rax          # Move x to rax
    mov %rcx,%r10          # Move y to r10
    cmp $0,%rax            # Check if x is negative
    jg x_positive          # If x is non-negative, go to x_positive
    cmp $0,%rsi
    jl x_negative          # If x is negative, go to x_negative
    cmp $0,%rsi
    je x_zero              # If x is zero, go to x_zero
    
x_zero:
    mov %rdi,%rax          # Move a to rax (result = a)
    jmp ans_x              # Jump to calculate the result of x

x_positive:
    mov %rdi,%rbx          # Move a to rbx (dividend = a)
    mov %al,%cl            # Move lower 8 bits of x to cl
    mov $1,%rax            # Set rax to 1
    shl %cl,%rax           # Calculate 2^x (2^x = 1 << x)
    mov %rax,%r9           # Store 2^x in r9
    loop_start:
        sub $1,%rdi        # Decrement dividend by 1
        cmp $0,%rdi        # Compare dividend with 0
        je ans_x           # If dividend is 0, jump to calculate the result of x
        add %r9,%rax       # Add 2^x to the result (rax)
        jmp loop_start     # Repeat the loop
    
x_negative:
    neg %rsi               # Negate x
    neg %rax               # Negate the result (rax)
    mov %al,%cl            # Move lower 8 bits of x to cl
    mov $1,%rax            # Set rax to 1
    shl %cl,%rax           # Calculate 2^x (2^x = 1 << x)
    mov %rax,%r9           # Store 2^x in r9
    mov $0,%rcx            # Set quotient counter to 0
    cmp %rdi,%r9           # Compare dividend with 2^x
    jg base                # If dividend > 2^x, go to base
    cmp %rdi,%rsi
    jle ans_both_pos       # If dividend <= x, jump to calculate the result of x and y
    
base:
    mov %rcx,%rax          # Move quotient counter to rax
    jmp ans_x              # Jump to calculate the result of x

ans_both_pos:
    sub %r9, %rdi          # Subtract divisor (2^x) from dividend
    add $1, %rcx           # Increment quotient counter
    cmp %rdi, %r9          # Compare dividend with divisor
    jle ans_both_pos       # If dividend is still larger than divisor, repeat subtraction
    mov %rcx,%rax          # Move quotient counter to rax
    jmp ans_x              # Jump to calculate the result of x


ans_x:
    mov %rax,%r14          # Move the result of x to r14

jmp y_check              # Jump to check the value of y

y_check:
    mov %r10,%rax          # Move y to rax
    cmp $0,%rax            # Check if y is negative
    jg y_positive          # If y is non-negative, go to y_positive
    cmp $0,%rax
    jl y_negative          # If y is negative, go to y_negative
    cmp $0,%rax
    je y_zero              # If y is zero, go to y_zero

y_zero:
    mov %rdx,%rax          # Move b to rax (result = b)
    add %r14,%rax          # Add the result of x to the result
    jmp result             # Jump to return the final result

y_positive:
    mov %rdx,%rbx          # Move b to rbx (dividend = b)
    mov %al,%cl            # Move lower 8 bits of y to cl
    mov $1,%rax            # Set rax to 1
    shl %cl,%rax           # Calculate 2^y (2^y = 1 << y)
    mov %rax,%r9           # Store 2^y in r9
    loop_start1:
        sub $1,%rdx        # Decrement dividend by 1
        cmp $0,%rdx        # Compare dividend with 0
        je ans_y           # If dividend is 0, jump to calculate the result of y
        add %r9,%rax       # Add 2^y to the result (rax)
        jmp loop_start1    # Repeat the loop

y_negative:
    neg %r10               # Negate y
    neg %rax               # Negate the result (rax)
    mov %al,%cl            # Move lower 8 bits of y to cl
    mov $1,%rax            # Set rax to 1
    shl %cl,%rax           # Calculate 2^y (2^y = 1 << y)
    mov %rax,%r9           # Store 2^y in r9
    mov $0,%rcx            # Set quotient counter to 0
    cmp %rdx,%r9           # Compare dividend with 2^y
    jg bases               # If dividend > 2^y, go to bases
    cmp %rdx,%r10
    jle ans_both_pos_      # If dividend <= y, jump to calculate the result of x and y
    
bases:
    mov %rcx,%rax          # Move quotient counter to rax
    jmp ans_y              # Jump to calculate the result of y

ans_both_pos_:
    sub %r9, %rdx          # Subtract divisor (2^y) from dividend
    add $1, %rcx           # Increment quotient counter
    cmp %rdx, %r9          # Compare dividend with divisor
    jle ans_both_pos_      # If dividend is still larger than divisor, repeat subtraction
    mov %rcx,%rax          # Move quotient counter to rax
    jmp ans_y              # Jump to calculate the result of y

ans_y:
    add %r14,%rax          # Add the result of x to the result (rax)
    jmp result             # Jump to return the final result

result:
    ret                    # Return the final result
