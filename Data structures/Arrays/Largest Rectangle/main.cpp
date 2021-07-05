#include <iostream>
using namespace std;

int main()
{
    int n, curr, prev=0, next=0, count, curr_index, max_rect=0;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n; i++){
        count=1;
        curr_index = i;
        curr = arr[i];
        if(i > 0)         prev = arr[i-1];
        if(i < n-1)      next = arr[i+1];

        if(prev < curr && next < curr)
            continue;
        if(prev >= curr){
            curr_index = i-1;
            while(prev >= curr && curr_index > -1){
                count++;
                prev = arr[--curr_index];
            }
        }
        if(next >= curr){
            curr_index = i+1;
            while(next >= curr && curr_index < n){
                count++;
                next = arr[++curr_index];
            }
        }
        if(curr*count > max_rect)
            max_rect = curr*count;
    }
    cout<<max_rect<<endl;

    return 0;
}
