#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct Student* Insert(struct Student *curr, struct Student *parent, struct Student *ele){
    if(curr == NULL){
        if(strcmp(ele->name, parent->name) > 0)
            parent->right = ele;
        else
            parent->left = ele;
        return curr;
    }

    else if(strcmp(ele->name, curr->name) > 0)
        return Insert(curr->right, curr, ele);
    else
        return Insert(curr->left, curr, ele);
}

// in-order traversal
void Show(struct Student *p){
    if(p == NULL){
        printf("Tree is empty!");
        return;
    }
    if(p->left)
        Show(p->left);

    printf("%s \n",p->name);
    printf("Marks: ");
    int i;
    for(i=0; i<3; i++)
        printf("%d, ", p->marks[i]);
    printf("\nAverage: %.2f \n\n", p->average);

    if(p->right)
        Show(p->right);
}

void CalculateAverage(struct Student *p){
    if(p == NULL){
        printf("Tree is empty!");
        return;
    }
    if(p->left)
        CalculateAverage(p->left);

    int total=0, i;
    for(i=0; i<3; i++)
        total += p->marks[i];
    p->average = total/3;

    if(p->right)
        CalculateAverage(p->right);
}

void Display65(struct Student *p){
    if(p == NULL){
        printf("Tree is empty!");
        return;
    }
    if(p->left)
        Display65(p->left);

    if(p->average>65 && p->marks[0]>=55 && p->marks[1]>=55 && p->marks[2]>=55)
        printf("%s, ", p->name);

    if(p->right)
        Display65(p->right);
}

void MarksHigher75(struct Student *p){
    if(p == NULL){
        printf("Tree is empty!");
        return;
    }
    if(p->left)
        MarksHigher75(p->left);

    if(p->marks[0]>75 && p->marks[1]>75 && p->marks[2]>75)
        printf("%s, ", p->name);

    if(p->right)
        MarksHigher75(p->right);
}



int main()
{
    struct Student *root = NULL;

    // filling tree with data given data.
    root = NewNode("James", 50, 65, 80);
    Insert(root, root, NewNode("Sarah", 55, 72, 66));
    Insert(root, root, NewNode("Stuart", 42, 65, 76));
    Insert(root, root, NewNode("Helen", 80, 55, 71));
    Insert(root, root, NewNode("Sam", 91, 76, 83));

    CalculateAverage(root);

    printf("All student's data. \n");
    printf("----------------------\n");
    Show(root);
    printf("----------------------\n");

    printf("\nStudents with average marks greater than 65 and no marks less than 55. \n");
    Display65(root);

    printf("\n\nStudents with all marks greater 75. \n");
    MarksHigher75(root);


    printf("\n\n");
    return 0;
}
