#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int chek(char c)
{
    if ((c >= 'A' && c <= 'F') || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')) {
        return 1;
    }
    return 0;
}

int space(int c)
{
    return c == ' ' || c == '\t';
}


int v_10(char s)
{
    if (s >= '0' && s <= '9') {
        return s - '0';
    } else if (s >= 'a' && s <= 'f') {
        return s - 'a' + 10;
    } else {
        return s - 'A' + 10;
    }
}


int main(void)
{
    int num = 0;
    long int sum1 = 0;
    int state = 1;
    int s;
    long int sum2 = 0;
    int znak = 1;
    int znak2 = 1;
    
    do {
        s = getchar();
        switch (state) {
            case 1:
                if (s == '\n' || s == '\r' || s == EOF) {
                    if (num == 0) {
                        sum1 = 0;
                        sum2 = 0;
                    }
                    if (num == 1) {
                        if (znak == 1) {
                            printf("%lX\n", sum1);
                        }
                        if (znak == -1) {
                            printf("-%lX\n", sum1);
                        }
                        sum1 = 0;
                        sum2 = 0;
                    } 
                    if (num >= 2) {
                        if (znak2 == 1) {
                            printf("%lX\n", sum2);
                        }
                        if (znak2 == -1) {
                            printf("-%lX\n", sum2);
                        }
                        sum1 = 0;
                        sum2 = 0;
                    }
                }
                if (s == '+' || s == '-') {
                    state = 2;
                    if (s == '-') {
                        znak = -1;
                    }
                } else if (chek(s)) {
                    sum1 = v_10(s);
                    state = 2;
                } else if (space(s) || s == '\n' || s == '\r') {
                    state = 1;
                } else {
                    state = 3;
                }
                break;
            case 2:
                if (s == '\n' || s == '\r' || s == EOF) {
                    ++num;
                    if (num == 0) {
                        sum1 = 0;
                    }
                    if (num == 1) {
                        if (znak == 1) {
                            printf("%lX\n", sum1);
                        }
                        if (znak == -1) {
                            printf("-%lX\n", sum1);
                        }
                        sum1 = 0;
                        sum2 = 0;
                    } 
                    if (num >= 2) {
                        if (znak2 == 1) {
                            printf("%lX\n", sum2);
                        }
                        if (znak2 == -1) {
                            printf("-%lX\n", sum2);
                        }
                        sum1 = 0;
                        sum2 = 0;
                    }
                }
                if (space(s) || s == '\n' || s == '\r' || s == EOF) {
                    sum2 = sum1;
                    znak2 = znak;
                    ++num;
                    state = 1;
                } else if (chek(s)) {
                    sum1 = sum1 * 16 + v_10(s);
                } else {
                    state = 3;
                }
                break;
            case 3:
                if (s == '\n' || s == '\r' || s == EOF) {
                    state = 1;
                    if (num == 0) {
                        sum1 = 0;
                    }
                    if (num == 1) {
                        if (znak == 1) {
                            printf("%lX\n", sum1);
                        }
                        if (znak == -1){
                            printf("-%lX\n", sum1);
                        }
                        sum1 = 0;
                        sum2 = 0;
                    } 
                    if (num >= 2) {
                        if (znak2 == 1) {
                            printf("%lX\n", sum2);
                        }
                        if (znak2 == -1) {
                            printf("-%lX\n", sum2);
                        }
                        sum1 = 0;
                        sum2 = 0;
                    }
                }
                if (space(s)) {
                    state = 1;
                }
                break;
        }
    } while (s != EOF);
    printf("\n");
    return 0;
}