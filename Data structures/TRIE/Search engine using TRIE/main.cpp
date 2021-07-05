#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printVector(vector<string> v){
    if(!v.size())
        return;

    for(unsigned int i=0; i<v.size(); i++)
        cout<<v[i]<<", ";
    cout<<endl;
}


class node{
private:
    string word;
    bool EOW;

public:
    char element;
    node **mapp;

    node(){
        element = (char)0;
        word = "";
        EOW = false;
        mapp = new node*[26]{nullptr};
    }

    void setEnd(){
        EOW = true;
    }
    bool isEnd(){
        return EOW;
    }
    void setWord(string com){
        if(EOW)
            word = com;
    }
    string getWord(){
        return word;
    }

    void setKey(char ele){
        int index = createKey(ele);
        if(!mapp[index] ){
            mapp[index] = new node();
            mapp[index]->element = ele;
        }
        else
            mapp[index]->element = ele;
    }

    node* getKey(char ele){
        int index = createKey(ele);
        return mapp[index];
    }

    bool hasKey(char ele){
        int index = createKey(ele);
        return (mapp[index]) ? true : false;
    }

    int createKey(char ele){
        return (int)ele - 97;
    }
};

class trie{
private:
    node *root;

    node* addUtil(string input, string inputCopy, node *n){
        if(input.size() == 0){
            n->setEnd();
            n->setWord(inputCopy);              // setting whole string at the leaf node.
            return n;
        }
        else if( !n->hasKey( input[0] ))
            n->setKey(input[0]);

        return addUtil(input.substr( 1, input.size()), inputCopy, n->getKey(input[0]) );
    }

    vector<string> printAllUtil(node *n, string s, vector<string> &words){
        s+= n->element;
        for(int i=0; i<26; i++){
            if(!n->mapp[i])
                continue;

            printAllUtil(n->getKey(n->mapp[i]->element), s, words);
        }
        if(n->isEnd()){
            //cout<<n->getWord()<<endl;
            words.push_back(s);
        }
        return words;
    }

    string searchUtil(node *n, string input){
        if( !input.size() && n->isEnd())
            return n->getWord();

        if( n->hasKey(input[0]) )
            return searchUtil(n->getKey(input[0]), input.substr(1, input.size()));
        else
            return "0";
    }

public:
    trie(){
        root = new node();
    }

    node* add(string input, string type){
        return addUtil(input, type, root);
    }

    vector<string> printAll(){
        vector<string> words;
        return printAllUtil(root, "", words);
    }

     vector<string> byPrefix(string prefix){
        int i=0;
        vector<string> words = {};
        node *temp = root;
        string matched = "";

        while(prefix[i] != '\0'){
            if(temp->hasKey(prefix[i])){
                matched += prefix[i];
                temp = temp->getKey(prefix[i]);
                i++;
            }
            else
                break;
        }
        if(matched.size()>1){
            return printAllUtil(temp, matched.substr(0, matched.size()-1), words);
        }
        return words;
    }

    void search(string input){
        string result = searchUtil(root, input);

        if(result == "0"){
             cout<<"Output the word \""<<input<<"\" was not found"<<endl;
            vector<string> similar = byPrefix(input);

            if(similar.size()){
                cout<<"Do you mean: ";
                printVector(similar);
            }
            return;
        }
        cout<<"Output the word \""<<input<<"\" was found with meaning \""<<result<<"\""<<endl;
    }
};

int main()
{
    trie tr;

    tr.add("apple", "fruit");
    tr.add("texla", "automobile");
    tr.add("facebook", "social network");
    tr.add("google", "search engine");
    tr.add("cricket", "sports game");
    tr.add("ronaldo", "football player");
    tr.add("jason", "actor");
    tr.add("python", "programming language");

    tr.add("maa", "");
    tr.add("nonentity", "");
    tr.add("nonaggressive", "");
    tr.add("nonessential", "");
    tr.add("nonfiction", "");

    tr.add("postmortem", "");
    tr.add("posterior", "");
    tr.add("postscript", "");

    tr.add("upbeat", "");
    tr.add("updo", "");
    tr.add("upgrade", "");
    tr.add("upload", "");
    tr.add("uphill", "");
    tr.add("upstage", "");
    tr.add("upscale", "");

    tr.search("ronaldo");

    //cout<<tr.search("python")<<endl;

    //printVector(tr.byPrefix("upstage") );

    //printVector( tr.printAll() );



    return 0;
}
