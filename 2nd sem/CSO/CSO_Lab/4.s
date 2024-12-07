.global gcd

gcd:
    movq $0,%rdx
    movq %rdi,%rax
    movq %rsi,%r10
    idivq %r10
    cmp $0,%rdx
    je end
    movq %rsi,%rdi
    movq %rdx,%rsi
    call gcd
    ret

end:
    movq %rsi,%rax
    ret
