#include <stdio.h>

int min(int a, int b)
{
    if (a < b) {
        return a;
    }
    return b;
}

int module(int x)
{
    if (x >= 0) {
        return x;
    }
    return -1 * x;
}

int max(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

int mod(int a, int b)
{
    int c;
    c = a % b;
    if (c < 0) {
        c = c + b;
    }
    return c;
}

int my_div(int x, int y)
{
    return (x - mod(x, y)) / y;
}

int ires(int i, int j, int l, int k)
{
    return module(k - 15) - min(my_div(i, 3), mod((j + l), 10)) - 20;
}

int jres(int i, int j, int l, int k)
{
    return -1 * my_div(j + k, 5) + module(mod(i * l, 8));
}

int lres(int i, int j, int l, int k)
{
    return max(mod(i + j, 15), mod((l + k), 14));
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
        in = ires(i, j, l, k);
        jn = jres(i, j, l, k);
        ln = lres(i, j, l, k);
        i = in;
        j = jn;
        l = ln;
    }

    printf("%s\n", in_a_area(i, j) ? "Yes" : "No");
    printf("%d %d %d %d\n", i, j, l, k);

    return 0;
}
