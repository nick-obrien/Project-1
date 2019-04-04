#include <stdio.h>

int main () 
{
    
    char rotation;
    char substitution; 
    char method[2] = {rotation, substitution};
    
    printf("Do you want to use: \n rotation cipher? \n OR \n substitution cipher? \n Input either rotation or substitution \n");
    scanf("%s", method);
        
    printf("%s was chosen, do you want to encrypt or decrypt?\n type either encrypt or decrypt", method);
    return 0;    
}