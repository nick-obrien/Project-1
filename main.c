/*

Title: ENG1003 Programming Assignment 1 - C Cipher
Student Name: Nicholas O'Brien 
Student Number: 3329907

HOW TO USE THIS PROGRAM:

Substitution Key:
ZAQWSXCDERFVBGTYHNMJUIKLOP

ABCDEFGHIJKLMNOPQRSTUVWXYZ

*/

#include <stdio.h> //Functions to perform input & output.
#include <string.h> //Functions for maniulating arrays of characters.
#include <ctype.h> // Library useful for testing and mapping characters.
#include <stdlib.h> //Functions for performing general functions.

//Define the Rotation cipher function for encrytion.
void rotationEncrypt(char* message, int key);
//Define the Rotation cipher function for decryption.
void rotationDecrypt(char* message, int key);
//Define the Brute force Decryption cipher function.
void bruteRotation(char* message, int key);

//main code goes here
int main(void) {
    
    int operation, key; //declared integers for
    char message[100]; //This is the array which holds the user's message to be used in the Cipher.
    
    
    printf("Please enter a string:\t"); //Ask the user for the message they wish to use.
    fgets(message, sizeof(message), stdin); //Gets the user's text input and stores it in the message variable.
    
    printf("\nPlease choose from the following options:\n");
    printf("1 = Encryt with the Rotation Cipher.\n");
    printf("2 = Decrypt with the Rotation Cipher.\n");
    printf("3 = Encrypt with the Substitution Cipher.\n");
    printf("4 = Decrypt with the Substitution Cipher.\n");
    printf("\nEnter a number to make your selection:\t");
    scanf("%d", &operation);
    fflush(stdin);
    
    
    //using switch case statesments to order the selction of operations / performable tasks..
    switch(operation) {
        case 1: // Encryption with Rotation cipher
            fflush(stdin);
            printf("\nEncryption with Rotation Cipher selected.\n");
            printf("Enter the Rotation Cipher Key (0-25):\t");
            scanf("%d", &key); 
            fflush(stdin);
            
            //Print the encyrpted text
            printf("\nEncrypted message: ");
            
            rotationEncrypt(message, key);
            break;
            
        case 2: // Decryption with Rotation cipher
            fflush(stdin);
            printf("\nDecryption with Rotation Cipher selected.\n");
            printf("Enter the Rotation Cipher Key (0-25):\t");
            scanf("%d", &key);
            fflush(stdin);
            //print the decrypted text
            printf("\nDecrypted message: ");
            
            rotationDecrypt(message, key);
            break;
            
        case 3:
        /*    
        case 3: // Brute force rotation decryption
            printf("\nBrute force Decryption selected.\n");
            for(key = 1; key <= 26; key++) {
                bruteRotation(message, key);
                printf("Key: %d Decryption: %s \n", key, message);
                //strcpy(message);
            }
            break;
         */   
        default:
            printf("\nError incorrectly entered inputs.\n");
    }

}

void rotationEncrypt(char* message, int key) {
    
    int i; //integer variable to reference each character
    
    for(i = 0; message[i] != '\0'; ++i) {
        
        
        if(message[i] >= 'a' && message[i] <= 'z') {
                message[i] = message[i] + key - 32; //Encrypt input message & convert any lower case characters to uppercase.
            
            if(message[i] > 'z') {
                message[i] = message[i] - 'z' + 'a' - 1;
            }
        }
        
        else if(message[i] >= 'A' && message[i] <= 'Z') {
                message[i] = message[i] + key;
        
            if(message[i] > 'Z') {
                message[i] = message[i] - 'Z' + 'A' - 1;
            }
        }
        printf("%c", message[i]);
    }
    printf("\n");
}

void rotationDecrypt(char* message, int key) {
    
    int i;
    
    for(i = 0; message[i] != '\0'; ++i) {
		
		if(message[i] >= 'a' && message[i] <= 'z') {
			message[i] = (message[i] - key) % 26 - 32; //Decrypt input message & convert any lower case characters to uppercase
			
			if(message[i] < 'a') {
				message[i] = message[i] + 'z' - 'a' + 1;
			}
		}
		
		else if(message[i] >= 'A' && message[i] <= 'Z') {
			message[i] = (message[i] - key) % 26;
			
			if(message[i] < 'A') {
				message[i] = message[i] + 'Z' - 'A' + 1;
			}
		}
		printf("%c", message[i]);
	}
    printf("\n");
}

void bruteRotation(char* message, int key) {
    
    int i;
    
    for(i = 0; message[i] != '\0'; ++i) {
        
        if(message[i] >= 'a' && message[i] <= 'z') {
			message[i] = (message[i] - key) % 26 - 32; //Decrypt input message & convert any lower case characters to uppercase
			
			if(message[i] < 'a') {
				message[i] = message[i] + 'z' - 'a' + 1;
			}
		}
		
		else if(message[i] >= 'A' && message[i] <= 'Z') {
			message[i] = (message[i] - key) % 26;
			
			if(message[i] < 'A') {
				message[i] = message[i] + 'Z' - 'A' + 1;
			}
		}
    }
    printf("\nAll possible decryption keys processed.\n");
}