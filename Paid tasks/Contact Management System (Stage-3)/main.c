#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact  {
    char *name;
    char *phoneNumber;
    char *birthdate;
};

// sort contact according to their name.
void sort(struct Contact **contacts, int count){
    int i, j, tempIndex;
    struct Contact *temp;
    for(i=0; i<count; i++) {
        tempIndex = i;
        for(j=i+1; j<=count; j++){
            // comparing a contact with all contacts next to it..
            // if current contact is greater than any contact next to it
            // then we will swap those 2 contacts.
            if(strcmp(contacts[j]->name, contacts[tempIndex]->name) < 0)
                tempIndex = j;
        }

        // swapping two contacts.
        temp = contacts[tempIndex];
        contacts[tempIndex] = contacts[i];
        contacts[i] = temp;
    }
}

// function to register new contact into array of contacts.
int registration(struct Contact **contacts, int count){
	// allocating memery to struct at index count.
    contacts[count] = malloc(sizeof(struct Contact));
    // allocating memory to all struct member.
    contacts[count]->name = malloc(sizeof(char) *100);
	contacts[count]->phoneNumber = malloc(sizeof(char) *100);
	contacts[count]->birthdate = malloc(sizeof(char) *100);

    printf("Name:");
    scanf("%s", contacts[count]->name);
    printf("Phone_number:");
    scanf("%s", contacts[count]->phoneNumber);
    printf("Birth:");
    scanf("%s", contacts[count]->birthdate);

    sort(contacts, count);

    // increment in count as a new contact is just added.
    printf("<<%d>>\n", ++count);
    return count;
}


// Delete the person’s information.
int delete(struct Contact **contacts, int count){
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
        if(strcmp(contacts[i]->name, name) == 0){
            int j;

            // free space of deleting structure's members.
            free(contacts[i]->name);
            free(contacts[i]->phoneNumber);
            free(contacts[i]->birthdate);

            // free space of deleting structure.
            free(contacts[i]);

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
void showAll(struct Contact **contacts, int count){
    int i;
    for(i=0; i<count; i++)
        printf("%s %s %s\n", contacts[i]->name, contacts[i]->phoneNumber, contacts[i]->birthdate);
}

// display the people’s information who where born in the given month
void findByBirth(struct Contact **contacts, int count){
    int month, i, monthInt;
    char monthStr[2];

    // taking month input to find.
    printf("Birth:");
    scanf("%d", &month);

    for(i=0; i<count; i++){
        // getting month from date of birth.
        monthStr[0] = contacts[i]->birthdate[4];
        monthStr[1] = contacts[i]->birthdate[5];
        // converting month string into integer
        monthInt = atoi(monthStr);

        // comparing given month with month of contact.
        if(monthInt == month)
            printf("%s %s %s\n", contacts[i]->name, contacts[i]->phoneNumber, contacts[i]->birthdate);
    }
}

// read contacts from file
int regFromFile(struct Contact **contacts, int count, int max){
    FILE * file = fopen("PHONE_BOOK.txt", "r");

    // if file opening failed
    if (file == 0)
        return count;

    char temp[100];
    while (fscanf(file, "%s", temp) != EOF){
        if(count == max){
            printf("OVERFLOW\n");
            break;
        }

        // allocating memery to struct at index count.
        contacts[count] = malloc(sizeof(struct Contact));
        // allocating memory to all struct member.
        contacts[count]->name = malloc(sizeof(char) *100);
        contacts[count]->phoneNumber = malloc(sizeof(char) *100);
        contacts[count]->birthdate = malloc(sizeof(char) *100);

        strcpy(contacts[count]->name, temp);

        fscanf(file, "%s", temp);
        strcpy(contacts[count]->phoneNumber, temp);

        fscanf(file, "%s", temp);
        strcpy(contacts[count]->birthdate, temp);

        count++;
    }

    // sorting contact by their names.
    sort(contacts, count-1);
    return count;
}

// write contacts to file
void writeToFile(struct Contact **contacts, int count){
    FILE * file = fopen("PHONE_BOOK.txt", "w");

    // if file creation failed
    if (file == 0)
        return;

    int i;
    for(i=0; i<count; i++){
        fputs(contacts[i]->name, file);
        fputc(' ', file);
        fputs(contacts[i]->phoneNumber, file);
        fputc(' ', file);
        fputs(contacts[i]->birthdate, file);
        fputc('\n', file);
    }

    fclose(file);
}


int main()
{
    int max;
    printf("Max_num:");
    scanf("%d", &max);

    struct Contact **contacts = malloc(sizeof(struct Contact) * max);
    int count=0, choice=-1;

    while(choice != 6){
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
        printf("Enter_the_menu_number:");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                if(count == max){
                    printf("OVERFLOW\n");
                    break;
                }

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
            case 5:{
                count = regFromFile(contacts, count, max);
                break;
            }
            case 6:{
                writeToFile(contacts, count);
                break;
            }
        }
    }

    return 0;
}
