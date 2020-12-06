#ifndef __MYBANK__H
#define __MYBANK__H
#include <stdio.h>
#define converter 901 //*Converter : convert accountNumber to index : 0 = 901 - 901 , 49 = 950 - 901 (index = accountNumber-converter) .
void open_new_acc(float amount);
void check_balance(int account_number);
void deposit(int account_number, float amount);
void withdrawal(int account_number, float amount);
void close_acc(int account_number);
void add_intrest(float intrest_rate);
void print();
void init(); //* Inits the 50 bank accounts data base .
void shut_down();
int check_open(int account_number, int situation);
int check_input(float input, int situation);
float accounts_list[50][2]; //*Account list structure : the first row represents if the account is open or closed, open account is 1 closed is 0, the second row represents the balance .
float roundf(float val);
void help();
int check_amount(int bool);
int check_acc_number(int bool, int number, int situation);
#endif
