#include <stdio.h>

int main() {
   int value;

   printf("Enter a value: ");
   value = getchar();
   
   int second = value;
   int third = second + 0x2fd;

   int result = (float)third;

   return result;
}


/*
Dump of assembler code for function main:
   0x000055555555468a <+0>:     push   %rbp
   0x000055555555468b <+1>:     mov    %rsp,%rbp
=> 0x000055555555468e <+4>:     sub    $0x20,%rsp
   0x0000555555554692 <+8>:     mov    %edi,-0x14(%rbp)
   0x0000555555554695 <+11>:    mov    %rsi,-0x20(%rbp)
   0x0000555555554699 <+15>:    lea    0xc4(%rip),%rdi        # 0x555555554764
   0x00005555555546a0 <+22>:    mov    $0x0,%eax
   0x00005555555546a5 <+27>:    callq  0x555555554550 <printf@plt>
   0x00005555555546aa <+32>:    callq  0x555555554560 <getchar@plt>
   0x00005555555546af <+37>:    mov    %eax,-0x10(%rbp)
   0x00005555555546b2 <+40>:    mov    -0x10(%rbp),%eax
   0x00005555555546b5 <+43>:    mov    %eax,-0xc(%rbp)
   0x00005555555546b8 <+46>:    mov    -0xc(%rbp),%eax
   0x00005555555546bb <+49>:    add    $0x2fd,%eax
   0x00005555555546c0 <+54>:    mov    %eax,-0x8(%rbp)
---Type <return> to continue, or q <return> to quit---
   0x00005555555546c3 <+57>:    cvtsi2ssl -0x8(%rbp),%xmm0
   0x00005555555546c8 <+62>:    movss  %xmm0,-0x4(%rbp)
   0x00005555555546cd <+67>:    mov    $0x0,%eax
   0x00005555555546d2 <+72>:    leaveq 
   0x00005555555546d3 <+73>:    retq 
*/