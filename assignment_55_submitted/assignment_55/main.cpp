#include <bits/stdc++.h>
using namespace std;

struct Account {
    int accountNumber;
    char name[1000];
    char email[1000];
    char contact[1000];
    float balance;
    char password[1000];
};

const string adminPass = "HelloWorld";
set<int> database;

void createAccount();
void viewAccount();
void deposit();
void withdraw();
void listAccounts();
void deleteAccount();
void showLog();
void transaction();

void dynamicFileName(char fileName[], int num);
void sensitiveContent(char fileName[], int num);
bool validityCheck(FILE*& fptr, FILE*& sen, char (&fileName)[1000], char (&senName)[1000]);

int main() {
    int choice;

    FILE *data = fopen("database.bin", "ab+");

    if (data == NULL)
    {
        cout << "Error" << endl;
        return 1;
    }

    rewind(data);

    int acc;

    while (fread(&acc, sizeof(int), 1, data) != 0)
    {
        if (acc != -1)
        database.insert(acc);
    }

    fclose(data);

    do {
        printf("\n=== Banking System Menu ===\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. List All Accounts\n");
        printf("6. Delete Account\n");
        printf("7. Transaction\n");
        printf("8. Show log\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccount(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: listAccounts(); break;
            case 6: deleteAccount(); break;
            case 7: transaction(); break;
            case 8: showLog(); break;
            case 9: printf("Exiting...\n"); break;

            default: printf("Invalid choice!\n");
        }
    } while (choice != 9);

    return 0;
}

// Function Definitions
void createAccount()
{
    Account newAcc;

    cout << "Enter Account Number: ";
    scanf("%d", &newAcc.accountNumber);

    FILE *data = fopen("database.bin", "a+");

    if (data == NULL)
    {
        cout << "Error" << endl;
        return;
    }

    if (database.find(newAcc.accountNumber) != database.end())
    {
        cout << endl;
        cout << "Account Number Already Exists" << endl;
        return;
    }

    else
    {
        database.insert(newAcc.accountNumber);
        fwrite(&newAcc.accountNumber, sizeof(int), 1, data);
    }

    cout << "Enter Your Name: ";
    scanf(" %[^\n]", newAcc.name);

    cout << "Enter Your Email: ";
    scanf("%s", newAcc.email);

    cout << "Enter Your Contact Number: ";
    scanf("%s", newAcc.contact);

    cout << "Enter Balance: ";
    scanf("%f", &newAcc.balance);

    cout << "Enter Password: ";
    scanf("%s", newAcc.password);

    char fileName[1000], sensitiveName[1000];;

    dynamicFileName(fileName, newAcc.accountNumber);
    sensitiveContent(sensitiveName, newAcc.accountNumber);

    FILE *fptr = fopen(fileName, "w+");
    FILE *sen = fopen(sensitiveName, "wb+");

    if (fptr == NULL || sen == NULL)
    {
        cout << "Error" << endl;
        return;
    }

    fprintf(fptr, "%d\n", newAcc.accountNumber);
    fprintf(fptr, "%s\n", newAcc.name);
    fprintf(fptr, "%s\n", newAcc.email);
    fprintf(fptr, "%s\n", newAcc.contact);

    fwrite(&newAcc.balance, sizeof(float), 1, sen);
    fwrite(&newAcc.password, sizeof(char), sizeof(newAcc.password), sen);

    cout << endl;
    cout << "New Account was created!" << endl << endl;

    fclose(fptr);
    fclose(data);
    fclose(sen);

    FILE *log = fopen("log.txt", "ab+");

    if (log == NULL)
    {
        cout << "Error" << endl;
        return;
    }

    fprintf(log, "%s has created a new account!\n\n", newAcc.name);

    fclose(log);
}

void viewAccount()
{
    FILE *fptr = NULL, *sen = NULL;
    char fileName[1000], senName[1000];

    if (!validityCheck(fptr, sen, fileName, senName))
    return;

    Account details;
    
    fscanf(fptr, "%d", &details.accountNumber);
    fscanf(fptr, " %[^\n]", details.name);
    fscanf(fptr, "%s", details.email);
    fscanf(fptr, "%s", details.contact);
    
    rewind(sen);
    fread(&details.balance, sizeof(float), 1, sen);

    cout << endl;
    printf("Name: %s\nEmail: %s\nContact: %s\nBalance: %f", details.name, details.email, details.contact, details.balance);
    cout << endl;

    fclose(fptr);
    fclose(sen);

    FILE *log = fopen("log.txt", "ab+");

    if (log == NULL)
    {
        cout << "Error" << endl;
        return;
    }

    fprintf(log, "%s has viewed their account!\n\n", details.name);

    fclose(log);
}

