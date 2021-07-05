#include <iostream>                             // https://www.hackerrank.com/challenges/merging-communities/problem
#include <vector>
using namespace std;

void print(vector<int> v){
    for(unsigned int i=1; i<v.size(); i++)
        cout << v[i] << ", ";
    cout<<endl<<endl;
}
int Find(vector<int> &parents, int vertex){
    if(parents[vertex] < 0)
        return -1*parents[vertex];
    return Find(parents, parents[vertex]);
}
void Union(vector<int> &parents, int x, int y){
    if(parents[x] < parents[y]){
        parents[x] += parents[y];
        parents[y] = x;
    }else{
        parents[y] += parents[x];
        parents[x] = y;
    }
}

int main()
{
    int n, q, i, j;
    char choice;
    cin >> n;
    cin >> q;

    vector<int> parents(n+1, -1);

    while(q--){
        cin >> choice;
        cin >> i;

        if(choice == 'm' || choice == 'M'){
            cin >> j;
            Union(parents, i, j);
            print(parents);
        }
        else if(choice == 'q' || choice == 'Q')
            cout<<Find(parents, i)<<endl;
    }

    return 0;
}
