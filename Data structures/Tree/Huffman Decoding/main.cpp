#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class node{
public:
    int freq;
    char data;
    node *left, *right;

    node(){}
    node(char c, int f){
        data = c;
        freq = f;
        left = right = nullptr;
    }
};

class tree{
public:
    node *root;
    tree(){
        root = nullptr;
    }

    void create_tree(node *curr, string s){
        int freq[26] = {0}, i=0, temp, count=0, max_index;
        node *n;
        size_t length = s.size();
        char max_char;

        while(s[i] != '\0')
            freq[s[i++]-97]++;

        for(i=0; i<26; i++){
            if(freq[i])
                count++;
        }
        root = new node('#', length);
        curr = root;

        for(i=0; i<count;i++){
            max_index = distance( freq, max_element(freq, freq+26) );
            max_char = (char)(max_index+97);

            n = new node(max_char, freq[max_index]);
            curr->left = n;
            length = length-freq[max_index];
            curr->right = new node('#', length);

            freq[max_index] = 0;
            curr = curr->right;
        }
    }
    void pre_order(node *curr){
        if(root == NULL){
            printf("Tree is empty!");
            return;
        }
        cout<<curr->data << ": "<<curr->freq<< ", " ;
        if(curr->left)       pre_order(curr->left);
        if(curr->right)    pre_order(curr->right);
    }
};

int main()
{
    string ele;                                             // abracadabra
    cin>>ele;

    tree tr;
    tr.create_tree(tr.root, ele);
    tr.pre_order(tr.root);

    return 0;
}
