#include <iostream>
#include <fstream>

using namespace std;
void file_out(string name);
ofstream file_get(char sym, string name);

void file_fill(ofstream (*openf) (char, string), char sym, string name);
int string_split(string us_string, string *str_arr);
void file_new(string name1, string name2, int length);

int get_num();
char file_mode();

int main() {
string file_name = "/Users/tornikegogiberidze/Desktop/labs_op_2/input.txt";
string new_file2 = "/Users/tornikegogiberidze/Desktop/labs_op_2/result.txt";
char sym_mode = file_mode();
file_fill(file_get, sym_mode, file_name);
cout <<"File 1: " <<"\n";
file_out(file_name);

int num = get_num();
file_new(file_name, new_file2, num);

cout <<"File 2: " << "\n";
file_out(new_file2);

return 0;

}

void file_fill(ofstream (*openf)(char, string), char sym, string name){
    ofstream user_file = openf(sym, name);
    string str = " ";
    if(!user_file){
        cout << "File could not open" << "\n";
    }
    else{
        cout << "Enter text, to stop press Option + N" << "\n";
        while(str.find(-53) == string :: npos){
            getline(cin, str);
            if(str.find(-53) == string :: npos)
                user_file << str << "\n";
            else break;
        }
        user_file.close();
    }
}

void file_out(string name){
    ifstream user_file(name);
    string str;
    if(!user_file){
        cout<<"File could not open"<<"\n";
    }
    else{
        while(!user_file.eof()){
            getline(user_file, str); // читання рядків
            cout << str << "\n";
        }
        user_file.close();
    }
}

ofstream file_get(char sym, string name){
    if(sym == 'w'){
        ofstream user_file(name, ios::out); // відкрити файл для запису
        return user_file;
    }
    else{
        ofstream user_file(name, ios::app); // відкрити в кінець
        return user_file;
    }
}

int string_split(string us_string, string *str_arr){
    size_t pos;
    string word;

    int word_count = 0;
    while((pos = us_string.find(" ")) != string::npos){ // робиття рядка
        word = us_string.substr(0, pos);
        if(word != ""){
            str_arr[word_count] = word;
            word_count++;
        }
        us_string.erase(0, pos+1);

    }
    return word_count;
}
void file_new(string name1, string name2, int length){
    ifstream file1(name1);
    ofstream file2(name2);
    string str;
    string text = "";
    while(!file1.eof()){
        getline(file1, str); // read rows
        text += str + " ";
    }
    size_t len = text.length()/2;
    string *word_arr = new string[len]; // words in text
    int amount = string_split(text, word_arr); // word count in text
    string *new_word_arr = new string[amount]; // words that satisfy condition
    int k = 0;
    for(int i = 0; i < amount - 1; i++){
        int counter = 1; // same words count
        for(int j = i + 1; j < amount; j++){
            if(word_arr[i] == word_arr[j]){
                word_arr[j] = "";
                counter++;
            }
        }
        if(counter > length && word_arr[i]!= ""){
            new_word_arr[k] = word_arr[i]; //words which quantity is bigger than user's words
            k++;
        }
    }
    //sort by length >
    for(int i = 0; i<k; i++){
        for(int j = 0; j < k-1; j++){
            if(new_word_arr[j].length()>new_word_arr[j+1].length()){
                string tmp = new_word_arr[j+1];
                new_word_arr[j+1] = new_word_arr[j];
                new_word_arr[j] = tmp;
            }
        }
    }
    //write info in new file
    for(int i = 0; i < k; i++){
        file2 << new_word_arr[i] << " ";
    }
    delete []word_arr;
    delete []new_word_arr;
    file1.close();
    file2.close();
}
int get_num(){
    int n ;
    cout << "Enter word amount";
    cin >> n;
    return n;
}
char file_mode(){
    char sym;
    cout << "Enter 'w' - write in file, 'a' - add text" << "\n"; // file opening mode
    cin >> sym;
    return sym;
}