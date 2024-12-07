.global get_product_assembly

get_product_assembly:
    mov $0,%r10           # Initialize r10 register to store the product
    add (%rdi),%r10      # Add the value at the current memory location to r10
    mov $1,%r8           # Initialize r8 register to track the current iteration

loop_start:
    cmp $10,%r8          # Compare r8 with 10 (maximum number of iterations)
    je done              # Jump to done if r8 is equal to 10

    add $1,%r8           # Increment r8 by 1 (iteration counter)
    add $8,%rdi          # Move the pointer to the next memory location
    mov (%rdi),%rdi      # Store the value at the current memory location in rdi
    imul (%rdi),%r10     # Multiply the value in rdi with the current product in r10

    jmp loop_start       # Jump back to loop_start for the next iteration

done:
    mov %r10,%rax        # Move the final product from r10 to rax register
    ret                  # Return from the get_product_assembly function
    