import random
import string

def get_random(x):
    return ''.join(random.choice('0123456789') for i in range(random.randint(1, x)))

if __name__ == "__main__":
    pattern = ''
    text = ''
    text_sup = ''
    keys = []
    test_file_name = "test.txt"
    with open( "test.txt", 'w' ) as output_file:
        for i in range(10): # obrazsci
            for a in range(random.randint(1, 10)):
                pattern = pattern + get_random(4) + ' '
            text = text + pattern + '\n'
            keys.append(pattern)
            pattern = ''
        text = text + '\n'
        for i in range(10000):
            if i % 1000 == 0:
                print(i)
            if i % 250 == 0:
                text = text + random.choice(keys) + '\n'
            else:
                for a in range(random.randint(0, 20)):
                    text_sup = text_sup + get_random(10) + ' '
                text = text + text_sup + '\n'
                text_sup = ''
        output_file.write("{0}\n".format( text.lstrip() ))