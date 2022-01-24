#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// user-defined library
// which includes all the structs
// Date, Person, BankAccount
#include "structures.h"

// constant for maximum number of bank accounts
#define MAX_ACCOUNTS 20

// helper function printDate 
// to display date
// parameters = Date
// return = null
void printDate(struct Date d){
    printf("%d/", d.day);
    printf("%d/", d.month);
    printf("%d \n", d.year);
}

// helper function printPerson
// to display Person
// parameters = Person
// return = null
void printPerson(struct Person p){
    printf("Name: %s \n", p.name);
    printf("Date of birth: ");
    printDate(p.dateOfBirth);
}

// helper function printBankAccount 
// to print bank account details
// parameters = Bank Account
// return null
void printBankAccount(struct BankAccount ba){
    printf("Account Number: %d \n", ba.accNumber);
    printf("Type: %s \n", ba.accType);
    printf("Balance: %.2f \n", ba.balance);
    printPerson(ba.accHolder);
    printf("\n");
}

// helper function printAllAccounts 
// to print all bank accounts
// parameters = bank accounts list, number of accounts
// return null
void printAllAccounts(struct BankAccount accounts[MAX_ACCOUNTS], int numAccounts){
	int i = 0;

    printf("------- All accounts data -------\n\n");
    for(i=0; i<numAccounts; i++){
        printBankAccount(accounts[i]);
    }

    printf("\n");
}

// function printSavingAccounts
// to display the saving accounts
// parameter = list of accounts, number of accounts
// return null
void printSavingAccounts(struct BankAccount accounts[MAX_ACCOUNTS], int numAccounts){
    int i=0;

    printf("------- All Saving Accounts -------\n\n");
    for(i=0; i<numAccounts; i++){
        // compare account type with "saving"
        // if matches then print
        // else ignore that account
        if(strcmp(accounts[i].accType, "saving") == 0){
            printBankAccount(accounts[i]);
        }
    }
    printf("\n");
}

// function printCurrentAccounts
// to display the saving accounts
// parameter = list of accounts, number of accounts
// return null
void printCurrentAccounts(struct BankAccount accounts[MAX_ACCOUNTS], int numAccounts){
    int i=0;

    printf("------- All Current Accounts -------\n\n");
    for(i=0; i<numAccounts; i++){
        // compare account type with "current"
        // if matches then print
        // else ignore that account
        if(strcmp(accounts[i].accType, "current") == 0){
            printBankAccount(accounts[i]);
        }
    }
    printf("\n");
}

// helper function NewPerson
// to create new struct of Person type.
// parameters:
//  1. string name of max 30 characters
//  2. integer day
//  3. integer month
//  4. integer year
//  5. int accNumber (account number)
//  6. string accType   (saving / current)
//  7. float balance
// return struct Person.
struct BankAccount newAccount(char name[30], int day, int month, int year, int accNumber, char accType[15], float balance){
    struct BankAccount ba;
    
    // account holder data
    // date of birth
    ba.accHolder.dateOfBirth.day = day;
    ba.accHolder.dateOfBirth.month = month;
    ba.accHolder.dateOfBirth.year = year;
    // copy parameter name to ba.accHolder.name
    strcpy(ba.accHolder.name, name);

    // copy parameter accNumber to ba.accNumber
    ba.accNumber = accNumber;
    // copy parameter accType to ba.accType
    strcpy(ba.accType, accType);
    // copy initial balance to ba.balance
    ba.balance = balance;

    // return new account
    return ba;
};

// helper fuction initAccounts
// to add some initial data to account lists
// parameters list of accounts
// return number of accounts added to list
int initAccounts(struct BankAccount accounts[MAX_ACCOUNTS]){
    int count = 5;

    accounts[0] = newAccount("John Holand", 12, 12, 1998, 1, "saving", 3456.91);
    accounts[1] = newAccount("Richard Smith", 1, 1, 1982, 2, "current", 11580.01);
    accounts[2] = newAccount("Sarah Morton", 21, 4, 1991, 3, "current", 5123.42);
    accounts[3] = newAccount("Harry Coughlin", 16, 9, 1988, 4, "saving", 8544.02);
    accounts[4] = newAccount("Sophie Parkinson", 14, 6, 1997, 5, "saving", 1886.52);

    return count;
}

