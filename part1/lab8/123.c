#include <stdio.h>

int main(void)
{
    int a, b;
    b = 0;
    scanf("%d", &a);
    while (a > 0) {
        
        int x;
        scanf("%d", &x);
        a--;
        b = b + x;
    }
    
    printf("%d\n", b);
    return 0;

}
