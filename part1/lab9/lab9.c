#include <stdio.h>
#include <math.h>




int main()
{
    int i, j, l, k, i1, j11, l1, i2, j2, l2;
    scanf ("%d,%d,%d", &i, &j, &l);
    k = 0;
    if (k <= 50){
        k++;

        i1 = (i % 10 + 10) % 10;
        j11 = (j % 10 + 10) % 10;
        l1 = (l % 10 + 10) % 10;
        i2 = i;
        j2 = j;
        l2 = l;
        max1 (i, j, k);
        mod20 (i);
        mod25 (j);
        min1 (j2, l2, )
        l = i1 + j11 + l1;
        while ((i >= 5) && (j >= -15) && (i <= 15) && (j <= -5)){
        printf ("Yes");
        printf ("%d%d%d", i, j, l);
        return 0;
        }
    }    
    else{
        printf ("No");
        printf ("%d%d%d", i, j, l); 
        return 0;
    }
    return 0;
        
}

int max1 (int resmax1)
{
    
    if (i * (k + 5) >= j * (k + 6)){
        resmax1 = i * (k + 5);
    }
    else{
        resmax1 = j * (k + 6);
    }
    return
}


int min1 ()
{
    if (j2 * (k + 7) >= l2 * (k + 8)){
        return j2 * (k + 7);
    }
    else{
        return l2 * (k + 8);
    }
}


int module1 (int max1)
{
    if (max1 >= 0){
        return max1;
    }
    else{
        return -max1;
    }
}


int module2 (int min1)
{
    if (min1 >= 0){
        return min1;
    }
    else{
        return -min1;
    }
}

int sign (int i, int j)
{
    if (i - j > 0){
        return 1;
    }
    else (i - j == 0){
        return 0;
    }
    else{
        return -1;
    }
}

int min2 (int j, int l, int i)
{
    if (i * l + 5 >= i * j - 3){
        if (j * l - 3 >= i * j + 6){
            return i * j + 6;
        }
        else{
            return j * l - 3;
        }
    }
    else{
        if (i * l + 5 >= i * j + 6){
            return i * j + 6;
        }
        else{
            return i * l + 5;
        }
    }
}

int module3 (int min2)
{
    if (min2 >= 0){
        return min2;
    }
    else{
        return -min2;
    }
}

int mod20 (int module1, int module2, int h)
{
    h = module1 - module2;
    return ((h % 20) + 20) % 20; 
}

int mod25 (int min2, int sign, int j1, int sup)
{
    int sup = 3 - sign;
    j1 = sup * module3;
    return ((j1 % 25) + 25) % 20 - 7;
}

