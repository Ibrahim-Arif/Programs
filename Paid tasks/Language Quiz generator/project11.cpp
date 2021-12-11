#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class word{
private:
    int totalTranslations;
    bool isCorrect;
    string english;

public:
    string spanishWords[10], answers[10];

    word();
    word(string e, int tt, string sw[]);
    bool checkAnswer();
    int getTotalTranslations();
    string getEnglish();
    bool getIsCorrect();
};

word::word(){
    totalTranslations = 0;
    english = "";
    for(int i=0; i<10; i++){
        spanishWords[i] = "";
        answers[i] = "";
    }
}
word::word(string e, int tt, string sw[]){
    english = e;
    totalTranslations = tt;
    for(int i=0; i<tt; i++)
        spanishWords[i] = sw[i];
}
bool word::checkAnswer(){
    isCorrect = true;
    for(int i=0; i<totalTranslations; i++){
        if(spanishWords[i] != answers[i])
            isCorrect = false;
    }
    return isCorrect;
}
int word::getTotalTranslations(){
    return totalTranslations;
}
string word::getEnglish(){
    return english;
}
bool word::getIsCorrect(){
    return isCorrect;
}

int read_dictionary(word (&words)[100], char filename[]){
    int totalTranslations, totalWords;
    string spanishWords[10];
    char english[20];

    ifstream dictionaryFile(filename);

    if(!dictionaryFile){
        cout << "!!! Can not read " << filename << " file !!!" << endl;
        exit(0);
    }

    dictionaryFile >> totalWords;

    int count=0;
    while(!dictionaryFile.eof()){
        dictionaryFile.ignore();
        dictionaryFile.read(english, 20);
        dictionaryFile >> totalTranslations;

        for(int i=0; i<totalTranslations; i++)
            dictionaryFile >> spanishWords[i];

        words[count] = word(english, totalTranslations, spanishWords);
        count++;
    }

    dictionaryFile.close();
    return totalWords;
}
double start_quiz(word (&words)[100], bool (&asked)[100], int totalWords, int total_qs_to_ask){
    srand(time(0));
    bool isCorrect;
    int random, totalCorrect=0;

    cout << "-------------------------------------" << endl;
    cout << "Quiz Time" << endl;
    cout << "-------------------------------------" << endl;

    random = rand() % totalWords;
    for(int i=0; i<total_qs_to_ask; i++){
        while(asked[random])
            random = rand() % totalWords;
        asked[random] = true;

        cout << "Question " << i+1 << endl;
        cout << "English word: " << words[random].getEnglish() << endl;
        cout << "\nEnter " << words[random].getTotalTranslations() << " equivalent Spanish word(s)." << endl;

        for(int j=0; j<words[random].getTotalTranslations(); j++){
            cout << "word[" << j+1 << "]: ";
            cin >> words[random].answers[j];
        }

        isCorrect = words[random].checkAnswer();

        if(isCorrect){
            cout << "Correct!" << endl;
            totalCorrect++;
        }
        else
            cout << "Incorrect!" << endl;

        cout << "\n-------------------------------------" << endl;
    }

    return ((double)totalCorrect / (double)total_qs_to_ask) * 100;
}
void write_result_file(word words[100], int totalWords, bool asked[100], char filename[], string username, int score){
    ofstream outputFile(filename);
    
    if(!outputFile){
        cout << "!!! Can not read " << filename << " file !!!" << endl;
        exit(0);
    }

    outputFile << "-------------------------------------" << endl;
    outputFile << "Quiz Result" << endl;
    outputFile << "-------------------------------------" << endl;

    int count=0;
    for(int i=0; i<totalWords; i++){
        if(asked[i]){
            outputFile << "Question " << ++count << endl;
            outputFile << "English word: " << words[i].getEnglish() << endl;

            outputFile << "Your answer(s): ";
            for(int j=0; j<words[i].getTotalTranslations(); j++)
                outputFile << words[i].answers[j] << ", ";
            outputFile << endl;

            outputFile << "Expected answer(s): ";
            for(int j=0; j<words[i].getTotalTranslations(); j++)
                outputFile << words[i].spanishWords[j] << ", ";
            outputFile << endl;

            if(words[i].getIsCorrect())
                outputFile << "Correct!" << endl;
            else
                outputFile << "Incorrect!" << endl;

            outputFile << "\n-------------------------------------" << endl;
        }
    }

    outputFile << "Grade Time" << endl;
    outputFile << "Name: " << username << endl;
    outputFile << "Grade: " << score << "% ";

    if(score < 80)
        outputFile << "(Failed - You have scored below 80%)" << endl;

    outputFile.close();
    cout << filename << " result file write successfully..." << endl;
}

int main()
{
    word words[100];
    int totalWords, total_qs_to_ask, score;
    bool asked[100] = {false};
    string username;
    char outputFilename[50], inputFilename[50];

    cout << "Welcome to the John Doe Vocabulary quiz program" << endl;

    cout << "Enter vocabulary filename: ";
    cin >> inputFilename;
    totalWords = read_dictionary(words, inputFilename);

    cout << "Please enter your name: ";
    getline(cin, username);
    getline(cin, username);

    cout << "Maximum available words: " << totalWords << " words." << endl;
    cout << "How many words would you like to be quizzed on? ";
    cin >> total_qs_to_ask;

    while(total_qs_to_ask > totalWords){
        cout << "\nERROR!!! " << inputFilename << " file does not contain "  << total_qs_to_ask << " words..." << endl;

        cout << "Please enter number of words again: ";
        cin >> total_qs_to_ask;
    }

    score = start_quiz(words, asked, totalWords, total_qs_to_ask);

    cout << "Grade Time" << endl;
    cout << "Name: " << username << endl;
    cout << "Grade: " << score << "% ";

    if(score < 80)
        cout << "(Failed - You have scored below 80%)" << endl;

    cout << "\n\nEnter an output filename: ";
    cin >> outputFilename;

    write_result_file(words, totalWords, asked, outputFilename, username, score);

    return 0;
}
