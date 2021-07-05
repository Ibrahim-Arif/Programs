#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[21];
    char phoneNumber[16];
    char birthdate[9];
};

// function to register new contact into array of contacts.
int registration(struct Contact contacts[100], int count){
    // count is the index where new contact should be add.
    printf("Name:");
    scanf("%s", contacts[count].name);
    printf("Phone_number:");
    scanf("%s", contacts[count].phoneNumber);
    printf("Birth:");
    scanf("%s", contacts[count].birthdate);


    // after inserting new contact, now sorting all contacts.
    int i, j, tempIndex;
    struct Contact temp;
    for(i=0; i<count; i++) {
        tempIndex = i;
        for(j=i+1; j<=count; j++){
            // comparing a contact with all contacts next to it..
            // if current contact is greater than any contact next to it
            // then we will swap those 2 contacts.
            if(strcmp(contacts[j].name, contacts[tempIndex].name) < 0)
                tempIndex = j;
        }

        // swapping two contacts.
        temp = contacts[tempIndex];
        contacts[tempIndex] = contacts[i];
        contacts[i] = temp;
    }


    // increment in count as a new contact is just added.
    printf("<<%d>>\n", ++count);
    return count;
}

// Delete the person’s information.
int delete(struct Contact contacts[100], int count){
    // if no user then write a message and return with same count, as no contact is been deleted.
    if(count == 0){
        printf("NO MEMBER\n");
        return count;
    }

    // getting name to delete.
    char name[21];
    printf("Name:");
    scanf("%s", name);

    int i;
    for(i=0; i<count; i++){
        // comparing input name with name of each contact.
        if(strcmp(contacts[i].name, name) == 0){
            int j;

            // replacing contact with its next contact in order to overwrite the contact to be deleted.
            for(j=i; j<count-1; j++)
                contacts[j] = contacts[j+1];

            // decrement in count as a new contact is just added.
            --count;
        }
    }

    return count;
}

// function to display all the contacts.
void showAll(struct Contact contacts[100], int count){
    int i;
    for(i=0; i<count; i++)
        printf("%s %s %s\n", contacts[i].name, contacts[i].phoneNumber, contacts[i].birthdate);
}

// display the people’s information who where born in the given month
void findByBirth(struct Contact contacts[100], int count){
    int month, i, monthInt;
    char monthStr[2];

    // taking month input to find.
    printf("Birth:");
    scanf("%d", &month);

    for(i=0; i<count; i++){
        // getting month from date of birth.
        monthStr[0] = contacts[i].birthdate[4];
        monthStr[1] = contacts[i].birthdate[5];
        // converting month string into integer
        monthInt = atoi(monthStr);

        // comparing given month with month of contact.
        if(monthInt == month)
            printf("%s %s %s\n", contacts[i].name, contacts[i].phoneNumber, contacts[i].birthdate);
    }
}

int main()
{
    struct Contact contacts[100];
    int count=0, choice=-1;

    while(choice != 5){
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
        printf("Enter_the_menu_number:");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                count = registration(contacts, count);
                break;
            }
            case 2:{
                showAll(contacts, count);
                break;
            }
            case 3:{
                count = delete(contacts, count);
                break;
            }
            case 4:{
                findByBirth(contacts, count);
                break;
            }
        }
    }

    return 0;
}
