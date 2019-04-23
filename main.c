/*

Title: ENG1003 Project 1 - Rotation & Substitution Cipher
Student: Nicholas O'Brien 
Student Number: 3329907

HOW TO USE THIS PROGRAM:


*/

#include <stdio.h> // fget(), stdin
#include <string.h> //stringlen() function
#include <stdlib.h>

//Define the Rotation cipher function for encrytion of type char.
void rotationEncrypt(char* message, int key);
void rotationDecrypt(char* message, int key);

//main code goes here
int main(void) {
    
    int key = 3;
    int x;
    char message[101];
    
    printf("\nPlease enter a string:\t \n"); //Ask the user for the message they wish to use.
    fgets(message, sizeof(message), stdin); //Gets the user's text input and stores it in the message variable.
    
    //printf("Please enter a key to encrypt with:\t");
    //scanf("%d", &key);
    
    printf("\nPlease choose from the following options:\n");
    printf("1 = Encryt with the Rotation Cipher.\n");
    printf("2 = Decrypt with the Rottion Ciphe.\n");
    printf("3 = Encrypt with the Substitution Cipher.\n");
    printf("4 = Decrypt with the Substitution Cipher.\n");
    printf("\nEnter a number to make your selection.\n");
    scanf("%d", &x);
    
    
    //using switch case statesments to order the selction of operations.
    switch(x) {
        case 1:
            //Print the encyrpted text
            printf("Encrypted string: ");
            
            rotationEncrypt(message, key);
            break;
            
        case 2:
            //print the decrypted text
            printf("Decrypted string: ");
            
            rotationDecrypt(message, key);
            break;
            
        default:
            printf("\nError incorrectly entered inputs.\n");
    }
}

void rotationEncrypt(char* message, int key) {
    
    int i;
    char cipher;
    int cipherValue; //this is the encryted message
    
    for(i = 0; (message[i] != '\0' && strlen(message)-1 > i); i++) {
        cipherValue = ((int)message[i] - 97 + key) % 26 + 97;
        cipher = (char)(cipherValue);
        
        printf("%c", cipher);
    }
    printf("\n");
}

void rotationDecrypt(char* message, int key) {
    
    int i;
    char cipher;
    int cipherValue;
    
    for (i=0; (message[i] != '\0' && strlen(message)-1 > i); i++) {
        cipherValue = ((int)message[i] - 97 - key) % 26 + 97;
        cipher = (char)(cipherValue);
        
        printf("%c", cipher);
    }
    printf("\n");
}