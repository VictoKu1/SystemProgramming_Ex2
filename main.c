#include "myBank.h"
#define debug
char input = 'H';
int main()
{
    float amount;
    int account_number;
    int bool;
    init();
    help();
    while (input != 'E')
    {
        if (input == 'E')
        {
            shut_down();
            return 0;
        }
        else
        {
            if (input == 'O')
            {
                if (accounts_list[49][0])
                {
                    printf("Cant open new account: all accounts are occupied .\n");
                    help();
                    scanf("%c", &input);
                    continue;
                }
                printf("Please enter amount for deposit:\n");
                bool = scanf("%f", &amount);
                if (!check_amount(bool))
                {
                    help();
                    scanf("%c", &input);
                    continue;
                }
                open_new_acc(amount);
                help();
                scanf("%c", &input);
                continue;
            }
            else
            {
                if (input == 'B')
                {
                    printf("Please enter account number: \n");
                    bool = scanf("%d", &account_number);
                    if (!check_acc_number(bool, account_number, 0))
                    {
                        help();
                        scanf("%c", &input);
                        continue;
                    }
                    check_balance(account_number);
                    help();
                    scanf("%c", &input);
                    continue;
                }
                else
                {
                    if (input == 'D')
                    {
                        printf("Please enter account number: \n");
                        bool = scanf("%d", &account_number);
                        if (!check_acc_number(bool, account_number, 1))
                        {
                            help();
                            scanf("%c", &input);
                            continue;
                        }
                        printf("Please enter the amount to deposit: ");
                        bool = scanf("%f", &amount);
                        if (!check_amount(bool))
                        {
                            help();
                            scanf("%c", &input);
                            continue;
                        }
                        amount = roundf(amount * 100) / 100;
                        deposit(account_number, amount);
                        help();
                        scanf("%c", &input);
                        continue;
                    }
                    else
                    {
                        if (input == 'W')
                        {
                            printf("Please enter account number :");
                            bool = scanf("%d", &account_number);
                            if (!check_acc_number(bool, account_number, 0))
                            {
                                help();
                                scanf("%c", &input);
                                continue;
                            }
                            printf("Please enter amount to withdraw:");
                            bool = scanf("%f", &amount);
                            if (!check_amount(bool))
                            {
                                help();
                                scanf("%c", &input);
                                continue;
                            }
                            withdrawal(account_number, amount);
                            help();
                            scanf("%c", &input);
                            continue;
                        }
                        else
                        {
                            if (input == 'C')
                            {
                                printf("Please enter account number: ");
                                bool = scanf("%d", &account_number);
                                if (!check_acc_number(bool, account_number, 1))
                                {
                                    help();
                                    scanf("%c", &input);
                                    continue;
                                }
                                close_acc(account_number);
                                help();
                                scanf("%c", &input);
                                continue;
                            }
                            else
                            {
                                if (input == 'P')
                                {
                                    print();
                                    help();
                                    scanf("%c", &input);
                                    continue;
                                }
                                else
                                {
                                    if (input == 'I')
                                    {
                                        printf("Please enter amount for deposit: ");
                                        bool = scanf("%f", &amount);
                                        if (!bool || amount < 0)
                                        {
                                            printf("Failed to read the interest rate\n");
                                            scanf("%c", &input);
                                            help();
                                            continue;
                                        }
                                        add_intrest(amount);
                                        scanf("%c", &input);
                                        help();
                                        continue;
                                    }
                                    else
                                    {
                                        printf("Invalid transaction type.\n");
                                        help();
                                        scanf("%c", &input);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
#ifdef debug
    // printf("input : %c\n", input);
    // printf("account_number : %d\n", account_number);
    // printf("amount : %f\n", amount);
    // printf("\n\n");
    // account_number = 0;
    // amount = 0;
#endif
    return 0;
}

//* Inits the 50 bank accounts data base .
void init()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            accounts_list[i][j] = 0;
        }
    }
}
void help()
{
    printf("\n");
    printf("Please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
    scanf("%c", &input);
}
float roundf(float val)
{
    int temp = (int)val;
    val = temp * 1.0;
    return val;
}
int check_amount(int bool)
{
    if (!bool)
    {
        printf("Failed to read the amount\n");
    }
    return bool;
}
int check_acc_number(int bool, int number, int situation)
{
    if (!bool)
    {
        printf("Failed to read the account number\n");
        return 0;
    }
    bool = check_open(number, situation);
    return bool;
}
