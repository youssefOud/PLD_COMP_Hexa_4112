.text                       # section declaration
.global main                # entry point

main: 
# prologue 
pushq %rbp # save %rbp on the stack 
movq %rsp, %rbp # define %rbp for the current function 
# body 
movl $18, -16(%rbp)
movl $14, -24(%rbp)
movl -24(%rbp), %eax
movl %eax, -16(%rbp)
movl $12, -8(%rbp)
movl -40(%rbp), %eax
movl %eax, -32(%rbp)
movl -32(%rbp), %eax
movl %eax, -24(%rbp)
movl -8(%rbp), %eax
movl %eax, -32(%rbp)
movl -16(%rbp), %eax
# epilogue 
popq %rbp # restore %rbp from the stack 
ret # return to the caller (here the shell) 

