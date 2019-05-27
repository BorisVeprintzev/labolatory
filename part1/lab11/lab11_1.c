#include <stdio.h>

 

int chek(int c)
{
    if ((c >= 'A' && c <= 'F') || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c == '-')) {
        return 1;
    }
    return 0;
}

int space(int c)
{
    return c == ' ' || c == '\t' || c == EOF;
}

int v_10(int c)
{
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'f') {
        return c - 'W';
    } else if (c >= 'A' && c <= 'F') {
        return  c - '7';
    } else {
        return 0;
    }
}



int main(void)
{
    int num = 0;
    long s;
    int state = 1;
    long sum;
    int var1 = 1;
    int var2 = 2;

    do {
        s = getchar();
        switch (state) {
            case 1:
                if (chek(s)) {
                    state = 1;
                } else if (!space(s)) {
                    state = 2;
                } else if (s == '\n' || s == '\r') {
                    if (num == 0) {
                        state = 1;
                    } else if (num == 1) {
                        switch (var1) {
                            case 1:
                                if (chek(s)) {
                                    if (s == '-') {
                                        sum = -1;
                                    }
                                    if (sum < 0) {
                                        sum = sum * 10 - v_10(s);
                                    } else {
                                        sum = sum * 10 + v_10(s);
                                    }
                                } else if (!space(s) || s != '\n' || s != '\r') {
                                    sum = 0;
                                    var1 = 2;
                                } else {
                                    printf("%lX\n", sum);
                                    var1 = 3;
                                }
                                break;
                            case 2:
                                if (!space(s) || s != '\n' || s != '\r') {
                                    var1 = 2;
                                } else {
                                    var1 = 1;
                                }
                                break;
                            case 3:
                                if (s != '\n' || s != '\r') {
                                    var1 = 3;
                                } else {
                                    var1 = 1;
                                }
                                break;
                        }
                    } else {
                        switch (var2) {
                            case 1:
                                if (chek(s)) {
                                    var2 = 1;
                                    sum = sum + v_10(s);
                                } else if (!space(s) || s != '\n' || s != '\r') {
                                    var2 = 2;
                                } else {
                                    --num;
                                    if (num == 0) {
                                        printf("%lX\n", sum);
                                        var2 = 3;
                                    } else {
                                        var2 = 1;
                                        sum = 0;
                                    }
                                }
                                break;
                            case 2:
                                if (!space(s) || s != '\n' || s != '\r') {
                                    var2 = 2;
                                } else {
                                    var2 = 1;
                                }
                                break;
                            case 3:
                                if (s != '\n' || s != '\r') {
                                    var2 = 3;
                                } else {
                                    var2 = 1;
                                }
                                break;
                        }
                    }
                } else {
                    ++num;
                    state = 3;
                }
                break;
            case 2:
                if (!space(s)) {
                    state = 2;
                } else if (s == '\n' || s == '\r') {
                    state = 1;
                } else {
                    state = 3;
                }
                break;
            case 3:
                if (chek(s)) {
                    state = 1;
                    sum = v_10(s);
                } else if (!space(s) || s != '\n' || s != '\r') {
                    state = 2;
                } else {
                    state = 3;
                }
                break;
        }

    } while (s != EOF);
    return 0;
}
