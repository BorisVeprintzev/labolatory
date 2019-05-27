import random
import string

def get_random_char():
    return random.choice('QWERTYUIOPASDFGHJKLZXCVBNM')

def get_random_pattern_key():
    return ''.join(random.choice('123456789') for i in range(3))

def get_random_text_key():
    return ''.join(random.choice('123456789') for i in range(random.randint(1,9)))

if __name__ == "__main__":
    pattern = ''
    text = ''
    keys = []
    test_file_name = "test.txt"
    with open( "test.txt", 'w' ) as output_file:
        for i in range(10): # kolvo strok v file
            text = text + get_random_char() + ' ' + get_random_pattern_key() + ' ' + get_random_char() + get_random_char() + ' ' + get_random_text_key() + '\n' 
        output_file.write("{0}\n".format( text.lstrip() ))