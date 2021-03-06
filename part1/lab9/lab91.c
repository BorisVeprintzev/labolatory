#include <stdio.h>
#include <math.h>


int max1(int i, int j, int k)
{
    int x;
    if (i * (k + 5) >= j * (k + 6)) {
        x = i * (k + 5);
    } else {
        x = j * (k + 6);
    }
    return x;
}

int min1(int j, int l, int k)
{
    if (j * (k + 7) >= l * (k + 8)) {
        return l * (k - 8);
    } else {
        return j * (k + 7);
    }
}

int module1(int res)
{
    if (res >= 0) {
        return res;
    } else {
        return -1 * res;
    }
}

int sign(int i, int j)
{
    if (i > j) {
        return 1;
    }
    if (i == j) {
        return 0;
    } else {
        return -1;
    }
}

int min2(int i, int j, int l)
{
    if (i * l + 5 >= j * l - 3) {
        if (j * l - 3 >= i * j + 6) {
            return i * j + 6;
        } else {
            return j * l - 3;
        }
    } else {
        if (i * l + 5 >= i * j + 6) {
            return i * j + 6;
        } else {
            return i * l + 5;
        }
    }
}

int in_a_area(int i, int j)
{
    if ((i >= 5) && (j >= -15) && (i <= 15) && (j <= -5)) {
        return 1;
    } else {
        return 0;
    }
}

int mod(int x, int y)
{
    if (x % y < 0) {
        return x % y + y;
    } else {
        return x % y;
    }
}

int l_result(int i, int j, int l)
{
    int i1, j1, l1;
    i1 = mod(i, 10);
    j1 = mod(j, 10);
    l1 = mod(l, 10);
    return i1 + j1 + l1;
}

int main(void)
{
    int i, j, l, k, in, jn, ln;
    scanf("%d %d %d", &i, &j, &l);

    for (k = 0; !in_a_area(i, j) && k < 50; k++) {
        in = mod((module1(max1(i, j, k)) - module1(min1(j, l, k))), 20);
        jn = (3 - sign(i, j)) * mod(module1(min2(i, j, l)), 25) - 7;
        ln = l_result(i, j, l);
        i = in;
        j = jn;
        l = ln;
    }

    printf("%s\n", in_a_area(i, j) ? "Yes" : "No");
    printf("%d %d %d %d\n", i, j, l, k);

    return 0;
}