void deposit()
{
    FILE *fptr = NULL, *sen = NULL;
    char fileName[1000], senName[1000];

    if (!validityCheck(fptr, sen, fileName, senName))
    return;

    Account details;

    fscanf(fptr, "%d", &details.accountNumber);
    fscanf(fptr, " %[^\n]", details.name);
    
    float depositAmount, newAmount, curAmount;

    cout << "Enter your Deposit Amount: ";
    cin >> depositAmount;
    cout << endl;
    
    rewind(sen);

    fread(&curAmount, sizeof(float), 1, sen);

    newAmount = curAmount + depositAmount;

    rewind(sen);

    fwrite(&newAmount, sizeof(float), 1, sen);

    cout << "Deposit Successful!\nNew Amount is " << newAmount << endl;

    fclose(fptr);
    fclose(sen);

    FILE *log = fopen("log.txt", "ab+");

    if (log == NULL)
    {
        cout << "Error" << endl;
        return;
    }

    fprintf(log, "%s has deposited %f amount to their account!\n\n", details.name, depositAmount);

    fclose(log);
}

void withdraw()
{
    FILE *fptr = NULL, *sen = NULL;
    char fileName[1000], senName[1000];

    if (!validityCheck(fptr, sen, fileName, senName))
    return;

    Account details;

    fscanf(fptr, "%d", &details.accountNumber);
    fscanf(fptr, " %[^\n]", details.name);

    float withdrawAmount, newAmount, curAmount;

    cout << "Enter your Withdraw Amount: ";
    cin >> withdrawAmount;
    cout << endl;
    
    rewind(sen);

    fread(&curAmount, sizeof(float), 1, sen);

    if (withdrawAmount > curAmount)
    {
        cout << "Not enough money" << endl;
        return;
    }

    newAmount = curAmount - withdrawAmount;

    rewind(sen);

    fwrite(&newAmount, sizeof(float), 1, sen);

    cout << "Withdraw Successful!\nNew Amount is " << newAmount << endl;

    fclose(fptr);
    fclose(sen);

    FILE *log = fopen("log.txt", "ab+");

    if (log == NULL)
    {
        cout << "Error" << endl;
        return;
    }

    fprintf(log, "%s has withdrawn %f amount from their account!\n\n", details.name, withdrawAmount);

    fclose(log);
}

void listAccounts()
{
    string userInput;
    cout << "Enter Admin Password: ";
    cin >> userInput;
    cout << endl;
    if (userInput != adminPass)
    {
        cout << "Access Denied" << endl;
        return;
    }

    int toFind;
    int serial = 1;

    if (database.empty())
    {
        cout << "No account Available" << endl;
        return;
    }

    for (auto it = database.begin(); it != database.end(); it++)
    {
        toFind = *it;
        
        cout << "Account " << serial << ":\n";
        serial++;

        char fileName[1000];

        dynamicFileName(fileName, toFind);

        FILE *fptr = fopen(fileName, "r+");

        if (fptr == NULL)
        {
            cout << "Error" << endl;
            return;
        }

        Account details;

        fscanf(fptr, "%d", &details.accountNumber);
        fscanf(fptr, " %[^\n]", details.name);
        fscanf(fptr, "%s", details.email);
        fscanf(fptr, "%s", details.contact);

        cout << "Account Number: " << details.accountNumber << endl;
        cout << "Owner: " << details.name << endl;
        cout << "Email: " << details.email << endl;
        cout << "Contact: " << details.contact << endl;
        cout << endl << endl;

        fclose(fptr);
    }
}

void deleteAccount()
{
    FILE *fptr = NULL, *sen = NULL;
    char fileName[1000], senName[1000];

    if (!validityCheck(fptr, sen, fileName, senName))
    return;

    int toDlt;
    char ch;

    cout << "Do you really want to delete you account? (y/n) ";
    cin >> ch;

    if (ch == 'n')
    {
        cout << "Process Terminated" << endl;
        return;
    }

    cout << "Retype your account to confirm: ";
    cin >> toDlt;

    database.erase(toDlt);

    FILE *data = fopen("database.bin", "rb+");

    if (data == NULL)
    {
        cout << "Error" << endl;
        fclose(fptr);
        fclose(sen);
        return;
    }

    int temp;

    while (fread(&temp, sizeof(int), 1, data) != 0)
    {
        if (temp == toDlt)
        {
            fseek(data, -sizeof(int), SEEK_CUR);
            int in = -1;
            fwrite(&in, sizeof(int), 1, data);
            break;
        }
    }

    fclose(fptr);
    fclose(sen);
    fclose(data);

    cout << endl;

    if (remove(fileName) == 0 && remove(senName) == 0)
    printf("File deleted successfully.\n");

    else
    printf("Unable to delete the file.\n");

    FILE *log = fopen("log.txt", "ab+");

    if (log == NULL)
    {
        cout << "Error" << endl;
        return;
    }

    fprintf(log, "Account %d was deleted!\n\n", toDlt);

    fclose(log);
}

