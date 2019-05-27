#include <iostream>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>

struct vertex {
    //список выходящих из вершины значений
    //int next[11];
    std::map<unsigned int, size_t> child;
    //конец ли слова
    bool leaf;
    //parent
    int p;
    //по какому значению мы пришли сюда из отца
    int pch;
    // суффиксная ссылка
    int link;
    // куда двигаться
    //int go[11];
    std::map<unsigned int, size_t> go;
    // номер образца
    int number_of_word;
    // длина образца
    size_t lenght;
    int link_exit;
};

int sz;
int num = 0;

void init(std::vector<vertex>& t) {
    /*
    t.resize(10);
    t[0].p = t[0].link = t[0].link_exit = -1;
    */
    t.reserve(20000);
    vertex tmp;
    tmp.p = tmp.link = tmp.link_exit = -1;
    t.push_back(tmp);
    sz = 1;
}

void add(std::vector<unsigned int>& sample, std::vector<vertex>& t)
{
    // начинаем обход древа с нулевого элемента - корня
    int v = 0;
    vertex tmp;
    // идем по одной цифре добавляемого числа
    for (size_t i = 0; i < sample.size(); ++i) {
        // если данная цифра отсутствует
        if (t[v].child.find(sample[i]) == t[v].child.end()) {
            tmp.link = tmp.link_exit = -1;
            tmp.p = v;
            tmp.pch = sample[i];
            tmp.leaf = false;
            t.push_back(tmp);
            // выделяем место в памяти для массива
            //memset(t[sz].next, 255, sizeof t[sz].next);
            // указывающие на следующие числа и переходы
            //memset(t[sz].go, 255, sizeof t[sz].go);
            // инициализируем суффиксальную ссылку
            //t[sz].link = -1;
            //t[sz].link_exit = -1;
            // запаминаем из какого элемента идем
            //t[sz].p = v;
            // из какого элемента предка идет в сторону текущего элемента
            //t[sz].pch = sample[i];
            // записываем номер ячейки в предке по которому мы сможем найти текущий элемент
            t[v].child[sample[i]] = sz++;
            //t[v].leaf = false;
        }
        // переходим к следующему элементу
        v = t[v].child[sample[i]];
    }
    // конец "слова"
    t[v].leaf = true;
    ++num;
    t[v].number_of_word = num;
    t[v].lenght = sample.size();
}

int go(std::vector<vertex>& t, int pos, unsigned int next);

int get_link(std::vector<vertex>& t, int v)
{
    //printf("a\n");
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0) {
            t[v].link = 0;
        } else {
            t[v].link = go(t, get_link (t, t[v].p), t[v].pch);
        }
    }
    return t[v].link;
}

int go(std::vector<vertex>& t, int pos, unsigned int next)
{
    //printf("b\n");
    if (t[pos].go.find(next) == t[pos].go.end()) {
        if (t[pos].child.find(next) != t[pos].child.end()) {
            t[pos].go[next] = t[pos].child[next];
        } else {
            t[pos].go[next] = (pos == 0 ? 0 : go(t, get_link(t, pos), next));
        }
    }
    return t[pos].go[next];
}

int link_exit(std::vector<vertex>& t, int v)
{
    if (t[v].link_exit == -1) {
        int a = get_link(t, v);
        while (a != 0) {
            if (t[a].leaf == true) {
                t[v].link_exit = a;
                return t[v].link_exit;
            }
            a = get_link(t, a);
        }
        t[v].link_exit = 0; 
    }
    return t[v].link_exit;
}

int read_samples(std::vector<vertex>& t)
{
	// место куда записываем образец
    std::vector<unsigned int> sample;
    // слово
    unsigned int word;
    // знак после слова
    char symbol;
    // максимальный размер образца
    int max = 0;
    // для строки и всех образцов
    bool status1 = true, status2 = true;
    //все образцы
    while (status1 == true) {
        // каждый по отдельности
        while (status2 == true) {
        	// считываем слово и символ после
            scanf("%u%c", &word, &symbol);
            // заносим в образец слово
            sample.push_back(word);
            // если перевод строки
            while (symbol == ' ') {
                symbol = getchar();
            }
            if (symbol == '\n') {
                /*
                for (int i = 0; i < sample.size(); ++i) {
                    std::cout << sample[i] << " ";
                }
                */
                // выходим из цикла считывания 1-ого образца
                status2 = false;
                // добавляем его в бор
                add(sample, t);
                // если его размер максимален, записываем его длину в max
                if (max < sample.size())
                {
                    max = sample.size();
                }
                // отчищаем вектор для данного образца
                sample.clear();
            } else {
                ungetc(symbol, stdin);
            }
        }
        // считываем сивмол для того чтоб понять не является ли это концом образцов
        symbol = getchar();
        if (symbol == EOF) {
            max = 0;
            status1 = false;
        } else if (symbol == '\n') {
            status1 = false;
        } 
        // если нет, то возращаем символ в строку
        else {
            ungetc(symbol, stdin);
            status2 = true;
        }
    }
    return max;
}

struct text
{
    int line;
    int begin_in_line;
};

void read_text_and_answer(std::vector<vertex>& t, int max)
{   
    // куда будем заносить параметры слов
    // размер max потому что длинее смысла хранить нету, т.к. это максимальная длина образца
    text *te = new text [max];
    // для считывания слова
    unsigned int word;
    // для считывания символа после
    char symbol;
    // для определения места в te
    int a;
    // для сохранения характеристик текста
    // номер линии, номер слова в строке, текущая позиция в боре
    // текущая позиция в te, суффиксная ссылка
    int line = 1, number_word = 0, pos_bor = 0, curr_pos = 0, link;
    // для выхода из цикла 
    bool status = true;
    // для пропуска строк перед текстом
    symbol = getchar();
    while (symbol == '\n') {
        symbol = getchar();
    }
    if (symbol == EOF) {
        status = false;
    } else {
        ungetc(symbol, stdin);
    }
    // сам процесс считывания и поиска
    while (status == true) {
        scanf("%u%c", &word, &symbol);
        pos_bor = go(t, pos_bor, word);
        ++number_word;
        if (pos_bor == 0) {
            curr_pos = 0;
        } else {
            curr_pos = curr_pos % max;
            //tmp.line = line;
            //tmp.begin_in_line = number_word;
            te[curr_pos].line = line;
            te[curr_pos].begin_in_line = number_word;
            if (t[pos_bor].leaf == true) {
                a = curr_pos - t[pos_bor].lenght + 1;
                if (a < 0) {
                    a += max;
                }
                printf("%d, %d, %d\n", te[a].line, te[a].begin_in_line, t[pos_bor].number_of_word);
            }
            link = link_exit(t, pos_bor);
            while (link != 0) {
                a = curr_pos - t[link].lenght + 1;
                if (a < 0) {
                    a += max;
                }
                printf("%d, %d, %d\n", te[a].line, te[a].begin_in_line, t[link].number_of_word);
                link = link_exit(t, link);
            }
            ++curr_pos;
        }
        while (symbol == ' ') {
            symbol = getchar();
        }
        if (symbol == '\n') {
            ++line;
            number_word = 0;
            symbol = getchar();
            while (symbol == '\n') {
                symbol = getchar();
                ++line;
            } if (symbol != EOF) {
                ungetc(symbol, stdin);
            } else {
                status = false;
            }
        } else {
            ungetc(symbol, stdin);
        }
    }
}

int main()
{
    std::vector<vertex> t;
    init(t);
    int m = read_samples(t);
    t.shrink_to_fit();
    if (m > 0) read_text_and_answer(t, m);
    return 0;
}
