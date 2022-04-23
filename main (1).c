
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// #define totalBalance 1000000;

void menu(char pinCode[4], char cardNum[16], int clientId, char strBalance[16]);
void getCardNum(char pinCode[4], char cardNum[16], char strBalance[16]);
void getPinCode(char pinCode[4], char cardNum[16], char strBalance[16]);
void validCardNum(char pinCode[4], char cardNum[16], char strBalance[16]);
void validPinCode(char pinCode[4], char cardNum[16], char strBalance[16]);
void smsInfo();
void pinChange();
void cashWithdrowal(int clientId);
void cardBalance(char pinCode[4], char cardNum[16], int clientId);
void cardReturn(char pinCode[4], char cardNum[16], char strBalance[16]);
void errorCardNum(char pinCode[4], char cardNum[16], char strBalance[16]);
void errorPinCode(char pinCode[4], char cardNum[16], char strBalance[16]);
void exitOption(char pinCode[4], char cardNum[16], int clientId, char strBalance[16]);



void smsInfo()
{
    int phoneNum = 0;
    
    printf("ENTER PHONE NUMBER: ");
    scanf("%d", &phoneNum);
}

void pinChange()
{
    printf("Hello");
}

void cashWithdrowal(int clientId)
{
    char strBalance[16] = "";
    
    char line[1000] = {0};
    unsigned int line_count = 0;
    
    int j = 0;
    // int n = all_line;
    
    FILE *pin;
    
    pin = fopen("pin.txt", "r");
    for(int i = 0; i < 5; i++)
    {
        while((fgets(line, 1000, pin)) != NULL)
        {
            line_count++;
            j = 0;
            if(line_count == clientId)
            {
                for(int k = 0; k < 30; k++)
                {
                    if(k > 20)
                    {
                        strBalance[j] = line[k];
                        j++;
                    }
                    // else continue;
                }
            }
        }
        // else
        // {
        //     errorCardNum(pinCode, cardNum);
        // }
    }
    fclose(pin);
    
    
    char pinCode[4] = "";
    char cardNum[16] = "";
    
    int option = 0;
    int newCash = 0;
    int minCash = 50000;
    
    int withdrowCash = 0;
    int leftCash = 0;
    
    int totalBalance = atoi(strBalance);
    
    printf("\nTotal Balance Int: %d\n", totalBalance);
    printf("\nTotal Balance String: %s\n", strBalance);
    
    printf("\n");
    printf("[1]-> 50 000\n");
    printf("[2]-> 100 000\n");
    printf("[3]-> 150 000\n");
    printf("[4]-> 200 000\n");
    printf("[5]-> 300 000\n");
    printf("[6]-> 400 000\n");
    printf("[7]-> 500 000\n");
    printf("[8]-> OTHER AMOUNT\n");
    
    printf("\n");
    printf("[+]-> ");
    
    scanf("%d", &option);
    
    if(option == 1)
    {
        withdrowCash = minCash;
        leftCash = totalBalance - withdrowCash;
        printf("PLEASE, TAKE YOUR CASH: %d", minCash);
        printf("\nBALANCE: %d\n", leftCash);
    }
    else if(option == 2)
    {
        withdrowCash = 2 * minCash;
        leftCash = totalBalance - withdrowCash;
        printf("PLEASE, TAKE YOUR CASH: %d", withdrowCash);
        printf("\nBALANCE: %d", leftCash);
    }
    else if(option == 3)
    {
        withdrowCash = 3 * minCash;
        leftCash = totalBalance - withdrowCash;
        printf("PLEASE, TAKE YOUR CASH: %d", withdrowCash);
        printf("\nBALANCE: %d", leftCash);
    }
    else if(option == 4)
    {
        withdrowCash = 4 * minCash;
        leftCash = totalBalance - withdrowCash;
        printf("PLEASE, TAKE YOUR CASH: %d", withdrowCash);
        printf("\nBALANCE: %d", leftCash);
    }
    else if(option == 5)
    {
        withdrowCash = 6 * minCash;
        leftCash = totalBalance - withdrowCash;
        printf("PLEASE, TAKE YOUR CASH: %d", withdrowCash);
        printf("\nBALANCE: %d", leftCash);
    }
    else if(option == 6)
    {
        withdrowCash = 8 * minCash;
        leftCash = totalBalance - withdrowCash;
        printf("PLEASE, TAKE YOUR CASH: %d", withdrowCash);
        printf("\nBALANCE: %d", leftCash);
    }
    else if(option == 7)
    {
        withdrowCash = 10 * minCash;
        leftCash = totalBalance - withdrowCash;
        printf("PLEASE, TAKE YOUR CASH: %d", withdrowCash);
        printf("\nBALANCE: %d", leftCash);
    }
    else if(option == 8)
    {
        printf("PLEASE, ENTER AMOUNT: ");
        scanf("%d", &newCash);
        
        withdrowCash = newCash;
        leftCash = totalBalance - withdrowCash;
        printf("PLEASE, TAKE YOUR CASH: %d", withdrowCash);
        printf("\nBALANCE: %d", leftCash);
    }
    
    // getCardNum(pinCode, cardNum, strBalance);
    exitOption(pinCode, cardNum, clientId, strBalance);
}

