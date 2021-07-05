#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student *Head = NULL, *Tail = NULL;

struct Student{
    char name[30];
    int marks[3];
    float average;
    struct Student *left;
    struct Student *right;
};

// helper function to allocate dynamic memory for new Student node.
struct Student* NewNode(char name[30], int m1, int m2, int m3){
    struct Student *temp = (struct Student*) calloc(1, sizeof(struct Student));

    strcpy(temp->name, name);
    temp->marks[0] = m1;
    temp->marks[1] = m2;
    temp->marks[2] = m3;
    temp->average = 0;

    return temp;
}

void AppendFirst(struct Student *std){
    if(Head == NULL){
        Head = std;
        Tail = std;
    }else{
        std->right = Head;
        Head->left = std;
        Head = std;
    }
}

void AppendLast(struct Student *std){
    if(Head == NULL){
        Head = std;
        Tail = std;
    }else{
        std->left = Tail;
        Tail->right = std;
        Tail = std;
    }
}

void Show(){
    if(Head == NULL){
        printf("List is empty!");
        return;
    }

    struct Student *p = Head;
    while(p != NULL){
        printf("%s \n",p->name);
        printf("Marks: ");
        int i;
        for(i=0; i<3; i++)
            printf("%d, ", p->marks[i]);
        printf("\nAverage: %.2f \n\n", p->average);

        p = p->right;
    }
    printf("\n");
}

void CalculateAverage(){
    if(Head == NULL){
        printf("List is empty!");
        return;
    }

    struct Student *p = Head;
    int total, i;
    while(p != NULL){
        total=0;
        for(i=0; i<3; i++)
            total += p->marks[i];
        p->average = total/3;

        p = p->right;
    }
    printf("\n");
}

void Display65(){
    if(Head == NULL){
        printf("List is empty!");
        return;
    }

    struct Student *p = Head;
    int flag = 0;
    while(p != NULL){
        if(p->average > 65){
            printf("%s, ",p->name);
            flag = 1;
        }
        p = p->right;
    }

    if(!flag)
        printf("No student found !!");
    printf("\n");
}

void MarksHigher79(){
    if(Head == NULL){
        printf("List is empty!");
        return;
    }

    struct Student *p = Head;
    int flag = 0;
    while(p != NULL){
        if(p->marks[0]>79 && p->marks[1]>79 && p->marks[2]>79){
            printf("%s, ",p->name);
            flag = 1;
        }
        p = p->right;
    }

    if(!flag)
        printf("No student found !!");
    printf("\n");
}

int main()
{
    // filling list with data given data.
    AppendFirst(NewNode("James", 50, 65, 80));
    AppendFirst(NewNode("Sarah", 55, 72, 66));
    AppendFirst(NewNode("Stuart", 42, 65, 76));

    AppendLast(NewNode("Sam", 91, 76, 83));
    AppendLast(NewNode("Helen", 80, 55, 71));

    CalculateAverage();

    printf("All student's data. \n");
    printf("----------------------\n");
    Show();
    printf("----------------------\n");

    printf("\nStudents with average marks greater than 65. \n");
    Display65();

    printf("\n\nStudents with all marks greater than 79. \n");
    MarksHigher79();


    printf("\n\n");
    return 0;
}
