#include <stdio.h>

int chekslovo16(char c)
{
    return (c >= 'A' && c <= 'F') ||
           (c >= '0' && c <= '9') ||
           (c >= 'a' && c <= 'f') ||
           (c == '-');
}


int main(void)
{
    int state = 1;
    int symbol;
    int n = 0;
    char itog;
    int var = 1;
    int qwe = 1;

    while ((symbol = getchar()) != EOF) {
        var = 1;
        switch (state) {
            case 1: //проверка на принадлежность к 16-тичной системе счисления
                if (chekslovo16(symbol)) {
                    state = 1;
                } else (chekslovo16(symbol) && symbol != ' ') {
                    state = 2;
                } else {
                    n++;
                    state = 3;
                }
                break;
            case 2: //если слово не подходит пропускаем
                if (symbol != ' ') {
                    state = 2; 
                } else {
                    state = 3;
                }
                break;
            case 3: //действие после конца слова
                if (symbol == '/n') {
                    if (n == 1) {
                        state = 1;
                        // напечатать первое 16-ное слово в строке и перейти к некст строчке
                        switch (var) {
                            case 1:
                                if (chekslovo16(symbol)) {
                                    var = 1;
                                    itog = itog + symbol;
                                } else (!chekslovo16(symbol) && symbol != ' ') {
                                    var = 2;
                                    itog = 0;
                                } else {
                                    printf("%c/n", itog);
                                    var = 100;
                                    itog = 0;
                                }
                                break;
                            case 2:
                                if (symbol != ' ') {
                                    var = 2;
                                } else {
                                    var = 3;
                                }
                                break;
                            case 3:
                                if (symbol == ' ') {
                                    var = 3;
                                } else {
                                    var = 1;
                                }
                                break;
                            case 100:
                                if (symbol != '/n') {
                                    var = 100;
                                } else {
                                    var = 0;
                                }
                                break;
                        }
                        n = 0
                    } else if (n = 0) {
                        if (symbol != ' '){
                            state = 3;
                        } else {
                            state = 1;
                        }// переход к некст строке
                    } else if (n > 1) {
                        n--;
                        switch (qwe) {
                            case 1:
                                if (chekslovo16(symbol)) {
                                    qwe = 1;
                                    itog = itog + symbol;
                                } else (!chekslovo16(symbol) && symbol != ' ') {
                                    var = 2;
                                    itog = 0;
                                } else {
                                    if (n == 0) {
                                        printf("%c/n");
                                    } else {
                                        n--;
                                    }
                                }
                                break;
                        }// печать предпоследнего слова, переход к некст строчке
                    }
                } else (symbol != '/n') {
                    state = 1;
                }
                break;
        }
    }
    return 0;
}

