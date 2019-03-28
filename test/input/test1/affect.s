.text                       # section declaration
.global main                # entry point

main: 
# prologue 
pushq %rbp # save %rbp on the stack 
movq %rsp, %rbp # define %rbp for the current function 
# body 
movq $18, -64(%rbp)
movq $3, -72(%rbp)
movq $2, -80(%rbp)
movq -72(%rbp), %rax
imulq -80(%rbp), %rax
movq %rax, -88(%rbp)
movq -64(%rbp), %rax
addq -88(%rbp), %rax
movq %rax, -96(%rbp)
movq $4, -104(%rbp)
movq -96(%rbp), %rax
subq -104(%rbp), %rax
movq %rax, -112(%rbp)
movq -112(%rbp), %rax
movq %rax, -32(%rbp)
movq $14, -120(%rbp)
movq $2, -128(%rbp)
movq -120(%rbp), %rax
imulq -128(%rbp), %rax
movq %rax, -136(%rbp)
movq -136(%rbp), %rax
movq %rax, -40(%rbp)
movq -40(%rbp), %rax
movq %rax, -32(%rbp)
movq $12, -144(%rbp)
movq $5, -152(%rbp)
movq -144(%rbp), %rax
subq -152(%rbp), %rax
movq %rax, -160(%rbp)
movq -160(%rbp), %rax
movq %rax, -8(%rbp)
movq -56(%rbp), %rax
movq %rax, -48(%rbp)
movq -48(%rbp), %rax
movq %rax, -40(%rbp)
movq -8(%rbp), %rax
movq %rax, -48(%rbp)
movq $3, -168(%rbp)
movq $9, -176(%rbp)
movq -168(%rbp), %rax
addq -176(%rbp), %rax
movq %rax, -184(%rbp)
movq $2, -192(%rbp)
movq -184(%rbp), %rax
imulq -192(%rbp), %rax
movq %rax, -200(%rbp)
movq -200(%rbp), %rax
# epilogue 
popq %rbp # restore %rbp from the stack 
ret # return to the caller (here the shell) 

