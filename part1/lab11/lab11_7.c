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
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == EOF;
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
    long long value = 0, lastvalue = 0, prelastvalue = 0;
    int signvalue = 1, len = 0, label = 0, state = 1, s, lastsignvalue = 0, prelastsignvalue = 0, prelastlen = 0, lastlen = 0;
    do {
        s = getchar();
        switch (state) {
            case 1:
                if (s == '+' || s == '-') {
                    if (s == '+') {
                        signvalue = 1;
                    } else {
                        signvalue = -1;
                    }
                    len = 0;
                    value = 0;
                    state = 2;
                } else if (chek(s)) {
                    len = 1;
                    value = v_10(s);
                    state = 2;
                } else if (!space(s)) {
                    state = 3;
                } else if (s == '\n' || s == '\r' || s == EOF) {
                    if (label == 1) {
                        printf("%0*llX\n", lastlen, lastvalue * lastsignvalue);
                        label = 0;
                        signvalue = 1;
                    } else if (label >= 2) {
                        printf("%0*llX\n", prelastlen, prelastvalue * prelastsignvalue);
                        label = 0;
                        signvalue = 1;
                    }
                }
                break;
            case 2:
                if (chek(s)) {
                    value = value * 16 + v_10(s);
                    ++len;
                } else if (space(s)) {
                    if (len > 0) {
                        if (label == 0) {
                            lastsignvalue = signvalue;
                            lastvalue = value;
                            lastlen = len;
                            ++label;
                        } else if (label > 0) {
                            prelastsignvalue = lastsignvalue;
                            prelastvalue = lastvalue;
                            prelastlen = lastlen;
                            lastsignvalue = signvalue;
                            lastvalue = value;
                            lastlen = len;
                            ++label;
                        }
                    }
                    if (s == '\n' || s == '\r' || s == EOF) {
                        if (label == 1) {
                            printf("%0*llX\n", lastlen, lastvalue * lastsignvalue);
                            label = 0;
                            signvalue = 1;
                        } else if (label >= 2) {
                            printf("%0*llX\n", prelastlen, prelastvalue * prelastsignvalue);
                            label = 0;
                            signvalue = 1;
                        }
                    }
                    signvalue = 1;
                    state = 1;
                } else {
                    signvalue = 1;
                    state = 3;
                }
                break;
            case 3:
                if (space(s)) {
                    state = 1;
                    if (s == '\n' || s == '\r' || s == EOF) {
                        if (label == 1) {
                            printf("%0*llX\n", lastlen, lastvalue * lastsignvalue);
                            label = 0;
                            signvalue = 1;
                        } else if (label >= 2) {
                            printf("%0*llX\n", prelastlen, prelastvalue * prelastsignvalue);
                            label = 0;
                            signvalue = 1;
                        }
                    }
                }
                break;
        }
    } while (s != EOF);
    printf("\n");
    return 0;
}