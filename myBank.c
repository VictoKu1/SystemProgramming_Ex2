#include <stdio.h>
#include "myBank.h"
#define converter 901

// converter : converte account number to index : 0 = 901 - 901 , 49 = 950 - 901;

int check_open(int account_number);
float accounts_list[7][2];

// account list structure : 
// the first raw represents if the account is open or close :
// open account is  1 close is 0;
// the second account represents the balance;

//this function loop through all accounts and when it finds a close account open it
void open_new_acc(float amount){
    int bool = 1;
    for (size_t i = 0; i < 7 && bool; i++)
    {
        if (accounts_list[i][0] == 0.0)
        {
            accounts_list[i][0] = 1.0;
            accounts_list[i][1] = amount;
            printf("%d\n",(int)(i + converter));
            bool = 0;
        }
        
    }
    if(bool){
        printf("\nall accounts are full\n");
    }
}

void check_balance(int account_number){
    int index = check_open(account_number);
    if (index)
    {
        printf("%f\n",accounts_list[index - 1][1]);
    }
}
void deposit(int account_number,float amount){

}
void withdrawal(int account_number,float amount){

}
void close_acc(int account_number){

}
void add_intrest(float intrest_rate){

}
void print(){

}
void shut_down(){

}
// this function checks if the given account number is open
int check_open(int account_number){
    int index = account_number - converter;
    if(accounts_list[index][0] == 0.0){
        printf("account close\n");
        return 0;
    }
    return index + 1;
}