// function createNewAccount 
// to create new bank account and add it into accounts list
// parameters list of accounts, number of accounts
// return updated numAccounts
int createNewAccount(struct BankAccount accounts[MAX_ACCOUNTS], int numAccounts){
    char name[30], type[15];
    int day, month, year;

    // get username, account type, date of birth of new user. 
    printf("Enter username: ");
    scanf("%s", name);
    printf("Enter account type (saving/current): ");
    scanf("%s", type);
    printf("Enter date of birth (i.e: 31 05 2001): ");
    scanf("%d %d %d", &day, &month, &year);

    // create a new bank account struct and add it to list of accounts
    accounts[numAccounts] = newAccount(name, day, month, year, numAccounts+1, type, 0);

    printf("\nAccount created successfully.. \n");
    printf("Your account number = %d \n\n", numAccounts+1);

    // return incremented number of accounts.
    return numAccounts + 1;
}

// fucntion withdraw
// to withdraw money from a specific bank account
// paramaters list of accounts, num of accounts
// return null
void withdraw(struct BankAccount accounts[MAX_ACCOUNTS], int numAccounts){
    int accountNumber, i, amount, found=0;

    // get account number from user
    printf("Enter you account number: ");
    scanf("%d", &accountNumber);

    for(i=0; i<numAccounts; i++){
        // match account number in the list with the given account number 
        if(accounts[i].accNumber == accountNumber){
             // if found then set found variable to 1
             found = 1;

            printf("\nAccount holder name: %s\n", accounts[i].accHolder.name);
            printf("Enter amount to withdraw: ");
            scanf("%d", &amount);

            // if account has more or equal amount of money
            // then withdraw request successful
            // else user will get "insuffient balance"
            if(accounts[i].balance >= amount){
                accounts[i].balance -= amount;
                printf("\nTransaction completed successfully..\n\n");
                break;
            }else{
                printf("\nInsuffient balance !! \n\n");
                break;
            }
        }
    }

    // if account not found in the list 
    // then found must be 0 
    // and user will get error message "Account not found"
    if(found == 0){
        printf("\nAccount not found !! \n\n");
    }
}

// function deposit
// to deposit money into specific account
// parameter list of account, number of accounts
// return null
void deposit(struct BankAccount accounts[MAX_ACCOUNTS], int numAccounts){
    int accountNumber, i, amount, found=0;

    // get account number from user
    printf("Enter you account number: ");
    scanf("%d", &accountNumber);

    for(i=0; i<numAccounts; i++){
        // match account number in the list with the given account number 
        if(accounts[i].accNumber == accountNumber){
            // if found then set found variable to 1
            found = 1;

            // display account holder name
            printf("\nAccount holder name: %s\n", accounts[i].accHolder.name);
            // request for account to be withdraw
            printf("Enter amount to deposit: ");
            scanf("%d", &amount);

            accounts[i].balance += amount;
            printf("\nDeposit request successful..\n\n");
            break;
        }
    }

    // if account not found in the list 
    // then found must be 0 
    // and user will get error message "Account not found"
    if(found == 0){
        printf("\nAccount not found !!\n\n");
    }
}

// function searchViaUsername
// to search and display account using username
// parameters list of account, number of accounts
// return null
void searchViaUsername(struct BankAccount accounts[MAX_ACCOUNTS], int numAccounts){
    char username[30];
    int found = 0, i;

    // get username to search
    printf("Enter username to search: ");
    scanf("%s", username);

    for(i=0; i<numAccounts; i++){
        // match account holder username with the given username
        if(strcasecmp(accounts[i].accHolder.name, username) == 0){
            // if found then set found 
            found = 1;

            // and print the account
            printf("\nAccount Found... \n\n");
            printBankAccount(accounts[i]);
            break;
        }
    }

    // if account not found in the list 
    // then found must be 0 
    // and user will get error message "Account not found"
    if(found == 0){
        printf("\nAccount not found !!\n\n");
    }
}

