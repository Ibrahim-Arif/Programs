#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char name[30];
    int RollNo;
    float CGPA;
}student;

int main()
{
    student std[5] /*= { {"Ibrahim", 033, 3.2}, {"haseeb", 042, 3.1}, {"shami", 057, 3.0} , {"Faizan", 075, 2.7}, {"bilal", 99, 3.4} }*/;

    FILE *fptr;
  //  fptr = fopen("file.txt" , "wb");
    if(fptr == 0)
        printf("Unable to open ;(");
    else
    {
       /* //for(int i=0;i<5;i++)
            fwrite(&std,sizeof(std),1,fptr);

        fclose(fptr);*/
    }

    fptr = fopen("file.txt" , "rb");
    fread(std,sizeof(std),1,fptr);
    printf("%s\n",std[4].name);
    printf("%d\n",std[4].RollNo);
    printf("%.2f\n",std[4].CGPA);


    return 0;
}
