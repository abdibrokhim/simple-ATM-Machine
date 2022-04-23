
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// #define totalBalance 1000000;

void menu(char pinCode[4], char cardNum[16], int clientId);
void getCardNum(char pinCode[4], char cardNum[16]);
void getPinCode(char pinCode[4], char cardNum[16]);
void validCardNum(char pinCode[4], char cardNum[16]);
void validPinCode(char pinCode[4], char cardNum[16]);
void smsInfo();
void pinChange();
void cashWithdrowal();
void cardBalance(char pinCode[4], char cardNum[16], int clientId);
void cardReturn(char pinCode[4], char cardNum[16]);
void errorCardNum(char pinCode[4], char cardNum[16]);
void errorPinCode(char pinCode[4], char cardNum[16]);
void exitOption(char pinCode[4], char cardNum[16], int clientId);



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

void cashWithdrowal()
{
    int option = 0;
    int newCash = 0;
    int minCash = 50000;
    
    long int totalBalance = 1000000;
    
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
        totalBalance - minCash;
        printf("PLEASE, TAKE YOUR CASH");
    }
    else if(option == 2)
    {
        totalBalance - (2 * minCash);
        printf("PLEASE, TAKE YOUR CASH");
    }
    else if(option == 3)
    {
        totalBalance - (3 * minCash);
        printf("PLEASE, TAKE YOUR CASH");
    }
    else if(option == 4)
    {
        totalBalance - (4 * minCash);
        printf("PLEASE, TAKE YOUR CASH");
    }
    else if(option == 5)
    {
        totalBalance - (6 * minCash);
        printf("PLEASE, TAKE YOUR CASH");
    }
    else if(option == 6)
    {
        totalBalance - (8 * minCash);
        printf("PLEASE, TAKE YOUR CASH");
    }
    else if(option == 7)
    {
        totalBalance - (10 * minCash);
        printf("PLEASE, TAKE YOUR CASH");
    }
    else if(option == 8)
    {
        printf("PLEASE, ENTER AMOUNT");
        scanf("%d", &newCash);
        
        totalBalance - newCash;
        printf("PLEASE, TAKE YOUR CASH");
    }
}

void cardBalance(char pinCode[4], char cardNum[16], int clientId)
{
    char strBalance[10] = "";
    
    int totalBalance = 0;
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
            if(clientId == line_count)
            {
                j = 0;
                for(int k = 0; k < 28; k++)
                {
                    if(k > 21)
                    {
                        strBalance[j] = line[k];
                        j++;
                    }
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
    
    exitOption(pinCode, cardNum, clientId);
}

void exitOption(char pinCode[4], char cardNum[16], int clientId)
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
        menu(pinCode, cardNum, clientId);
    }
    else if(option == 2)
    {
        cardReturn(pinCode, cardNum);
    }
}

void cardReturn(char pinCode[4], char cardNum[16])
{
    getCardNum(pinCode, cardNum);
}


////========= VALID PIN CODE =========////
void validPinCode(char pinCode[4], char cardNum[16])
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
        if((fgets(line, 1000, pin)) != NULL) 
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
                if(c == 16 && c1 == 4)
                {
                    clientId = line_count;
                    // printf("%d", clientId);
                    menu(pinCode, cardNum, clientId);
                }
                // printf("\n------\n");
            }
        }
        else 
        {
            errorPinCode(pinCode, cardNum);
        }
        // printf("\n%d | %d\n", c, c1);
        // printf("\n------\n");
    }
    fclose(pin);
}

////========= ERRORS =========////
void errorCardNum(char pinCode[4], char cardNum[16])
{
    // char cardNum[16] = "";
    
    printf("\nINVALID!\n");
    printf("ENTER CARD NUMBER: ");
    scanf("%s", cardNum);
    
    validCardNum(pinCode, cardNum);
}

void errorPinCode(char pinCode[4], char cardNum[16])
{
    // char pinCode[4] = "";
    
    printf("\nINVALID!\n");
    printf("ENTER PIN CODE: ");
    scanf("%s", pinCode);
    
    validPinCode(pinCode, cardNum);
}


////========= getCardNum =========////
void getCardNum(char pinCode[4], char cardNum[16])
{
    // char pinCode[4] = "";
    // char cardNum[16] = "";
    
    printf("PLEASE, INSERT YOUR CARD\n");
    printf("ENTER CARD NUMBER: ");
    scanf("%s", cardNum);
    
    validCardNum(pinCode, cardNum);
}

////========= getCardNum =========////
void getPinCode(char pinCode[4], char cardNum[16])
{
    // char pinCode[4] = "";
    // char cardNum[16] = "";
    
    printf("ENTER PIN CODE: ");
    scanf("%s", pinCode);
    
    validPinCode(pinCode, cardNum);
}

void validCardNum(char pinCode[4], char cardNum[16])
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
                    getPinCode(pinCode, cardNum);
                }
            }
        }
        else
        {
            errorCardNum(pinCode, cardNum);
        }
    }
    fclose(pin);
}


void menu(char pinCode[4], char cardNum[16], int clientId)
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
        cashWithdrowal();
    }
    else if(option == 5)
    {
        cardReturn(pinCode, cardNum);
    }
}

int main()
{
    char pinCode[4] = "";
    char cardNum[16] = "";
    
    getCardNum(pinCode, cardNum);
}