// function searchViaAccountNumber
// to search and display account using account number
// parameters list of account, number of accounts
// return null
void searchViaAccountNumber(struct BankAccount accounts[MAX_ACCOUNTS], int numAccounts){
    int accountNumber, found = 0, i;

    // get account number to search
    printf("Enter account number to search: ");
    scanf("%d", &accountNumber);

    for(i=0; i<numAccounts; i++){
        // match account holder username with the given username
        if(accounts[i].accNumber == accountNumber){
            // if found then set found to 1 
            found = 1;

            // and print the account
            printf("\nAccount Found... \n\n");
            printBankAccount(accounts[i]);
            break;
        }
    }

    // if account not found in the list 
    // then found must be 0 
    // and user will get error message "Account not found"
    if(found == 0){
        printf("\nAccount not found !!\n\n");
    }
}

// function searchAccountsInRange
// to print the accounts in specific range
// parameters = list of accounts, number of accounts, min range, max range
// return null
void searchAccountsInRange(struct BankAccount accounts[MAX_ACCOUNTS], int numAccounts, int min, int max){
    int i=0;

    printf("------- All account in range(%d - %d) -------\n\n", min, max);
    for(i=0; i<numAccounts; i++){
        // match account balance with the given range
        if(accounts[i].balance >= min && accounts[i].balance <= max){
            printBankAccount(accounts[i]);
        }
    }

    printf("\n");
}

// helper function displayAccountMenu
// to display menu of displaying accounts.
// parameter list of accounts, number of accounts.
// return null
void displayAccountMenu(struct BankAccount accounts[MAX_ACCOUNTS], int numAccounts){
    int choice;

    printf("\n1. Display All Accounts \n2. Display Saving Accounts \n3. Display Current Accounts");

    // get user choice
    printf("\n\nEnter choice (number): ");
    scanf("%d", &choice);

    switch (choice){
        case 1:{
            printAllAccounts(accounts, numAccounts);
            break;
        }
        case 2:{
            printSavingAccounts(accounts, numAccounts);
            break;
        }
        case 3:{
            printCurrentAccounts(accounts, numAccounts);
            break;
        }
        default:{
            printf("Invalid choice !! \n");
            break;
        }
    }
}

// helper function displaySearchMenu
// to display menu of available search queries.
// parameter list of accounts, number of accounts.
// return null
void displaySearchMenu(struct BankAccount accounts[MAX_ACCOUNTS], int numAccounts){
 int choice;

    printf("\n1. Search via username  \n2. Search via account number \n3. Search accounts in range ");
    
    // get user choice.
    printf("\n\nEnter choice (number): ");
    scanf("%d", &choice);

    switch (choice){
        case 1:{
            searchViaUsername(accounts, numAccounts);
            break;
        }
        case 2:{
            searchViaAccountNumber(accounts, numAccounts);
            break;
        }
        case 3:{
            int min, max;

            printf("Enter lower bound: ");
            scanf("%d", &min);
            printf("Enter higher bound: ");
            scanf("%d", &max);

            searchAccountsInRange(accounts, numAccounts, min, max);
            break;
        }
        default:{
            printf("Invalid choice !! \n\n");
            break;
        }
    }
}


int main(){
    // array of MAX_ACCOUNTS length to store accounts details
    struct BankAccount accounts[MAX_ACCOUNTS];

    // integer variable to store current number of active accounts.
    int numAccounts = initAccounts(accounts);
    int choice;

    do {
        printf("1. Display accounts \n2. Create new account \n3. Search an existing account \n4. Deposit \n5. Withdraw \n0. EXIT \n\n");
        
        // get user choice.
        printf("Enter choice (number): ");
        scanf("%d", &choice);

        switch (choice){
            case 1: {
                // menu to display all bank accounts
                // all accounts, saving account, current accounts
                displayAccountMenu(accounts, numAccounts);
                break;
            }
            case 2: {
                // create new account for new user
                numAccounts = createNewAccount(accounts, numAccounts);
                break;
            }
            case 3: {
                // menu to display available search queries.
                // in range, via username, via account number
                displaySearchMenu(accounts, numAccounts);
                break;
            }
            case 4: {
                // deposit money to an account
                deposit(accounts, numAccounts);
                break;
            }
            case 5: {
                // withdraw money from an account
                withdraw(accounts, numAccounts);
                break;
            }
            case 0: {
                // terminate the program
                choice = 0;
                printf("--- Terminating Program ---");
                break;
            }
            default:{
                printf("Invalid choice !! \n");
                break;
            }   
        }
    } while(choice);

    return 0;
}