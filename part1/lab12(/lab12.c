#include <stdio.h>


int main(void)
{
    long long number;
    int dlina = 0;
    while (scanf("%lld", &number) == 1) {
        long long sign_value = 1;
        if (number < 0) {
            sign_value = -1;
            number *= -1;
        }
        int capacity = 1;
        int ans = 0;

        while (number >= 10) {
            number = number / 10;
            ans += (number % 10) * capacity;
            capacity *= 10;
            number = number / 10;
            ++dlina;
        }
        if (sign_value == -1) {
            ++dlina;
        }
        printf("%0*lld\n", dlina, ans * sign_value);
        dlina = 0;
    }
    return 0;
}