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
//Define substitution index function.
int f_index(char subkey[], char to_find);
//Define substitution encryption function.
char* substitutionEncrypt(char* message, char subkey[]);
//Define substitution decryption function.
char* substitutionDecrypt(char* message, char subkey[]);


//----------------- User Friendly menu & Task selection -----------------
int main() {
    
    int operation, key; //declared integers for operation
    char message[255]; //This is the array which holds the user's message to be used in the Cipher.
    //Alphabet -------- A    B    C    D    E    F    G    H    I    J    K    L    M    N    O    P    Q    R    S    T    U    V    W    X    Y    Z
    //Declaration of substitution key within its index.
    char subkey[26] = {'Z', 'A', 'Q', 'W', 'S', 'X', 'C', 'D', 'E', 'R', 'F', 'V', 'B', 'G', 'T', 'Y', 'H', 'N', 'M', 'J', 'U', 'I', 'K', 'L', 'O', 'P'};
    
    
    printf("Please enter a string:\t"); //Ask the user for the message they wish to use.
    fgets(message, sizeof(message), stdin); //Gets the user's text input and stores it in the message variable.
    
    printf("\nPlease choose from the following options:\n");
    printf("1 = Encrypt with the Rotation Cipher.\n");
    printf("2 = Decrypt with the Rotation Cipher.\n");
    printf("3 = Encrypt with the Substitution Cipher.\n");
    printf("4 = Decrypt with the Substitution Cipher.\n");
    printf("\n5 = Use brute force Rotation Decryption.\n");
    printf("\nEnter a number to make your selection:\t");
    scanf("%d", &operation);
    fflush(stdin);
    
    
    //using switch case statesments to order the selction of operations / performable tasks..
    switch(operation) {
        case 1: // Encryption with Rotation cipher
            fflush(stdin);
            printf("\nEncryption with Rotation Cipher selected.\n");
            printf("Enter the Rotation Cipher Key (between 0-25):\t");
            scanf("%d", &key); 
            //Print the encyrpted text
            printf("\nEncrypted message: ");
            
            rotationEncrypt(message, key);
            break;
            
        case 2: // Decryption with Rotation cipher
            fflush(stdin);
            printf("\nDecryption with Rotation Cipher selected.\n");
            printf("Enter the Rotation Cipher Key (between 0-25):\t");
            scanf("%d", &key);
            //print the decrypted text
            printf("\nDecrypted message: ");
            
            rotationDecrypt(message, key);
            break;
            
        case 3: //Encryption with Substitution cipher
            printf("\nEncryption with Substitution Cipher selected.\n");
            char *esub = substitutionEncrypt(message, subkey);
            printf("Encrypted message: %s\n", esub);
            break;
            
        case 4: //Decryption with Substitution cipher
            printf("\nDecryption with Substitution Cipher selected.\n");
            char *dsub = substitutionDecrypt(message, subkey);
            printf("Decrypted Message: %s\n", dsub);
            break;
            
        case 5:  // Brute force rotation decryption
            printf("\nBrute force Decryption selected.\n");
                bruteRotation(message, key);
            break;
            
        default:
            printf("\nError incorrectly entered inputs.\n");
    }

}

void rotationEncrypt(char* message, int key) {
    
    int i; //integer variable to reference each character
    
    for(i = 0; message[i] != '\0'; ++i) {
        message[i] = message[i];
        
        if(message[i] >= 'a' && message[i] <= 'z') { //Check that the given message is inbetween 'a' or 'z'
                message[i] = toupper(message[i]) + key; //Encrypt input message & convert any lower case characters to uppercase.
            
            if(message[i] > 'Z') { // Subtract 
                message[i] = message[i] - 'Z' + 'A' - 1;
            }
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') { //Check that the given message is inbetween 'A' or 'Z'
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
    		message[i] = toupper(message[i]) - key; //Decrypt input message & convert any lower case characters to uppercase
    			
    		if(message[i] < 'A') {
    			message[i] = message[i] + 'Z' - 'A' + 1;
    		}
    	}	
    	else if(message[i] >= 'A' && message[i] <= 'Z') {
    		message[i] = message[i] - key;
    			
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
    
    for(key = 0; key <= 25; key++) {
        for(i = 0; i < strlen(message); ++i) {
    		
    		if(message[i] >= 'a' && message[i] <= 'z') {
    			message[i] = toupper(message[i]) - key; //Decrypt input message & convert any lower case characters to uppercase
    			
    			if(message[i] < 'A') {
    				message[i] = message[i] + 'Z' - 'A' + 1;
    			}
    		}
    		else if(message[i] >= 'A' && message[i] <= 'Z') {
    			message[i] = message[i] - key;
    			
    			if(message[i] < 'A') {
    				message[i] = message[i] + 'Z' - 'A' + 1;
    			}
    		}
    	}
    	printf("Key: %d Decrypted Message: %s", key, message);
    }
}

int f_index(char subkey[], char to_find) {
    
    int i;
    
    for(i = 0; i < 26; i++) {
        if(subkey[i] == to_find) {
            return i;
        }
    }
    return -1;
}

char* substitutionEncrypt(char* message, char subkey[]) {
    
    int i;
    int length = strlen(message);
    int e_index;
    char *esub = (char *) malloc(sizeof(char)*length);
    
    for(i = 0; i < length; i++) {
        e_index = toupper(message[i]) - 'A';
        
        if (e_index >= 0 && e_index < 26) {
            esub[i] = subkey[e_index];
        }
        else {
            esub[i] = message[i];
        }
    }
    return esub;
}

char* substitutionDecrypt(char* message, char subkey[]) {
    
    int i;
    int length = strlen(message);
    int d_index;
    int subkey_index;
    char *dsub = (char *) malloc(sizeof(char)*length);
    
    for(i = 0; i < length; i++) {
        d_index = toupper(message[i]) - 'A';
        
        if(d_index >= 0 && d_index < 26) {
            subkey_index = f_index(subkey, toupper(message[i]));
            dsub[i] = 'A' + subkey_index;
        }
        else {
            dsub[i] = message[i];
        }
    }
    return dsub;
}