#include<stdio.h>
#include<string.h>
typedef struct student
{
  char Name[20];
  int RollNo;
  float CGPA;
}Student;
Write_to_File(Student st[5],FILE *fp)
{
   int k;
         for(k = 0 ; k < 5; k++)
            {
                    fprintf(fp,"Name      : %s\n",st[k].Name);
                    fprintf(fp,"Roll No   : %d\n",st[k].RollNo);
                    fprintf(fp,"CGPA      : %.2f\n\n",st[k].CGPA);
            }
}

Read_from_File(Student st[5],FILE *fp)
{
   int k;
   while(feof(fp))
   {
       for(k = 0 ; k < 5; k++)
            {
                    fscanf(fp,"%s",&st[k].Name);
                    fscanf(fp,"%d",&st[k].RollNo);
                    fscanf(fp,"%.2f",&st[k].CGPA);
            }
   }

}
Append_to_file(student s1[5],FILE *f)
{
    fprintf(f,"\nThis is an appending text\n");
    Student append={"HUMMA",12,4};
    fprintf(f,"Name      : %s\n",append.Name);
    fprintf(f,"Roll No   : %d\n",append.RollNo);
    fprintf(f,"CGPA      : %.2f\n\n",append.CGPA);
}

void  main()
{
int option;
//b array of 5 elements                       //c initialization
Student s1[5]={{"IFRAH NAZ",1,4},{"IFRA",2,3.7},{"ANAM",3,4},{"FARAH",1,3.3},{"SAIF",11,3.3}};
do
{

    printf("\n\n***************************************\n");
    printf("press 1 for Writing a file\n");
    printf("press 2 for Reading a file\n");
    printf("press 3 for Appending a file\n");
    printf("press 4 to exit from a program\n");
    scanf("%d",&option);
    printf("\n***************************************\n\n");

if(option==1)

{

    FILE *fp;
    fp=fopen("student.dat","w");

    if(fp==NULL)
        {
            printf("FIlE NOT FOUND\n");
        }
        else
        {
            fprintf(fp,"\n\n****************Writing***********************\n\n");
            Write_to_File(s1,fp);
        }
        printf("\nData has been written successfully to the file\n");
}

else if(option==2)
    {
        FILE *fp;
    fp=fopen("student.dat","r");

        if(fp==NULL)
        {
            printf("FIlE NOT FOUND\n");
        }
        else
        {
            fprintf(fp,"\n\n****************Reading***********************\n\n");
            Read_from_File(s1,fp);
            fclose(fp);
        }
        printf("\nData has been read successfully from the file\n");
    }
else if(option==3)
    {
        FILE *fp;
        fp=fopen("student.dat","a");

        if(fp==NULL)
            {
                printf("FIlE NOT FOUND\n");
            }

        else
           {
                fprintf(fp,"\n\n****************Appending***********************\n\n");
                Append_to_File(s1,fp);
                fclose(fp);
            }
        printf("\nData has been appended successfully to the file\n");
    }
else if(option == 4)
        printf("\nYou entered an Invalid option!!!!!!!!!!!!!!!!\n");
}
while(option!=4);


return 0;
}
