#include <iostream>
#define size 10
using namespace std;

void print(int arr[][size] ){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
            cout<< arr[i][j] << ", \t";
        cout<<endl;
    }
    cout<<endl;
}

bool reached = false;
void maze(int arr[size][size], int (&path)[size][size], int n, int src_r, int src_c, int desc_r, int desc_c){
    if( !arr[src_r][src_c] )
        return;
    else{
        if(!reached)                                       // if once reached then don't touch path array.
            path[src_r][src_c] = 1;
    }

    if(src_r == desc_r && src_c == desc_c){
        reached = true;
        return;
    }

    if(src_c+1 < n){
        maze(arr, path, n, src_r, ++src_c, desc_r, desc_c);

        if(!reached)                                      // if once reached then don't touch path array.
            path[src_r][src_c] = 0;

        --src_c;        // if next column have a dead end then we need to back trace to column which leads to next row.
    }
    if(src_r+1 < n)
         return maze(arr, path, n, ++src_r, src_c, desc_r, desc_c);
}

int main()
{
    int path[size][size] = {};
    /*
    int arr[4][4] = { {1, 1, 1, 1},
                             {0, 1, 0, 0},
                             {0, 1, 0, 1},
                             {1, 1, 1, 1} };
    */
    /*
    int arr[4][4] = {{1, 1, 0, 0},
                             {1, 1, 1, 1},
                             {0, 0, 1, 1},
                             {1, 1, 1, 1} };
    */
    /*
    int arr[size][size] = {{1, 0, 0, 0},
                                       {1, 0, 0, 0},
                                       {1, 1, 1, 0},
                                       {0, 0, 1, 1} };
    */

    int arr[size][size] = {{1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                                      {1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                                      {0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
                                      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 1, 0, 1, 1, 1, 0, 0},
                                      {1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
                                      {1, 1, 1, 0, 0, 0, 1, 0, 0, 0},
                                      {0, 0, 1, 1, 1, 1, 1, 1, 1,1} };

    maze(arr, path, size, 0, 0, size-1, size-1);

    if(!reached)
        cout<<"Path don't exist"<<endl;
    else
        print(path);

    return 0;
}
