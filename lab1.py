def write_file(filename, filemode):
     f = open(filename, filemode) #open file
     us_str = ' '
     print("Enter text, double Enter to stop")
     while us_str: # insert line condition
         us_str = input()
         if us_str:
             f.write(us_str + "\n")
     f.close()


def file_out(filename):
    with open(filename, 'r+') as f:
        for line in f:
            print(line)#output file


def get_n():
    n = int(input('Enter amount of words '))
    return n


def new_file(file1, file2, amount):
    f1 = open(file1, 'r') #open input file for reading
    f2 = open(file2, 'w') #open new file for write
    text = f1.read()
    word_list = text.split()#input file words
    checked_words = list()
    for word in word_list:
        counter = 0 #same words quantity
        for key, word_check in enumerate(word_list):
            if word == word_check and word_check!='':
                counter += 1
                if counter>1:
                    word_list[key] = ''
        if counter > amount: #task condition check
            checked_words.append(word + ' ') #words for second file
    checked_words.sort(key=lambda s: len(s)) #sort by length
    for word in checked_words:
        f2.write(word)#write words in new file
    f1.close()
    f2.close()

symb = str(input('Enter w - write in file, a - add text '))
write_file('input.txt', symb)#input by user
n = get_n()#word count
new_file('input.txt', 'result.txt', n)#create new file
print('\nFile1:')
file_out('input.txt')#print input file
print('\nFile2:')
file_out('result.txt')#print result