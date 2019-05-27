#include <stdio.h>

int main(void)
{
    int a, b;
    b = 0;
    scanf("%d", &a);
    while (a > 0) {
        
        int x;
        scanf("%d", &x);
        if (x >= 10) {
            
            b = b + x;
        }
        a--;
    }
    
    printf("%d\n", b);
    
    return 0;

}
