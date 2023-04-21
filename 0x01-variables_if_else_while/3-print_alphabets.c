#include <stdio.h>
  
int main()
{
  

    char ch;
    int i;
    for(i=0;i<=25; i++){
    ch = 'a' + i;
    putchar(ch);
    }
    for(i=0;i<=25; i++){
    ch = 'A' + i;
    putchar(ch);
    }
    putchar('\n');
    return (0);
}

