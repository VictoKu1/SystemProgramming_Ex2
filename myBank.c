#include "myBank.h"

//*Loops through all accounts and when it finds a free account the function open it.

void open_new_acc(float amount)
{
    if (check_input(amount,0))
    {
        int index = 0;
        while (accounts_list[index][0] && index < 50)
        {
            index++;
        }
         if (index >= 50)
            {
                printf("No free accounts were found.\n");
                return;
            }
        accounts_list[index][0] = 1;
        accounts_list[index][1] = amount;
        printf("New account number is: %d\n", (int)(index + converter));
    }
}

void check_balance(int account_number)
{
    int index = check_open(account_number,0);
    if (index)
    {
        printf("The balance of account number %d is: %0.2f\n", account_number, accounts_list[account_number - converter][1]);
    }
}

//*Adds amount of money equals to inputed float amount to account_number cell .

void deposit(int account_number, float amount)
{
    if (check_open(account_number,1))
    {
        if (check_input(amount,1))
        {
            int index = account_number - converter;
            accounts_list[index][1] = accounts_list[index][1] + amount;
            printf("The new balance is: %0.2f\n",accounts_list[index][1]);
        }
    }
}

//*Subtracts the amount of money from the rellevant bank acoount if that account is opened and there is enough money inside, otherwise prints a rellevant error messege .

void withdrawal(int account_number, float amount)
{
    if (check_open(account_number,2))
    {
        if (check_input(amount,2))
        {
            int index = account_number - converter;
            if (accounts_list[index][1] >= amount)
            {
                accounts_list[index][1] = accounts_list[index][1] - amount;
                printf("The new balance is: %0.2f\n",accounts_list[index][1]);
                return;
            }
            printf("Cannot withdraw more than the balance\n");
        }
    }
}

//*Closing account with the given account number, in case this account is already closed the function return a rellevant messege .

void close_acc(int account_number)
{
    int index = account_number - converter;
    if (index < 0 || index > 49)
    {
        printf("Invalid account number.\n");
        return;
    }
    if (accounts_list[index][0] == 0.0)
    {
        printf("This account is already closed.\n");
        return;
    }
    accounts_list[index][1] = 0;
    accounts_list[index][0] = 0;
    printf("Closed account number %d\n",account_number);
}

//*Adds each open account an ineterest rate - assumes the rate was chekced in the main.c section and assumes the rate is intrest_rate = x/100 .

void add_intrest(float intrest_rate)
{
    if (check_input(intrest_rate,3))
    {
        for (int i = 0; i < 50; i++)
    {
        if (accounts_list[i][0])
        {
            accounts_list[i][1] = accounts_list[i][1] + (accounts_list[i][1] * intrest_rate);
        }
    }
    }
}

//*Prints the data of every open account in the data base.

void print()
{
    for (int i = 0; i < 50; i++)
    {
        if (accounts_list[i][0])
        {
            check_balance(i + converter);
        }
    }
}

//*Closes all the accounts in the data base through makeing all the cells being equal to 0.

void shut_down()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            accounts_list[i][j] = 0;
        }
    }
}

//*This function checks if the given account number is legit and open .

int check_open(int account_number,int situation)
{
    int index = account_number - converter;
    if (index < 0 || index > 49)
    {
        printf("Invalid account number\n");
        return 0;
    }
    if (situation == 3)
    {
       return 1;
    }
    if (accounts_list[index][0] == 0.0)
    {
        printf("This account is closed\n");
        return 0;
    }
    return 1;
}
int check_input(float input,int situation)
{
    if (input >= 0)
    {
        return 1;
    }
    else
    {
        switch (situation)
        {
        case 0:
            printf("Invalid Amount\n");
            return 0;
        case 1:
            printf("Cannot deposit a negative amount\n");
            return 0;
        case 2:
            return 1;
        case 3:
            printf("Invalid interest rate\n");
            return 0;
        default:
            break;
        }
        return 0;
    }
}
