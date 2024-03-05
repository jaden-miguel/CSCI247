#include <stdio.h>

// this was hard as hell, 35+ hours on all 3 programs

int aFunction(int var) {
    var++;

    return var;
}

int main() {
    int x = 0;
    int y = 0;
    

    while (y <= 0x21) {
        x = aFunction(x);
        y++;
    }


    return 0;
}



/*
Dump of assembler code for function main:
   0x0000555555554608 <+0>:     push   %rbp
   0x0000555555554609 <+1>:     mov    %rsp,%rbp
   0x000055555555460c <+4>:     sub    $0x20,%rsp
   0x0000555555554610 <+8>:     mov    %edi,-0x14(%rbp)
   0x0000555555554613 <+11>:    mov    %rsi,-0x20(%rbp)
=> 0x0000555555554617 <+15>:    movl   $0x0,-0x8(%rbp)
   0x000055555555461e <+22>:    movl   $0x0,-0x4(%rbp)
   0x0000555555554625 <+29>:    jmp    0x555555554638 <main+48>
   0x0000555555554627 <+31>:    mov    -0x4(%rbp),%eax
   0x000055555555462a <+34>:    mov    %eax,%edi
   0x000055555555462c <+36>:    callq  0x5555555545fa <aFunction>
   0x0000555555554631 <+41>:    add    %eax,-0x8(%rbp)
   0x0000555555554634 <+44>:    addl   $0x1,-0x4(%rbp)
   0x0000555555554638 <+48>:    cmpl   $0x21,-0x4(%rbp)
   0x000055555555463c <+52>:    jle    0x555555554627 <main+31>
   0x000055555555463e <+54>:    mov    $0x0,%eax
   0x0000555555554643 <+59>:    leaveq 
   0x0000555555554644 <+60>:    retq   
End of assembler dump.
*/


//bruh