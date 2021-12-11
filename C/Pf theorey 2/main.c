#include <stdio.h>
#include <stdlib.h>

float ratti_to_masha(float ratti)
{
    float masha;
    masha=ratti/8;
    return masha;
}
float  masha_to_ratti(float masha)
{
    float ratti;
    ratti=masha*8;
    return ratti;
}
float masha_to_tola(float masha)
{
    float tola;
    tola=masha/12;
    return tola;
}
float tola_to_masha(float tola)
{
    float masha;
    masha=tola*12;
    return masha;
}
float tola_to_ser(float tola)
{
    float ser;
    ser=tola/80;
    return ser;
}
float ser_to_tola(float ser)
{
    float tola;
    tola=ser*80;
    return tola;
}

int main()
{
    float ratti, masha, tola, ser;
    char choice;
    repeat:
    printf("Enter 1 ratti to masha. \n");
    printf("Enter 2 masha to ratti. \n");
    printf("Enter 3 masha to tola. \n");
    printf("Enter 4 tola to masha. \n");
    printf("Enter 5 tola to ser. \n");
    printf("Enter 6 ser to tola. \n");
    printf("Enter 7 to exit. \n");

    printf("\nYour choice: ");
    choice=getche();
    printf("\n");

    if(choice=='1')
    {
        printf("Enter weight in ratti: ");
        scanf("%f",&ratti);
        masha=ratti_to_masha(ratti);
        printf("%.2f ratti = %.2f masha\n\n",ratti, masha);
    }

    else if(choice=='2')
    {
        printf("Enter weight in masha: ");
        scanf("%f",&masha);
        ratti=masha_to_ratti(masha);
        printf("%.2f masha = %.2f ratti\n\n",masha, ratti);
    }
    else if(choice=='3')
    {
        printf("Enter weight in masha: ");
        scanf("%f",&masha);
        tola=masha_to_tola(masha);
        printf("%.2f masha = %.2f tola\n\n",masha, tola);
    }
    else if(choice=='4')
    {
        printf("Enter weight in tola: ");
        scanf("%f",&tola);
        masha=tola_to_masha(tola);
        printf("%.2f tola = %.2f masha\n\n",tola, masha);
    }

    else if(choice=='5')
    {
        printf("Enter weight in tola: ");
        scanf("%f",&tola);
        ser=tola_to_ser(tola);
        printf("%.2f tola = %.2f ser\n\n",tola, ser);
    }
    else if(choice=='6')
    {
        printf("Enter weight in ser: ");
        scanf("%f",&ser);
        tola=ser_to_tola(ser);
        printf("%.2f ser = %.2f tola\n\n",ser, tola);
    }
    else if(choice=='7')
    {
        printf("This program is created by: Ibrahim Arif.\n");
        return 0;
    }
    goto repeat;
    return 0;
}
