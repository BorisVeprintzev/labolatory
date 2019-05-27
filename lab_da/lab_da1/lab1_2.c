#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 

typedef struct $
{
    int first;
    int second;
    int third;
    int number;
    unsigned long long int value;
}pare;

int max_number(int *data, int number) {
    int max = 0;
    for (int i = 0; i < number; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}


long int power(int t, int k) // возведение t в степень k
{
  long int res = 1;
  while (k) 
      {
        if (k & 1) 
            res *= t;
    t *= t;
    k >>= 1;
      }
  return res;
}


void counting_sort(pare* data_full, int number, int number_elem)
{
    int data_for_sort[number_elem];
    pare result[number_elem];
    switch (number) {
        case 0:
            for (int i = 0; i < number_elem; ++i)
            {
                data_for_sort[i] = data_full[i].third;
            }
            break;
        case 1:
            for (int i = 0; i < number_elem; ++i)
            {
                data_for_sort[i] = data_full[i].second;
            }
            break;
        case 2:
            for (int i = 0; i < number_elem; ++i)
            {
                data_for_sort[i] = data_full[i].number;
            }
            break;
        case 3:
            for (int i = 0; i < number_elem; ++i)
            {
                data_for_sort[i] = data_full[i].first;
            }
            break;
    }
    int max = max_number(data_for_sort, number_elem);
    int templorary[max + 1];
    for (int i = 0; i < max + 1; ++i) {
        templorary[i] = 0;
    }
    for (int i = 0; i < number_elem; ++i) {
        ++templorary[data_for_sort[i]];
    }
    for (int i = 1; i < max + 1; ++i) {
        templorary[i] += templorary[i - 1];
    }
    for (int i = number_elem - 1; i >= 0; --i) {
        result[templorary[data_for_sort[i]] - 1] = data_full[i];
        --templorary[data_for_sort[i]];
    }
    for (int i = 0; i < number_elem; ++i)
    {
        data_full[i] = result[i];
    }
}

void print(pare* result, int number_of_elem)
{
    for (int i = 0; i < number_of_elem; ++i) {
        printf("%c %03d %c%c\t", result[i].first, result[i].number, result[i].second, result[i].third);
        printf("%llu\n", result[i].value);
    }
    return;
}

int main() {
//    clock_t begin = clock();
    int number_of_elem = 0;
    pare* all = malloc(sizeof(pare) * 40);
    int capacity = 40;
    int k;
    k = getchar();
    while (k == '\n'){
        k = getchar();
    }
    while (k != EOF) {
        all[number_of_elem].first = k;
        k = getchar();
        scanf("%d", &all[number_of_elem].number);
        k = getchar();
        all[number_of_elem].second = getchar();
        all[number_of_elem].third = getchar();
        scanf("%llu", &all[number_of_elem].value);
        ++number_of_elem;
        if (number_of_elem == capacity) {
            all = realloc(all, sizeof(pare) * capacity * 2);
            capacity *= 2;
        }
        k = getchar();
        if (k == EOF) break;
        k = getchar();
    }
    all = realloc(all, sizeof(pare) * number_of_elem);
    for (int i = 0; i < 4; ++i) {
        counting_sort(all, i, number_of_elem);
    }
    print(all, number_of_elem);
    free(all);
   /*    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf\n", time_spent);
    */ 
    return 0;
}
