#include <iostream>                             // https://www.hackerrank.com/challenges/no-prefix-set/problem
#include <string>
#include <vector>
using namespace std;

class node{
private:
    string word;
    bool EOW;

    int createKey(char ele){
        return (int)ele - 97;
    }

public:
    char element;
    node **mapp;
    int totalKeys;

    node(){
        element = (char)0;
        word = "";
        EOW = false;
        totalKeys = 0;
        mapp = new node*[26]{nullptr};
    }

    void setEnd(bool e){
        EOW = e;
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

        totalKeys++;
    }

    node* getKey(char ele){
        int index = createKey(ele);
        return mapp[index];
    }

    bool hasKey(char ele){
        int index = createKey(ele);
        return (mapp[index]) ? true : false;
    }
};

class trie{
private:
    node *root;

    node* addUtil(string input, string inputCopy, node *n){
        if(input.size() == 0){
            n->setEnd(true);
            n->setWord(inputCopy);              // setting whole string at the leaf node.
            return n;
        }
        else if( !n->hasKey( input[0] ))
            n->setKey(input[0]);

        return addUtil(input.substr( 1, input.size()), inputCopy, n->getKey(input[0]) );
    }

public:
    trie(){
        root = new node();
    }

    node* add(string input){
        return addUtil(input, input, root);
    }

     bool doPrefix(string prefix){
        int i=0;
        node *temp = root;
        bool flag = false;
        string matched = "";

        while(prefix[i] != '\0'){
            if(temp->hasKey(prefix[i])){
                temp = temp->getKey(prefix[i]);
                matched += prefix[i];

                if(temp->isEnd()){
                    flag = true;
                    break;
                }
                i++;
            }
            else
                break;
        }
        if(matched == prefix)
            return true;
        return flag;
    }

};

int main()
{
    int n;
    bool flag = false;
    string input;
    vector<string> v;
    trie t;

    cin >> n;
    while(n--){
        cin >> input;
        v.push_back(input);
    }

    for(unsigned int i=0; i<v.size(); i++){
        if(t.doPrefix(v[i])){
            flag = true;
            cout<<"BAD SET"<<endl;
            cout<<v[i]<<endl;
            break;
        }
        t.add(v[i]);
    }
    if(!flag)
        cout<<"GOOD SET"<<endl;

    return 0;
}
