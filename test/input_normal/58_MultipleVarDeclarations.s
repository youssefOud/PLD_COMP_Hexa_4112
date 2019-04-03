.text                       # section declaration
.global main                # entry point

main: 
# prologue 
pushq %rbp # save %rbp on the stack 
movq %rsp, %rbp # define %rbp for the current function 
# body 
movq $5, -24(%rbp)
movq -24(%rbp), %rax
movq %rax, -8(%rbp)
movq $6, -32(%rbp)
movq -32(%rbp), %rax
movq %rax, -16(%rbp)
movq -16(%rbp), %rax
imulq -8(%rbp), %rax
movq %rax, -40(%rbp)
movq -40(%rbp), %rax
# epilogue 
popq %rbp # restore %rbp from the stack 
ret # return to the caller (here the shell) 
