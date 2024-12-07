.global _divide

_divide:
    mov $0,%rcx               # Initialize quotient counter
    mov $0,%r8                # Temporary register for comparisons
    cmp $0, %rsi              # Check if divisor is zero
    je division_by_zero       # Jump to division_by_zero if it is

    cmp $0,%rsi
    jl division_by_negative   # Jump to division_by_negative if divisor is negative

    cmp $0,%rsi
    jg division_by_positive   # Jump to division_by_positive if divisor is positive

division_by_positive:
    cmp $0,%rdi
    jge both_positive         # Jump to both_positive if dividend is positive or zero
    cmp $0,%rdi
    jl up_neg_down_pos        # Jump to up_neg_down_pos if dividend is negative

both_positive:
    cmp %rdi,%rsi   
    jg base
    cmp %rdi,%rsi
    jle ans_both_pos

base:
    mov %rcx,(%rdx)           # Store quotient counter at the memory location pointed by rdx
    add $8,%rdx               # Move rdx to the next memory location
    mov %rdi,(%rdx)           # Store dividend at the memory location pointed by rdx
    ret                       # Return from the function

ans_both_pos:
    sub %rsi, %rdi            # Subtract divisor from dividend
    add $1, %rcx              # Increment quotient counter
    cmp %rdi, %rsi            # Check if dividend is still larger than divisor
    jle ans_both_pos          # If yes, repeat subtraction
    mov %rcx,(%rdx)           # Store quotient counter at the memory location pointed by rdx
    add $8,%rdx               # Move rdx to the next memory location
    mov %rdi,(%rdx)           # Store dividend at the memory location pointed by rdx
    ret                       # Return from the function

up_neg_down_pos:
    neg %rdi                  # Negate the dividend (convert negative to positive)
    cmp %rdi,%rsi
    jg bases                  # Jump to bases if dividend > divisor
    cmp %rdi,%rsi
    jle ans_up_neg_down_pos    # Jump to ans_up_neg_down_pos if dividend <= divisor

ans_up_neg_down_pos:
    sub %rsi, %rdi            # Subtract divisor from dividend
    add $1, %rcx              # Increment quotient counter
    cmp %rdi, %rsi            # Check if dividend is still larger than divisor
    jle ans_up_neg_down_pos    # If yes, repeat subtraction
    cmp $0,%rdi
    je ans_1
    sub %rdi,%rsi
    add $1,%rcx
    neg %rcx
    mov %rcx,(%rdx)           # Store quotient counter at the memory location pointed by rdx
    add $8,%rdx               # Move rdx to the next memory location
    mov %rsi,(%rdx)           # Store dividend at the memory location pointed by rdx
    ret                       # Return from the function

ans_1:
    neg %rcx
    mov %rcx,(%rdx)           # Store quotient counter at the memory location pointed by rdx
    add $8,%rdx               # Move rdx to the next memory location
    mov %rdi,(%rdx)           # Store dividend at the memory location pointed by rdx
    ret                       # Return from the function

bases:
    mov $-1,%rcx              # Set quotient counter to -1
    mov %rcx,(%rdx)           # Store quotient counter at the memory location pointed by rdx
    add $8,%rdx               # Move rdx to the next memory location
    sub %rdi,%rsi             # Subtract dividend from divisor
    mov %rsi,(%rdx)           # Store result at the memory location pointed by rdx
    ret                       # Return from the function

division_by_negative:
    cmp $0,%rdi
    jl both_negative          # Jump to both_negative if dividend is negative
    cmp $0,%rdi
    jg up_positive_down_negative  # Jump to up_positive_down_negative if dividend is positive

up_positive_down_negative:
    neg %rsi                  # Negate the divisor (convert negative to positive)
    cmp %rdi,%rsi
    jle divv                  # Jump to divv if dividend <= divisor
    mov $0,%rax
    mov %rax,(%rdx)           # Store quotient counter at the memory location pointed by rdx
    add $8,%rdx               # Move rdx to the next memory location
    mov %rdi,(%rdx)           # Store dividend at the memory location pointed by rdx
    ret                       # Return from the function

divv:
    sub %rsi, %rdi            # Subtract divisor from dividend
    add $1, %rcx              # Increment quotient counter
    cmp %rdi, %rsi            # Check if dividend is still larger than divisor
    jle divv                  # If yes, repeat subtraction
    neg %rcx
    mov %rcx, (%rdx)          # Store quotient counter at the memory location pointed by rdx
    add $8,%rdx               # Move rdx to the next memory location
    mov %rdi, (%rdx)          # Store dividend at the memory location pointed by rdx
    jmp done

div:
    sub %rsi, %rdi            # Subtract divisor from dividend
    add $1, %rcx              # Increment quotient counter
    cmp %rdi, %rsi            # Check if dividend is still larger than divisor
    jle div                    # If yes, repeat subtraction
    cmp $0,%rdi
    je ans
    add $1,%rcx
    sub %rdi,%rsi
    mov %rcx, (%rdx)          # Store quotient counter at the memory location pointed by rdx
    add $8,%rdx               # Move rdx to the next memory location
    mov %rsi, (%rdx)          # Store dividend at the memory location pointed by rdx
    jmp done

ans:
    mov %rcx, (%rdx)          # Store quotient counter at the memory location pointed by rdx
    add $8,%rdx               # Move rdx to the next memory location
    mov %rdi, (%rdx)          # Store dividend at the memory location pointed by rdx
    jmp done

both_negative:
    neg %rdi                  # Negate the dividend (convert negative to positive)
    neg %rsi                  # Negate the divisor (convert negative to positive)
    cmp %rdi,%rsi
    jg ans_both_negative_when_less  # Jump to ans_both_negative_when_less if dividend > divisor
    jmp div

ans_both_negative_when_less:
    mov $1,%rax
    mov %rax,(%rdx)           # Store quotient counter at the memory location pointed by rdx
    add $8,%rdx               # Move rdx to the next memory location
    sub %rdi,%rsi             # Subtract dividend from divisor
    mov %rsi,(%rdx)           # Store result at the memory location pointed by rdx
    ret                       # Return from the function

division_by_zero:
    # handle division by zero error here
    mov $-1,%rax
    mov %rax,(%rdx)           # Store -1 as quotient counter at the memory location pointed by rdx
    add $8,%rdx               # Move rdx to the next memory location
    mov %rax,(%rdx)           # Store -1 as dividend at the memory location pointed by rdx
    ret                       # Return from the function

done:
    ret                       # Return from the function
