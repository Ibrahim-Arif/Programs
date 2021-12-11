#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int day, month, year;
};
struct BankAccount {
    char accNumber[15], sortCode[15], accType[15];
    float balance;
};

struct Person {
    char name[30];
    struct Date dateOfBirth;
    struct BankAccount bAccount;
};

void PrintDate(struct Date d){
    printf("%d/%d/%d \n", d.day, d.month, d.year);
}
void PrintBankAccount(struct BankAccount ba){
    printf("Account Number: %s \n", ba.accNumber);
    printf("Sort Code: %s \n", ba.sortCode);
    printf("Type: %s \n", ba.accType);
    printf("Balance: %.2f \n\n", ba.balance);
}
void PrintPerson(struct Person p){
    printf("Name: %s \n", p.name);
    printf("Date of birth: ");
    PrintDate(p.dateOfBirth);
    PrintBankAccount(p.bAccount);
}

// helper function to create person.
struct Person NewPerson(char name[30], int day, int month, int year, char accNumber[15], char sortCode[15], char accType[15], float balance){
    struct Person temp;
    strcpy(temp.name, name);

    temp.dateOfBirth.day = day;
    temp.dateOfBirth.month = month;
    temp.dateOfBirth.year = year;

    strcpy(temp.bAccount.accNumber, accNumber);
    strcpy(temp.bAccount.sortCode, sortCode);
    strcpy(temp.bAccount.accType, accType);
    temp.bAccount.balance = balance;

    return temp;
};

void PrintAll(struct Person persons[5]){
	int i;
    for(i=0; i<5; i++)
        PrintPerson(persons[i]);
    printf("\n");
}

void PrintWithSaving(struct Person persons[5]){
    printf("------- All person's having saving accounts -------\n\n");
    int i;
    for(i=0; i<5; i++){
        if(strcmp(persons[i].bAccount.accType, "saving") == 0)
            PrintPerson(persons[i]);
    }
    printf("\n");
}

void BalanceLess_5K(struct Person persons[5]){
    printf("------- All person's having balance less than 5000 -------\n\n");
    int i;
    for(i=0; i<5; i++){
        if(persons[i].bAccount.balance < 5000)
            PrintPerson(persons[i]);
    }
    printf("\n");
}

// helper function to swap 2 elements of array of struct.
void swap(struct Person *p1, struct Person *p2){
    struct Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// using bubble sort, sorting data of persons in descending order.
void SortBalances(struct Person persons[5]){
    int i, j;

    for (i=0; i<5; i++){
        for (j=0; j<4-i; j++){
            if (persons[j].bAccount.balance < persons[j+1].bAccount.balance)
                swap(&persons[j], &persons[j+1]);
        }
    }
}

int main()
{
    struct Person persons[5];
    persons[0] = NewPerson("John Holand", 12, 12, 1998, "2345123", "22-33-44", "saving", 3456.91);
    persons[1] = NewPerson("Richard Smith", 1, 1, 1982, "6543123", "22-35-45", "current", 11580.01);
    persons[2] = NewPerson("Sarah Morton", 21, 4, 1991, "1234543", "22-33-44", "isa", 5123.42);
    persons[3] = NewPerson("Harry Coughlin", 16, 9, 1988, "6541233", "22-35-45", "saving", 8544.02);
    persons[4] = NewPerson("Sophie Parkinson", 14, 6, 1997, "9876123", "23-55-85", "saving", 1886.52);

    printf("------- All person's data -------\n\n");
    PrintAll(persons);

    PrintWithSaving(persons);
    BalanceLess_5K(persons);

    SortBalances(persons);
    printf("------- All person's sorted data (in descending order)-------\n\n");
    PrintAll(persons);

    return 0;
}
