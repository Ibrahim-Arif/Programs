#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

template<class T>
class Stack{
private:
    vector<T> vec;
    
public:
    void push_back(T ele){
    	vec.push_back(ele);
    }
    
    T pop_back(){
    	T temp = vec[vec.size()-1];
    	vec.pop_back();
        return temp;
    }
    
    bool isEmpty(){
        return vec.empty();
    }
};


int main(int argc, const char * argv[])
{
	Stack<char> operations;
	Stack<int> ids;
	int numberOfHROperations, i, id;
	char operation;
	
	printf("Enter the number of HR operations: \n");
	scanf("%d", &numberOfHROperations);
	
	//Read the operations and IDs from stdin
	printf("Input the operations and IDs: \n");
	for (i=0; i<numberOfHROperations; i++){
        scanf(" %c%d", &operation, &id);
        operations.push_back(operation);
        ids.push_back(id);
    }

	// reversing the stack
	Stack<int> tempIds;
	Stack<char> tempOpr;
	while(!ids.isEmpty()){
		tempIds.push_back(ids.pop_back());
		tempOpr.push_back(operations.pop_back());
	}
	
	// checking the operations.
	Stack<char> temp;
    while(!tempIds.isEmpty()){
    	operation = tempOpr.pop_back();
    	id = tempIds.pop_back();
    	
    	if(operation == '-'){
    		if(id != temp.pop_back()){
    			printf("\nFAIL \n");
    			return 0;
			}
		}
		else
			temp.push_back(id);
	}
	printf("\nPASS \n");
    
    return 0;
}
