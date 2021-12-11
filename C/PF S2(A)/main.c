#include <stdio.h>
#include <stdlib.h>

void input_student(int stdIDs[], int numStudents)
{
    int i;
    printf("\n");
    for(i=0;i<numStudents;i++)
    {
        printf("Enter student[%d] id: ",i);
        scanf("%d",&stdIDs[i]);
    }
}

void input_top_student(int topStdIDs[], int numQuizzes)
{
    int i;
    for(i=0;i<numQuizzes;i++)
    {
        printf("Enter student id, who topped in quiz %d: ",i);
        scanf("%d",&topStdIDs[i]);
    }
}

void topCount(int topStdCount[], int topStdIDs[], int numQuizzes)
{
    int i, count,j;
    for(i=0;i<numQuizzes;i++)
        topStdCount[i] = -1;

    for(i=0;i<numQuizzes;i++)
    {
        count=1;
        for(j=i+1;j<numQuizzes;j++)
        {
            if(topStdIDs[i] == topStdIDs[j])
            {
                count++;
                topStdCount[j] = 0;
            }
            if(topStdCount[i] != 0)
            {
                topStdCount[i]=count;
            }
        }
        //++topStdCount[topStdIDs[i]];
    }
}

void displayArray(int arr[], int index)
{
    int i;
    printf("[");
    for(i=0;i<index;i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("]");
}

int main()
{
    int numQuizzes, numStudents, stdIDs[100]={0}, topStdIDs[100]={0}, topStdCount[100]={0};

    printf("Enter number of students: ");
    scanf("%d",&numStudents);
    printf("Enter number of quizzes: ");
    scanf("%d",&numQuizzes);

    input_student(stdIDs, numStudents);
    printf("\n");
    input_top_student(topStdIDs, numQuizzes);

    printf("Student ids: ");
    displayArray(stdIDs, numStudents);
    printf("\nTop student ids: ");
    displayArray(topStdIDs, numQuizzes);

    topCount(topStdCount, topStdIDs, numQuizzes);
    printf("\nTop student count: ");
    //displayArray(topStdCount, numStudents);
    printf("[ ");
    for(int i=0;i<=numStudents;i++)
    {
        if(topStdCount[i] != 0)
            printf("%d ",topStdCount[i]);
    }
    printf("]");
    printf("\n\n");
    return 0;
}
