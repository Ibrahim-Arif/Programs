// Date struct
// to represent dates
// integer day (1 - 31)
// integer month (1 - 12)
// integer year ( - 2021)
struct Date {
    int day;
    int month;
    int year;
};


// Person struct
// to represent a person
// string name of max 30 characters
// struct Date of birth
struct Person {
    char name[30];
    struct Date dateOfBirth;
};


// BankAccount struct
// to represent bank account
// string account number of max 15 characters
// string account type (current / saving)
// float balance (567.50, 12000.00 etc)
// struct Person account holder
struct BankAccount {
    int accNumber;
    char accType[15];
    float balance;
    struct Person accHolder;
}; 
