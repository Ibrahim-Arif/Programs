#include <stdio.h>
#include <stdlib.h>
int main()
{
   int x,y;
   printf("Enter the values of coordinates to check:\n");
   scanf("%d %d",&x,&y);
   if(x>=1&&y>=1)
   {
       printf("1st Quad");
   }
   else if(x<1&&y>=1)
   {
       printf("2nd Quad");
   }
   else if(x<0&&y<0)
   {
       printf("3rd Quad");
   }
   else if(x>=1&&y<1)
   {
       printf("4th Quad");
   }
   else
   {
       printf("points are 0,0");

   }
   return 0;
}