void transaction()
{
    FILE *fptr = NULL, *sen = NULL;
    char fileName[1000], senName[1000];

    if (!validityCheck(fptr, sen, fileName, senName))
    return;

    Account details;

    fscanf(fptr, "%d", &details.accountNumber);
    fscanf(fptr, " %[^\n]", details.name);

    int rec;
    cout << "Enter Receiver Account Number: ";
    cin >> rec;

    if (database.find(rec) == database.end())
    {
        cout << "Receiver account doesn't exist" << endl;
        return;
    }

    float amount;
    cout << "Enter Amount: ";
    cin >> amount;

    rewind(sen);

    float curAmount;
    fread(&curAmount, sizeof(float), 1, sen);

    if (amount > curAmount)
    {
        cout << "Not enough Money to send" << endl;
        return;
    }

    rewind(sen);

    char recFileName[1000];
    sensitiveContent(recFileName, rec);

    FILE *recPtr = fopen(recFileName, "rb+");

    if (recPtr == NULL)
    {
        cout << "Error" << endl;
        fclose(sen);
        fclose(fptr);
        return;
    }

    float curAmount2;
    fread(&curAmount2, sizeof(float), 1, recPtr);
    rewind(recPtr);

    float newAmount2 = curAmount2 + amount;
    float newAmount = curAmount - amount;

    fwrite(&newAmount, sizeof(float), 1, sen);
    fwrite(&newAmount2, sizeof(float), 1, recPtr);

    cout << endl;
    cout << "Transaction was successful!\nYou new balance is: " << newAmount << endl;

    fclose(recPtr);
    fclose(sen);
    fclose(fptr);

    FILE *log = fopen("log.txt", "ab+");

    if (log == NULL)
    {
        cout << "Error" << endl;
        return;
    }

    fprintf(log, "Account %d sent money to Account %d!\n\n", details.accountNumber, rec);

    fclose(log);
}

void showLog()
{
    string userInput;
    cout << "Enter Admin Password: ";
    cin >> userInput;
    cout << endl;

    if (userInput != adminPass)
    {
        cout << "Access Denied" << endl;
        return;
    }

    FILE *log = fopen("log.txt", "rb+");

    if (log == NULL)
    {
        cout << "Nothing to Show" << endl;
        return;
    }

    char ch;

    while (fscanf(log, "%c", &ch) != EOF)
    cout << ch;

    fclose(log);
}

void dynamicFileName(char fileName[], int num)
{
    string s = "account_";
    string temp = to_string(num);

    s = s + temp;

    s += ".txt";

    for (int i = 0; i < s.size(); i++)
    {
        fileName[i] = s[i];
    }

    fileName[s.size()] = '\0';
}

void sensitiveContent(char fileName[], int num)
{
    string s = "sensitive_";
    string temp = to_string(num);

    s = s + temp;

    s += ".bin";

    for (int i = 0; i < s.size(); i++)
    {
        fileName[i] = s[i];
    }

    fileName[s.size()] = '\0';
}

bool validityCheck(FILE*& fptr, FILE*& sen, char (&fileName)[1000], char (&senName)[1000])
{
    int toFind;
    char userInput[1000];

    cout << "Enter your Account Number: ";
    cin >> toFind;

    if (database.find(toFind) == database.end())
    {
        cout << endl;
        cout << "Account Number Does Not Exist" << endl;
        if (fptr != NULL) fclose(fptr);
        if (sen != NULL) fclose(sen);
        return false;
    }

    cout << "Enter your Account Password: ";
    scanf("%s", userInput);

    dynamicFileName(fileName, toFind);
    sensitiveContent(senName, toFind);

    fptr = fopen(fileName, "r+");
    sen = fopen(senName, "rb+");

    if (fptr == NULL || sen == NULL)
    {
        cout << endl;
        cout << "Error" << endl;
        if (fptr != NULL) fclose(fptr);
        if (sen != NULL) fclose(sen);
        return false;
    }

    char pass[1000];

    fseek(sen, sizeof(float), SEEK_SET);
    fread(pass, sizeof(char), 1000, sen);

    if (strcmp(userInput, pass) != 0)
    {
        cout << endl;
        cout << "Access Denied\n";
        if (fptr != NULL) fclose(fptr);
        if (sen != NULL) fclose(sen);
        return false;
    }

    rewind(sen);

    return true;
}

