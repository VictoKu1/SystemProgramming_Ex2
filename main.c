#include <stdio.h>
#include "myBank.h"
float roundf(float val);
void help();
int check_amount(int bool);
int check_acc_numbet(int bool,int number);
int main(){
    float amount;
    int account_number;
    int bool;
    char input = 'H' ;
    while ( input != 'E')
    {   
        help();
        scanf("%c",&input);
        switch (input)
        {
        case 'E':
            shut_down();
            break;
        case 'O':
            printf("Please enter amount for deposit: ");
            bool = scanf("%f",&amount);
            if(!check_amount(bool)){ break;}
            amount = roundf(amount * 100) / 100;
            open_new_acc(amount);
            break;
        case 'B':
            printf("Please enter account number: ");
            bool = scanf("%d",&account_number);
            if(!check_acc_numbet(bool,account_number)){ break;}
            check_balance(account_number);
            break;
        case 'D' :
            printf("Please enter account number: ");
            bool = scanf("%d",&account_number);
            if(!check_acc_numbet(bool,account_number)){ break;}
            printf("Please enter amount for deposit: ");
            bool = scanf("%f",&amount);
            if(!check_amount(bool)){ break;}
            amount = roundf(amount * 100) / 100;
           deposit(account_number,amount);
            break;
        case'W':
            printf("Please enter account number: ");
            bool = scanf("%d",&account_number);
            if(!check_acc_numbet(bool,account_number)){ break;}
            printf("Please enter amount for deposit: ");
            bool = scanf("%f",&amount);
            if(!check_amount(bool)){ break;}
            amount = roundf(amount * 100) / 100;
            withdrawal(account_number,amount);
            break;
        case 'C' :
            printf("Please enter account number: ");
           bool = scanf("%d",&account_number);
            if(!check_acc_numbet(bool,account_number)){ break;}
            close_acc(account_number);
            break;
        case 'P' :
            print();
            break;
        case 'I' :
            printf("Please enter amount for deposit: ");
            bool = scanf("%f",&amount);
            if(!check_amount(bool)){ break;}
            amount = roundf(amount * 100) / 100;
            add_intrest(amount);
            break;
        default:
            printf("Invalid transaction type\n");
            break;
            }
    }
return 0;
}

void help(){
    printf("\n");
    printf("Please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
}
float roundf(float val){
    int temp = (int) val;
    val = temp*1.0;
    return val;
}
int check_amount(int bool){
    if (!bool)
    {
        printf("Failed to read the amount\n");
    }
    return bool;
}
int check_acc_numbet(int bool,int number){
    if (!bool)
    {
        printf("Failed to read the account number\n");
        return 0;
    }
    bool = check_open(number);
    return bool;
}

