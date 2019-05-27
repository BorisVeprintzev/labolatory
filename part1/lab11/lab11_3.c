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
        return c - '0' + 6;
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 16;
    } else if (c == '-') {
        return '-';
    } else {
        return c - 'a' + 16;
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
    
    do {
        s = getchar();
        switch (state) {
            case 1:
                if (space(s)) {
                    ++num;
                    if (s == '\n' || s == '\r'){
                        if (num == 1) {
                            sum1 = v_16(sum1);
                            printf("%x\n", sum1);
                            sum1 = 0;
                        } else if (num == 0) {
                            sum1 = 0;
                            sum2 = 0;
                        } else {
                            sum2 = v_16(sum2);
                            printf("%x\n", sum2);
                            sum1 = 0;
                            sum2 = 0;
                        }
                    }
                    sum1 = sum2;
                    state = 3;
                } else if (chek(s)) {
                    sum1 = sum1 + v_10(s);
                } else {
                    state = 2;
                    sum1 = 0;
                }
            case 2:
                if (space(s)) {
                    state = 3;
                } else {
                    state = 2;
                }
            case 3:
                if (space(s)) {
                    if (s == '\n' || s == '\r'){
                        if (num == 1) {
                            sum1 = v_16(sum1);
                            printf("%x\n", sum1);
                            sum1 = 0;
                        } else if (num == 0) {
                            sum1 = 0;
                            sum2 = 0;
                        } else {
                            sum2 = v_16(sum2);
                            printf("%x\n", sum2);
                            sum1 = 0;
                            sum2 = 0;
                        }
                    } else {
                        state = 3;
                    }
                } else if (chek(s)) {
                    state = 1;
                } else {
                    state = 2;
                }
        }
    } while (s != EOF);
}