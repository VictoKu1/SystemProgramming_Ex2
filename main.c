#include <stdio.h>

int main(){
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
            break;
        case 'O':
            printf("%c\n",input);
            break;
        case 'B':
            printf("%c\n",input);
            break;
        case 'D' :
            printf("%c\n",input);
            break;
        case'W':
            printf("%c\n",input);
            break;
        case 'C' :
            printf("%c\n",input);
            break;
        case 'P' :
            printf("%c\n",input);
            break;
        case 'I' :
            printf("%c\n",input);
            break;
        case 'H' :
            printf("%c\n",input);
            break;
        default:
            printf("this commands doesnt exist \n");
            printf("for help enter : H\n");
            break;
            }
    }
return 0;
}


