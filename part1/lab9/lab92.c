#include <stdio.h>

int mod(int x, int y)
{
    if (x % y < 0) {
        return x % y + y;
    } else {
        return x % y;
    }
}

int min(int x, int y)
{
    if (x >= y) {
        return x;
    } else {
        return y;
    }
}

int sign(int l)
{
    if (l > 0) {
        return 1;
    }
    if (l == 0) {
        return 0;
    } else {
        return -1;
    }
}

int module(int x)
{
    if (x >= 0) {
        return x;
    } else {
        return -1 * x;
    }
}

int i_res(int i, int j, int l, int k)
{
    return mod((i + j + l) * (k + 1), 25) - mod(i * j * l * (k + 2), 10) + 10;
}

int j_res(int i, int j, int l, int k)
{
    return min(mod((i + j + l) * (k + 3), 25), mod(i * j * l * (k + 4), 25))+ 10;
}

int l_res(int i, int j, int l, int k)
{
    return 2 * sign(l) * module(mod((i + j + l) * (k + 5), 10) - mod(i * j * l * (k + 6), 25));
}

int in_a_area(int i, int j)
{
    if ((i >= 5) && (j >= -15) && (i <= 15) && (j <= -5)) {
        return 1;
    } else {
        return 0;
    }
}

int main(void)
{
    int i, j, l, k, in, jn, ln;
    scanf("%d %d %d", &i, &j, &l);
    for (k = 0; !in_a_area(i, j) && k < 50; k++) {
        in = i_res(i, j, l, k);
        jn = j_res(i, j, l, k);
        ln = l_res(i, j, l, k);
        i = in;
        j = jn;
        l = ln;
    }
    printf("%s\n", in_a_area(i, j) ? "Yes" : "No");
    printf("%d %d %d %d\n", i, j, l, k);

    return 0;
}