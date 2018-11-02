#include <stdio.h>
union {
 int i;
 short s[2];
 unsigned char c[4];
} u;
int main()
{
 int s0, s1;
 u.i = 0xbadbabe;
 s0 = (int) u.s[0];
 s1 = (int) u.s[1];
 printf("sizeof(int)=%d, sizeof(short)=%d, sizeof(char)=%d\n",
 sizeof(int), sizeof(short), sizeof(char));
 printf("sizeof(u.i)=%d\n", sizeof(u.i));
 printf("sizeof(u.s)=%d, sizeof(u.s[0])=%d\n", sizeof(u.s), sizeof(u.s[0]));
 printf("sizeof(u.c)=%d, sizeof(u.c[0])=%d\n", sizeof(u.c), sizeof(u.c[0]));
 printf("sizeof(u)=%d\n", sizeof(u));
 printf("s0=0x%x, s1=0x%x\n", s0, s1);
 printf("u.c=0x%x 0x%x 0x%x 0x%x\n", u.c[0],u.c[1],u.c[2],u.c[3]);
}
