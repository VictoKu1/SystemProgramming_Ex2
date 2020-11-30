#include <stdio.h>
#include <math.h>
#include "myBank.h"
void help();
int main(){
    double amount;
    int account_number;
    char input = 'H' ;
    while ( input != 'E')
    {   
        printf("please insert a command : ");
        scanf("%c",&input);
        getchar();
        printf("your input : %c \n" ,input);
        switch (input)
        {
        case 'E':
            shut_down();
            break;
        case 'O':
            printf("you are naw opening a new account \nyour account number will be given to you \n");
            printf("first you need to enter your first deposit\n");
            printf("please enter an amount : \n");
            scanf("%lf",&amount);
            amount = round (amount * 100) / 100;
            getchar();
            open_new_acc(amount);
            break;
        case 'B':
            printf("for checking your balance : \n");
            printf("please enter an account number : \n");
            scanf("%d",&account_number);
            getchar();
            check_balance(account_number);
            break;
        case 'D' :
            printf("for depositing money \n ");
            printf("please enter an account number : \n");
            scanf("%d",&account_number);
            getchar();
            printf("please enter an amount : \n");
            scanf("%lf",&amount);
            amount = round (amount * 100) / 100;
            getchar();
           deposit(account_number,amount);
            break;
        case'W':
            printf("for withdrawing money \n ");
            printf("please enter an account number : \n");
            scanf("%d",&account_number);
            getchar();
            printf("please enter an amount : \n");
            scanf("%lf",&amount);
            amount = round (amount * 100) / 100;
            getchar();
            withdrawal(account_number,amount);
            break;
        case 'C' :
            printf("for closing your account \n");
            printf("please enter an account number : \n");
            scanf("%d",&account_number);
            getchar();
            close_acc(account_number);
            break;
        case 'P' :
            print();
            break;
        case 'I' :
            printf("for applying intrest for all accounts \n");
            printf("please enter an amount :\n");
            scanf("%lf",&amount);
            amount = round (amount * 100) / 100;
            getchar();
            add_intrest(amount);
            break;
        case 'H' :
            help();
            break;
        default:
            printf("this commands doesnt exist \n");
            printf("for help enter : H\n");
            printf("if inserting commands doesnt work press enter \n");
            break;
            }
    }
return 0;
}

void help(){
    printf(" \n the command O : open a new account \n input :  initial deposit. \n \n");
    printf(" the command B : check the balance \n input : account number. \n \n");
    printf(" the command D : deposit \n input : account number , deposit amount. \n \n");
    printf(" the command W : withdrawal \n input : account number , withdrawal amount. \n \n");
    printf(" the command C : close an account \n input : account number. \n \n");
    printf(" the command I : add an intrest rate for all accounts \n input : intrest rate.\n\n ");
    printf(" the command P : print all open accounts and their balance \n input : .\n \n");
    printf(" the command E : close all accounts and stop running \n input : .\n ");
}
