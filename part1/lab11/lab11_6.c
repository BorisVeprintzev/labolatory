#include <stdio.h>



int chek(char c)
{
    if ((c >= 'A' && c <= 'F') || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')) {
        return 1;
    } else {
        return 0;
    }
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
    int s;
    long long sum1 = 0;
    long long sum2 = 0;
    long long sum3 = 0;
    int znak1 = 1;
    int znak2 = 1;
    int znak3 = 1;
    int state = 1;
    int n = 0;
    do {
        s = getchar();
        switch (state) {
            case 1:
                if (s == '\n' || s == '\r' || s == EOF) {
                    if (n == 0) {
                        sum1 = 0;
                        sum3 = 0;
                        znak1 = 1;
                        znak3 = 1;
                    } else if (n == 1) {
                        if (znak2 > 0) {
                            printf("%llX\n", sum2);
                        } else {
                            printf("-%llX\n", sum2);
                        }
                        sum1 = 0;
                        sum2 = 0;
                        sum3 = 0;
                        znak1 = 1;
                        znak2 = 1;
                        znak3 = 1;
                        n = 0;
                    } else {
                        if (znak3 > 0) {
                            printf("%llX\n", sum3);
                        } else {
                            printf("-%llX\n", sum3);
                        }
                        sum1 = 0;
                        sum2 = 0;
                        sum3 = 0;
                        znak1 = 1;
                        znak2 = 1;
                        znak3 = 1;
                        n = 0;
                    }
                }
                if (space(s)) {
                    state = 1;
                } else if (chek(s)) {
                    sum1 = v_10(s);
                    state = 2;
                } else if (s == '+' || s == '-') {
                    sum1 = 0;
                    state = 2;
                    if (s == '-') {
                        znak1 = -1;
                    }
                } else {
                    state = 3;
                }
                break;
            case 2:
                if (s == '\n' || s == '\r' || s == EOF) {
                    ++n;
                    if (n == 1) {
                        if (znak2 > 0) {
                            printf("%llX\n", sum2);
                        } else {
                            printf("-%llX\n", sum2);
                        }
                        sum1 = 0;
                        n = 0;
                        sum2 = 0;
                        sum3 = 0;
                        znak1 = 1;
                        znak2 = 1;
                        znak3 = 1;
                    } else {
                        if (znak3 > 0) {
                            printf("%llX\n", sum3);
                        } else {
                            printf("-%llX\n", sum3);
                        }
                        sum1 = 0;
                        sum2 = 0;
                        sum3 = 0;
                        n = 0;
                        znak1 = 1;
                        znak2 = 1;
                        znak3 = 1;
                    }
                }
                if (chek(s)) {
                    sum1 = sum1 * 16 + v_10(s);
                    state = 2;
                } else if (space(s)) {
                    sum3 = sum2;
                    sum2 = sum1;
                    znak3 = znak2;
                    znak2 = znak1;
                    ++n;
                    state = 1;
                    sum1 = 0;
                } else {
                    sum2 = sum1;
                    sum1 = 0;
                    state = 3;
                }
                break;
            case 3:
                if (s == '\n' || s == '\r' || s == EOF) {
                    if (n == 0) {
                        sum1 = 0;
                        sum2 = 0;
                        sum3 = 0;
                        znak1 = 1;
                        znak2 = 1;
                        znak3 = 1;
                    } else if (n == 1) {
                        if (znak2 > 0) {
                            printf("%llX\n", sum2);
                        } else {
                            printf("-%llX\n", sum2);
                        }
                        sum1 = 0;
                        sum2 = 0;
                        sum3 = 0;
                        n = 0;
                        znak1 = 1;
                        znak2 = 1;
                        znak3 = 1;
                    } else {
                        if (znak3 > 0) {
                            printf("%llX\n", sum3);
                        } else {
                            printf("-%llX\n", sum3);
                        }
                        sum1 = 0;
                        sum2 = 0;
                        sum3 = 0;
                        n = 0;
                        znak1 = 1;
                        znak2 = 1;
                        znak3 = 1;
                    }
                }
                if (space(s)) {
                    state = 1;
                } else {
                    state = 3;
                }
                break;
        }

    } while (s != EOF);
    printf("\n");
    return 0;

}