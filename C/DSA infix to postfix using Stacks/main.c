#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    int capacity;
    char *array;
};
struct stack* createStack(int capacity){
    struct stack* stack = (struct stack*) calloc( 1, sizeof(struct stack) );

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)  calloc(stack->capacity, sizeof(char));
    return stack;
}
void push(char ele, struct stack *s){
    if( isFull(s) )     printf("Stack is overflow!");
    else                   s->array[++s->top] = ele;
}
char pop(struct stack *s){
    return s->array[s->top--];
}
char peek(struct stack *s){
    return s->array[s->top];
}
void traverse(struct stack *s){
     for(int i=s->top; i>=0; i--)
            printf("%c",s->array[i]);
}
int isEmpty(struct stack *s){
    if(s->top == -1)
        return 1;
    else
        return 0;
}
int isFull(struct stack *s){
    if(s->top == s->capacity-1)
        return 1;
    else
        return 0;
}
int length(struct stack *s){
    return s->top+1;
}
int precedence(char op){
    if(op == '(' || op == ')' || op == '{' || op == '}')               return 4;
    else if(op == '^')                                                            return 3;
    else if(op == '*' || op == '/' || op == '%')                      return 2;
    else if(op == '+' || op == '-')                                         return 1;
    //else return;
}
void convertToPostfix(char str[], struct stack *s){
    int i=0;
    char curr;
     while(str[i] != '\0'){
        curr = str[i];
        if( isalpha(curr) || isdigit(curr) )            printf("%c",curr);
        else if( isEmpty(s) || peek(s) == '(' )   push(curr, s);
        else if(curr == '(')                                     push(curr, s);
        else if( curr == ')' ){
            char po = pop(s);
            while(po != '('){
                printf("%c",po);
                po = pop(s);
            }
        }
        else if(precedence(curr) > precedence( peek(s) ))    push(curr, s);
        else if(precedence(curr) < precedence( peek(s) )){
            printf("%c",pop(s));
            continue;
            push(curr, s);
        }
        else if(precedence(curr) == precedence( peek(s) )){
            if(precedence(curr) == 3)       push(curr, s);
            else{
                printf("%c",pop(s));
                push(curr, s);
            }
        }
        i++;
    }
    traverse(s);
}

int main()
{
    int i=0;
    char str[50], curr;           //K+L-M*N+(O^P)*W/U/V*T+Q
    struct stack *s = createStack(30);

    printf("Enter expression to postfix: ");
    scanf("%s",str);
    convertToPostfix(str, s);

    printf("\n\n");
    return 0;
}
