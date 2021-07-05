#include <iostream>
using namespace std;

class word{
public:
    string wordd;
    int length, position;
    word *next;

    word(string w, int l, int p){
        wordd = w;
        length = l;
        position = p;
        next = nullptr;
    }
};
class sentence{
public:
    word *words;
    int position, length;
    sentence *next;

    sentence(word *w, int p, int l){
        words = w;
        position = p;
        length = l;
        next = nullptr;
    }
};

template<class N>
class list{
public:
    N *head, *tail;
    int size;
    list(){
        size = 0;
        head = tail = nullptr;
    }

    void append(N *node){
        if( !head ){
              head = node;
              tail = node;
              size++;
              return;
        }
        tail->next = node;
        tail = node;
        size++;
    }
    void deleteSentence(int position){
        if(position < 1 || position > size)
            return;

        N *curr = head, *previous, *temp;
        if(position == 1){                                      // is root is deleted
            curr = head;
            head = curr->next;
        }
        else{
            while(curr->position != position){
                previous = curr;
                curr = curr->next;
            }
            if(curr == tail)                                        // for tail deletion
                tail = previous;

            previous->next = curr->next;
        }

        temp = curr->next;
        curr->next = nullptr;
        delete curr;

        while(temp){                                            // decrement remaining list
            temp->position--;
            temp = temp->next;
        }
        size--;                                                      // decrement size of paragraph
    }
    void displaySentence(){                            // when list is of words type then use this function.
        word *temp = head;
        while(temp){
            cout<<temp->wordd<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    word* searchWord(string ele){
        word *temp = head;
        while(temp){
            if(temp->wordd == ele)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};


 void displayPara(list<sentence> paragraph){
     sentence *temp = paragraph.head;
     list<word> words;

     while(temp){
        words.head = temp->words;
        words.displaySentence();

        temp = temp->next;
     }
 }
 void searchWord(string ele, list<sentence> paragraph){
     sentence *temp = paragraph.head;
     list<word> words;
     word *w;
     bool found = false;

     while(temp){
        words.head = temp->words;
        w = words.searchWord(ele);

        if(w){
            cout<<"sentence: "<<temp->position<<", word: "<<w->position<<endl;
            found = true;
        }
        temp = temp->next;
     }
     if(!found)
        cout<<ele<<" NOT FOUND!!!"<<endl;
 }
sentence* generateSentence(string sent, int sentPos){           // sentence, position of sentence in paragraph
    char curr;
    string w;
    list<word> words;

    for(unsigned int i=0; i<sent.size(); i++){
        curr = sent[i];

        if(curr != ' ' && isalpha(curr))
            w += curr;

        if(curr == ' ' || i == sent.size()-1){
            words.append( new word(w, w.size(), words.size+1) );
            w = "";
        }
    }
    return new sentence(words.head, sentPos, words.size);
}

int main()
{
    string sen = " ";
    list<sentence> paragraph;

    while(sen != ""){           // insertion
        getline(cin, sen);

        if(sen != "")
            paragraph.append( generateSentence(sen, paragraph.size+1) );
    }

    displayPara(paragraph);

    sen = " ";
    while(sen != ""){          // searching
        cout<<"\nsearch: ";
        getline(cin, sen);

        if(sen != "")
            searchWord(sen, paragraph);
    }

    int pos;
    while(pos){                 // deletion
        cout<<"\nDelete: ";
        cin >> pos;
        if(pos){
            paragraph.deleteSentence(pos);
            displayPara(paragraph);
        }
    }

    cout<<"\n\nEnded";
    return 0;
}
