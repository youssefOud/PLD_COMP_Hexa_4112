.text                       # section declaration
.global main                # entry point

main: 
# prologue 
pushq %rbp # save %rbp on the stack 
movq %rsp, %rbp # define %rbp for the current function 
# body 
movq $1, -16(%rbp)
movq $2, -24(%rbp)
movq $4, -32(%rbp)
movq -24(%rbp), %rax
imulq -32(%rbp), %rax
movq %rax, -40(%rbp)
movq -16(%rbp), %rax
addq -40(%rbp), %rax
movq %rax, -48(%rbp)
movq $2, -56(%rbp)
movq $4, -64(%rbp)
movq $3, -72(%rbp)
movq $2, -80(%rbp)
movq -72(%rbp), %rax
imulq -80(%rbp), %rax
movq %rax, -88(%rbp)
movq -64(%rbp), %rax
addq -88(%rbp), %rax
movq %rax, -96(%rbp)
movq $2, -104(%rbp)
movq -96(%rbp), %rax
subq -104(%rbp), %rax
movq %rax, -112(%rbp)
movq -56(%rbp), %rax
imulq -112(%rbp), %rax
movq %rax, -120(%rbp)
movq -48(%rbp), %rax
subq -120(%rbp), %rax
movq %rax, -128(%rbp)
movq -128(%rbp), %rax
movq %rax, -8(%rbp)
movq -8(%rbp), %rax
# epilogue 
popq %rbp # restore %rbp from the stack 
ret # return to the caller (here the shell) 