void cardBalance(char pinCode[4], char cardNum[16], int clientId)
{
    char strBalance[16] = "";
    
    char line[1000] = {0};
    unsigned int line_count = 0;
    
    int j = 0;
    // int n = all_line;
    
    FILE *pin;
    
    pin = fopen("pin.txt", "r");
    for(int i = 0; i < 5; i++)
    {
        while((fgets(line, 1000, pin)) != NULL)
        {
            line_count++;
            j = 0;
            if(line_count == clientId)
            {
                for(int k = 0; k < 30; k++)
                {
                    if(k > 20)
                    {
                        strBalance[j] = line[k];
                        j++;
                    }
                    // else continue;
                }
            }
        }
        // else
        // {
        //     errorCardNum(pinCode, cardNum);
        // }
    }
    fclose(pin);
    
    printf("\n");
    printf("YOUR BALANCE: %s", strBalance);
    
    exitOption(pinCode, cardNum, clientId, strBalance);
}

void exitOption(char pinCode[4], char cardNum[16], int clientId, char strBalance[16])
{
    int option = 0;
    
    printf("\n\n");
    printf("[1]-> BACK\n");
    printf("[2]-> END SESSION\n");
    
    printf("\n");
    printf("[+]-> ");
    
    scanf("%d", &option);
    
    if(option == 1)
    {
        menu(pinCode, cardNum, clientId, strBalance);
    }
    else if(option == 2)
    {
        cardReturn(pinCode, cardNum, strBalance);
    }
}

void cardReturn(char pinCode[4], char cardNum[16], char strBalance[16])
{
    getCardNum(pinCode, cardNum, strBalance);
}


////========= VALID PIN CODE =========////
void validPinCode(char pinCode[4], char cardNum[16], char strBalance[16])
{
    char str[16] = "";
    char str1[4] = "";
    
    char line[1000] = {0};
    unsigned int line_count = 0;
    int clientId = 0;
    
    int j = 0;
    int c = 0;
    int c1 = 0;
    int z = 0;
    
    FILE *pin;
    
    pin = fopen("pin.txt", "r");
    for(int i = 0; i < 1;)
    {
        while((fgets(line, 1000, pin)) != NULL) 
        {
            line_count++;
            
            j = 0;
            z = 0;
            for(int k = 0; k < 21; k++)
            {
                if(k < 16)
                {
                    str[j] = line[k];
                    j++;
                }
                else if(k > 16)
                {
                    str1[z] = line[k];
                    z++;
                }
            }
            //Sometimes do not work properly [c]
            c = 1;
            c1 = 0;
            j = 0;
            z = 0;
            for(int k = 0; k < 21; k++)
            {
                if(k < 16)
                {
                    if(cardNum[j] == str[k])
                    {
                        c++;
                    }
                    j++;
                    
                }
                else if(k > 16)
                {
                    if(pinCode[z] == str1[z])
                    {
                        c1++;
                    }
                    z++;
                }
                // printf("\n%d | %d\n", c, c1);
                if(c >= 16 && c1 == 4)
                {
                    clientId = line_count;
                    // printf("clientId: %d", clientId);
                    menu(pinCode, cardNum, clientId, strBalance);
                }
                // printf("\n------\n");
            }
        }
        errorPinCode(pinCode, cardNum, strBalance);
        // else 
        // {
        //     errorPinCode(pinCode, cardNum, strBalance);
        // }
        // printf("\n%d | %d\n", c, c1);
        // printf("\n------\n");
    }
    fclose(pin);
}

