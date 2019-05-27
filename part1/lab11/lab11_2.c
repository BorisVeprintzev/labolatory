#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int chek(char c)
{
    if ((c >= 'A' && c <= 'F') || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c == '-')) {
        return 1;
    }
    return 0;
}

int space(int c)
{
    return c == ' ' || c == '\t' || c == EOF || c == '\n' || c == '\r' ;
}

int v_16(char c)
{
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' - 10;
    } else if (c == '-') {
        return '-';
    } else {
        return c - 'a' - 10;
    }
}

int v_10(int c)
{
    int f;
    int r = 0;
    if (abs(c) > 16) {
        while (abs(c) > 16) {
            f = abs(c) % 16;
            c = c / 16;
            r = r + f;
        }
        return r;
    } else {
        return c;
    }
}


int main(void)
{
    int num = 0;
    int sum1 = 0;
    int state = 1;
    int s;
    int sum2 = 0;
    int sum3 = 0;
    
    do {
        s = getchar();
        switch (state) {
            case 1:
                if (chek(s)) {
                    state = 1;
                    sum1 = sum1 + v_10(s);
                } else if (space(s)) {
                    sum3 = sum2;
                    sum2 = sum1;
                    sum1 = 0;
                    ++num;
                    state = 3;
                } else {
                    state = 2;
                }
                break;
            case 2:
                sum1 = 0;
                if (space(s)) {
                    state = 3;
                } else {
                    state = 2;
                }
                break;
            case 3:
                if (s == '\n' || s == '\r') {
                    state = 1;
                    if (num == 0) {
                        sum1 = 0;
                        sum2 = 0;
                    } else if (num == 1) {
                        sum2 = v_16(sum2);
                        printf("%x\n", sum2);
                        sum1 = 0;
                        sum2 = 0;
                        sum3 = 0;
                    } else {
                        sum3 = v_16(sum3);
                        printf("%x\n", sum3);
                        sum1 = 0;
                        sum2 = 0;
                        sum3 = 0;
                    }
                } else if (chek(s)) {
                    state = 1;
                } else if (s == EOF || s == ' ' || s == '\t') {
                    state = 3;
                } else {
                    state = 2;
                }
                break;
        }
    } while (s != EOF);
    return 0;
}
