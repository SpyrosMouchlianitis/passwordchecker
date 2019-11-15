/*A password is considered strong if below conditions are all met:

It has at least 6 characters and at most 20 characters.
It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.*/


#include <stdio.h>
#include <ctype.h>

int main(){
    int errors;
    int charcount=0;
    int upper=0;
    int lower=0;
    int digits=0;
    int triple=0;
    int i;
    char psw[20];
    printf("Enter a password\n");
    scanf("%s", psw);
    
    
    do
    {
        errors=0;
        charcount=0;
        //Checks the password's length
        for (i = 0; psw[i]; i++)
        {
            charcount += 1;
        }
        if (charcount<6)
        {
            printf("Password must be longer than 6 characters\n");
            errors++;
        }else if (charcount>20)
        {
            printf("Password must be no longer than 20 characters\n");
            errors++;
        }


        //Checks if the password has one lower case and one upper case character
        for ( i = 0; psw[i]!='\0'; i++)
        {
            if (psw[i]>='A' && psw[i]<='Z')
            {
                upper++;
            }
            
            if (psw[i]>='a' && psw[i]<='z')
            {
                lower++;
            }
            
        }
        if (lower==0)
        {
            printf("The password needs at least 1 lower case character\n");
            errors++;
        }
        if (upper==0)
        {
            printf("The password needs at least 1 upper case character\n");
            errors++;
        }
        

        //Checks if the password has at least one digit
        for ( i = 0; psw[i]!='\0'; i++)
        {
            if (psw[i]>='0' && psw[i]<='9')
            {
                digits++;
            }
        }
        if (digits==0)
        {
            printf("The password needs at least 1 digit\n");
            errors++;
        }
        

        //Checks if the password has three same letters in a row e.x("...aaa...")
        triple=0;
        for ( i = 0; psw[i]!='\0'; i++)
        {
            if (psw[i]==psw[i+1] && psw[i+1]==psw[i+2])
            {
                triple++;
            }
            
        }
        
        if (triple!=0)
        {
            printf("Do not use the same characters in a row e.x(...aaa...)\n");
            errors++;
        }


        if(errors!=0){
            printf("Try a different password\n");
            scanf("%s", psw);
        }
    } while (errors!=0);
    
    if (errors==0)
    {
        printf("Congratulations! Your password is very strong\n");
    }
    
    return 0;
}