////========= ERRORS =========////
void errorCardNum(char pinCode[4], char cardNum[16], char strBalance[16])
{
    // char cardNum[16] = "";
    
    printf("\nINVALID!\n");
    printf("ENTER CARD NUMBER: ");
    scanf("%s", cardNum);
    
    validCardNum(pinCode, cardNum, strBalance);
}

void errorPinCode(char pinCode[4], char cardNum[16], char strBalance[16])
{
    // char pinCode[4] = "";
    
    printf("\nINVALID!\n");
    printf("ENTER PIN CODE: ");
    scanf("%s", pinCode);
    
    validPinCode(pinCode, cardNum, strBalance);
}


////========= getCardNum =========////
void getCardNum(char pinCode[4], char cardNum[16], char strBalance[16])
{
    // char pinCode[4] = "";
    // char cardNum[16] = "";
    
    printf("\nPLEASE, INSERT YOUR CARD\n");
    printf("ENTER CARD NUMBER: ");
    scanf("%s", cardNum);
    
    validCardNum(pinCode, cardNum, strBalance);
}

////========= getCardNum =========////
void getPinCode(char pinCode[4], char cardNum[16], char strBalance[16])
{
    // char pinCode[4] = "";
    // char cardNum[16] = "";
    
    printf("ENTER PIN CODE: ");
    scanf("%s", pinCode);
    
    validPinCode(pinCode, cardNum, strBalance);
}

void validCardNum(char pinCode[4], char cardNum[16], char strBalance[16])
{
    char str[16] = "";
    char line[1000] = {0};
    unsigned int line_count = 0;
    
    int j = 0;
    int c = 0;
    
    FILE *pin;
    
    pin = fopen("pin.txt", "r+");
    for(int i = 0; i < 1;)
    {
        if((fgets(line, 1000, pin)) != NULL) 
        {
            line_count++;
            j = 0;
            for(int k = 0; k < 16; k++)
            {
                str[j] = line[k];
                j++;
            }
            c = 0;
            j = 0;
            for(int k = 0; k < 16; k++)
            {
                if(cardNum[j] == str[k])
                {
                    c++;
                }
                j++;
                
                if(c == 16)
                {
                    getPinCode(pinCode, cardNum, strBalance);
                }
            }
        }
        else
        {
            errorCardNum(pinCode, cardNum, strBalance);
        }
    }
    fclose(pin);
}


void menu(char pinCode[4], char cardNum[16], int clientId, char strBalance[16])
{
    int option = 0;
    
    printf("\n");
    printf("[1]-> SMS INFORMATION\n");
    printf("[2]-> PIN CHANGE\n");
    printf("[3]-> CARD BALANCE\n");
    printf("[4]-> CASH WITHDROWAL\n");
    printf("[5]-> RETURN CARD\n");
    
    printf("\n");
    printf("[+]-> ");
    
    scanf("%d", &option);
    
    if(option == 1)
    {
        smsInfo();
    }
    else if(option == 2)
    {
        pinChange();
    }
    else if(option == 3)
    {
        cardBalance(pinCode, cardNum, clientId);
    }
    else if(option == 4)
    {
        cashWithdrowal(clientId);
    }
    else if(option == 5)
    {
        cardReturn(pinCode, cardNum, strBalance);
    }
}

int main()
{
    char pinCode[4] = "";
    char cardNum[16] = "";
    char strBalance[16] = "";
    
    getCardNum(pinCode, cardNum, strBalance);
}




