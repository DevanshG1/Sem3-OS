global main
extern scanf, printf

section .data
msg: db "Enter the Integer:",10,0
msg2: db "Enter the String:",10,0
fmt1: db "%d",0
fmt2: db "%s",0
fmt3: db "The entered numerical value is: %d ",10,0
fmt4: db "The entered String is: %s",10,0
s times 100 db 0

section .text

main:

push rbp
mov rbp,rsp
sub rsp,16

xor     eax, eax
lea     rdi, [msg]
call    printf

mov     eax, 0
lea     rdi, [fmt1]
lea     rsi, [num]
call    scanf

xor     eax, eax
lea     rdi, [fmt3]
mov     edx, [num]
call    printf

xor     eax, eax
lea     rdi, [msg2]
call    printf

mov     eax, 0
lea     rdi, [fmt2]
lea     rsi, [s]
call    scanf

xor     eax, eax
lea     rdi, [fmt4]
lea     rsi, [s]
call    printf

add rsp, 16
leave
ret

section .bss
num resb 4