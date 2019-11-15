/*A password is considered strong if below conditions are all met:

It has at least 6 characters and at most 20 characters.
It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.*/


#include <stdio.h>
#include <ctype.h>

int main(){
    int charcount=0;
    int upper=0;
    int lower=0;
    int digits=0;
    int triple=0;
    int i;
    int symbols=0;
    int strength;
    char psw[20];
    printf("Enter a password\n");
    scanf("%s", psw);
    
    do
    {
        strength=5;
        charcount=0;
        //Checks the password's length
        for (i = 0; psw[i]; i++)
        {
            charcount += 1;
        }
        if (charcount<6)
        {
            printf("Password must be longer than 6 characters\n");

        }else if (charcount>20)
        {
            printf("Password must be no longer than 20 characters\n");

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
            printf("The password should have at least 1 lower case character\n");
            strength--;
        }
        if (upper==0)
        {
            printf("The password should have at least 1 upper case character\n");
            strength--;
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
            printf("The password should have at least 1 digit\n");
            strength--;
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
            strength--;
        }


        //Check if the password has symbols
        symbols=0;
        for ( i = 0; psw[i]!='\0'; i++)
        {
            if (ispunct(psw[i]))
            {
                symbols++;
            }
            
        }
        if (symbols==0)
        {
            printf("It is advised to use symbols for even more protection\n");
            strength--;
        }
        


        if(charcount<6 || charcount>20){
            printf("Try a different password\n");
            scanf("%s", psw);
        }
    } while (charcount<6 || charcount>20);
    
    if (strength==5)
    {
        printf("Congratulations! Your password is very strong\n");
    }
    if (strength==4)
    {
        printf("Your password is strong\n");
    }
    if (strength==3)
    {
        printf("Your password has medium strength\n");
    }
    if (strength==2)
    {
        printf("Your password is unsafe\n");
    }
    if(strength==1)
    {
        printf("Your password is very unsafe\n");
    }


    return 0;
}